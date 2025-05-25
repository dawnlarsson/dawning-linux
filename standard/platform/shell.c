#include "../library.c"

const positive page_size = 4096;

bool dawn_shell_styles = true;

fn dawn_shell_basename(writer write, string_address input)
{
        if (input == null)
                return write(str("basename: missing operand\n"));

        path_basename(write, input);

        write(str("\n"));
}

fn dawn_shell_cat(writer write, string_address input)
{
        if (input == null)
                return write(str("cat: missing operand\n"));

        bipolar file_descriptor = system_call_3(syscall(openat), AT_FDCWD, (positive)input, FILE_READ);

        if (file_descriptor < 0)
                return string_format(write, "cat: Cannot open file: %s\n", input);

        p8 buffer[page_size];

        while (1)
        {
                bipolar bytes_read = system_call_3(syscall(read), file_descriptor, (positive)buffer, page_size);

                if (bytes_read <= 0)
                        break;

                write(buffer, bytes_read);
        }

        system_call_1(syscall(close), file_descriptor);
}

// TODOs:
// - empty buffer should go to home directory & handle ~
// - "cd -" aka cd $OLDPWD
fn dawn_shell_cd(writer write, string_address input)
{
        if (input == null)
                input = "/";

        if (!system_call_1(syscall(chdir), (positive)input))
                return;

        string_format(write, "cd: No such directory: %s\n", input);
}

fn dawn_shell_clear(writer write, string_address input)
{
        write(str(TERM_CLEAR_SCREEN));
}

fn dawn_shell_chmod(writer write, string_address input)
{
        if (input == null)
                return write(str("chmod: missing operand\n"));

        if (!system_call_3(syscall(fchmodat), AT_FDCWD, (positive)input, 0777))
                return;

        string_format(write, "chmod: Cannot change permissions: %s\n", input);
}

fn dawn_shell_cp(writer write, string_address input)
{
        if (input == null)
                return write(str("cp: missing operand\n"));

        string_address destination = string_cut(input, ' ');

        bipolar source_file = system_call_3(syscall(openat), AT_FDCWD, (positive)input, FILE_READ);

        if (source_file < 0)
                return string_format(write, "cp: Cannot open source file: %s\n", input);

        bipolar dest_file = system_call_4(syscall(openat), AT_FDCWD, (positive)destination,
                                          FILE_CREATE | FILE_WRITE | O_TRUNC, 0666);

        if (dest_file < 0)
        {
                system_call_1(syscall(close), source_file);
                return string_format(write, "cp: Cannot create destination file: %s\n", destination);
        }

        p8 buffer[page_size];

        while (1)
        {
                bipolar bytes_read = system_call_3(syscall(read), source_file, (positive)buffer, page_size);

                if (bytes_read <= 0)
                        break;

                system_call_3(syscall(write), dest_file, (positive)buffer, bytes_read);
        }

        system_call_1(syscall(close), source_file);
        system_call_1(syscall(close), dest_file);
}

fn dawn_shell_echo(writer write, string_address input)
{
        if (input != null)
                write(input, 0);

        write(str("\n"));
}

fn dawn_shell_exec(writer write, string_address input)
{
        p8 address_to argv[] = {input};

        system_call_2(syscall(execve), (positive)input, (positive)argv);
}

// - Blue: Directories
// - Cyan: Symbolic links
// - Default: Regular files
// - Yellow: Special files (FIFO, sockets, devices, etc.)
fn dawn_shell_ls(writer write, string_address input)
{
        const p32 max_line_entries = 8;

        if (input == null)
                input = ".";

        bipolar file_descriptor = system_call_3(syscall(openat), AT_FDCWD, (positive)input, FILE_READ | O_DIRECTORY);

        if (file_descriptor < 0)
                return string_format(write, "ls: Cannot access '%s': No such file or directory\n", input);

        p8 out_buffer[page_size];

        positive entries_count = 0;

        while (1)
        {
                bipolar bytes_read = system_call_3(syscall(getdents64), file_descriptor, (positive)out_buffer, page_size);

                if (bytes_read <= 0)
                        break;

                p8 address_to step = out_buffer;

                while (step < out_buffer + bytes_read)
                {
                        struct linux_dirent64 address_to entry = (struct linux_dirent64 address_to)step;

                        if (entry->d_name[0] == '.' && (entry->d_name[1] == end ||
                                                        (entry->d_name[1] == '.' && entry->d_name[2] == end)))
                        {
                                step += entry->d_reclen;
                                continue;
                        }

                        if (dawn_shell_styles)
                        {
                                if (entry->d_type == DT_DIR)
                                        write(str(TERM_BOLD TERM_BLUE));
                                else if (entry->d_type == DT_LNK)
                                        write(str(TERM_CYAN));
                                else if (entry->d_type == DT_REG)
                                        write(str(TERM_RESET));
                                else
                                        write(str(TERM_YELLOW));
                        }

                        string_format(write, "%s ", entry->d_name);

                        if (dawn_shell_styles)
                                write(str(TERM_RESET));

                        entries_count++;

                        if (entries_count % max_line_entries == 0)
                                write(str("\n"));

                        step += entry->d_reclen;
                }
        }

        if (entries_count % max_line_entries != 0)
                write(str("\n"));

        system_call_1(syscall(close), file_descriptor);
}

fn dawn_shell_mkdir(writer write, string_address input)
{
        if (input == null)
                return write(str("mkdir: missing operand\n"));

        if (!system_call_3(syscall(mkdirat), AT_FDCWD, (positive)input, 0777))
                return;

        string_format(write, "mkdir: Cannot create directory: %s\n", input);
}

fn dawn_shell_mv(writer write, string_address input)
{
        if (input == null)
                return write(str("mv: missing operand\n"));

        string_address destination = string_cut(input, ' ');

        if (destination == null)
                return write(str("mv: missing destination\n"));

        if (!system_call_4(syscall(renameat), AT_FDCWD, (positive)input, AT_FDCWD, (positive)destination))
                return;

        string_format(write, "mv: Cannot move file: %s\n", input);
}

fn dawn_shell_mount(writer write, string_address input)
{
        if (input == null)
                return write(str("mount: missing operand\n"));

        string_address destination = string_cut(input, ' ');

        if (destination == null)
                return write(str("mount: missing destination\n"));

        if (!system_call_4(syscall(mount), (positive)input, (positive)destination, (positive)input, MS_BIND))
                return;

        string_format(write, "mount: Cannot mount filesystem: %s\n", input);
}

fn dawn_shell_pwd(writer write, string_address input)
{
        p8 out_buffer[4096];

        system_call_2(syscall(getcwd), (positive)out_buffer, 4096);

        string_format(write, "%s\n", out_buffer);
}

fn dawn_shell_exit(writer write, string_address input)
{
        bipolar exit_code = 0;

        if (input != null)
                exit_code = string_to_bipolar(input);

        exit(exit_code);
}

fn dawn_shell_touch(writer write, string_address input)
{
        if (input == null)
                return write(str("touch: missing operand\n"));

        bipolar file_descriptor = system_call_4(syscall(openat), AT_FDCWD, (positive)input, FILE_CREATE | FILE_WRITE | O_TRUNC, 0666);

        if (file_descriptor < 0)
                return string_format(write, "touch: Cannot create file: %s\n", input);

        system_call_1(syscall(close), file_descriptor);
}

fn dawn_shell_help(writer write, string_address input);

typedef fn(address_to dawn_shell_command_function)(writer write, string_address input);

typedef struct
{
        string_address name;
        dawn_shell_command_function function;
} dawn_shell_command;

dawn_shell_command dawn_shell_commands[] = {
    {"basename", dawn_shell_basename},
    {"cat", dawn_shell_cat},
    {"cd", dawn_shell_cd},
    {"clear", dawn_shell_clear},
    {"cp", dawn_shell_cp},
    {"chmod", dawn_shell_chmod},
    {"echo", dawn_shell_echo},
    {"exec", dawn_shell_exec},
    {"exit", dawn_shell_exit},
    {"ls", dawn_shell_ls},
    {"mkdir", dawn_shell_mkdir},
    {"mv", dawn_shell_mv},
    {"mount", dawn_shell_mount},
    {"pwd", dawn_shell_pwd},
    {"touch", dawn_shell_touch},
    {"help", dawn_shell_help},
    {null, null},
};

fn dawn_shell_help(writer write, string_address input)
{
        string_format(write, "Dawning Shell, WIP, " TERM_RED TERM_BOLD "expect crashes! \n\n" TERM_RESET "Available built-in commands:\n");

        dawn_shell_command address_to command = dawn_shell_commands;

        while (command->name)
        {
                string_format(write, TERM_BOLD " -  %s" TERM_RESET "\n", command->name);
                command++;
        }

        write(str("\n"));
}