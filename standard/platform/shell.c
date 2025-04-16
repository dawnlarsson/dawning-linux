#include "../library.c"

// kernel page is normaly 4096 bytes
const positive page_size = 4096;

fn core_basename(writer write, string_address input)
{
        if (input == null)
                return write(str("basename: missing operand\n"));

        path_basename(write, input);

        write(str("\n"));
}

fn core_cat(writer write, string_address input)
{
        if (input == null)
                return write(str("cat: missing operand\n"));

        bipolar file_descriptor = system_call_3(syscall(openat), AT_FDCWD, (positive)input, O_RDONLY);

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
fn core_cd(writer write, string_address input)
{
        if (input == null)
                input = "/";

        if (!system_call_1(syscall(chdir), (positive)input))
                return;

        string_format(write, "cd: No such directory: %s\n", input);
}

fn core_clear(writer write, string_address input)
{
        write(str(TERM_CLEAR_SCREEN));
}

fn core_chmod(writer write, string_address input)
{
        if (input == null)
                return write(str("chmod: missing operand\n"));

        if (!system_call_3(syscall(fchmodat), AT_FDCWD, (positive)input, 0777))
                return;

        string_format(write, "chmod: Cannot change permissions: %s\n", input);
}

fn core_cp(writer write, string_address input)
{
        if (input == null)
                return write(str("cp: missing operand\n"));
        
        string_address source = input;
        string_address destination = string_cut(input, ' ');

        bipolar source_file_descriptor = system_call_3(syscall(openat), AT_FDCWD, (positive)input, O_RDONLY);

        if (source_file_descriptor < 0)
                return string_format(write, "cp: Cannot open file: %s\n", input);
                
        
        bipolar destination_fd = system_call_3(syscall(openat), AT_FDCWD, (positive)destination, O_CREAT | O_WRONLY);
        
        if (destination_fd < 0)
                return string_format(write, "cp: Cannot open source file: %s\n", source);
        

        p8 out_buffer[page_size];

        while (1)
        {
                bipolar bytes_read = system_call_3(syscall(read), source_file_descriptor, (positive)out_buffer, page_size);

                if (bytes_read <= 0)
                        break;

                system_call_3(syscall(write), destination_fd, (positive)out_buffer, bytes_read);
        }

        system_call_1(syscall(close), source_file_descriptor);
        system_call_1(syscall(close), destination_fd);

}

fn core_echo(writer write, string_address input)
{
        if (input != null)
                write(input, 0);

        write(str("\n"));
}

fn core_exec(writer write, string_address input)
{
        p8 address_to argv[] = {input};

        system_call_2(syscall(execve), (positive)input, (positive)argv);
}

// - Blue: Directories
// - Cyan: Symbolic links
// - Default: Regular files
// - Yellow: Special files (FIFO, sockets, devices, etc.)
fn core_ls(writer write, string_address input)
{
        const p32 max_line_entries = 8;

        if (input == null)
                input = ".";

        bipolar file_descriptor = system_call_3(syscall(openat), AT_FDCWD, (positive)input, O_RDONLY | O_DIRECTORY);

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

                        if (entry->d_name[0] == '.' && (entry->d_name[1] == '\0' ||
                                                        (entry->d_name[1] == '.' && entry->d_name[2] == '\0')))
                        {
                                step += entry->d_reclen;
                                continue;
                        }

                        if (entry->d_type == DT_DIR)
                                write(str(TERM_BOLD TERM_BLUE));
                        else if (entry->d_type == DT_LNK)
                                write(str(TERM_CYAN));
                        else if (entry->d_type == DT_REG)
                                write(str(TERM_RESET));
                        else
                                write(str(TERM_YELLOW));

                        string_format(write, "%s " TERM_RESET, entry->d_name);

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

fn core_pwd(writer write, string_address input)
{
        p8 out_buffer[4096];

        system_call_2(syscall(getcwd), (positive)out_buffer, 4096);

        string_format(write, "%s\n", out_buffer);
}

fn core_mkdir(writer write, string_address input)
{
        if (input == null)
                return write(str("mkdir: missing operand\n"));

        if (!system_call_3(syscall(mkdirat), AT_FDCWD, (positive)input, 0777))
                return;

        string_format(write, "mkdir: Cannot create directory: %s\n", input);
}

fn core_mv(writer write, string_address input)
{
        if (input == null)
                return write(str("mv: missing operand\n"));

        string_address source = input;
        string_address destination = string_cut(input, ' ');

        if (destination == null)
                return write(str("mv: missing destination\n"));

        if (!system_call_4(syscall(renameat), AT_FDCWD, (positive)source, AT_FDCWD, (positive)destination))
                return;

        string_format(write, "mv: Cannot move file: %s\n", source);
}

fn core_mount(writer write, string_address input)
{
        if (input == null)
                return write(str("mount: missing operand\n"));

        string_address source = input;
        string_address destination = string_cut(input, ' ');

        if (destination == null)
                return write(str("mount: missing destination\n"));

        if (!system_call_4(syscall(mount), (positive)source, (positive)destination, (positive)source, MS_BIND))
                return;

        string_format(write, "mount: Cannot mount filesystem: %s\n", source);
}

fn core_exit(writer write, string_address input)
{
        exit(0);
}

fn core_help(writer write, string_address input);

typedef fn(address_to core_command_function)(writer write, string_address input);

typedef struct
{
        string_address name;
        core_command_function function;
} core_command;

core_command core_commands[] = {
    {"basename", core_basename},
    {"cat", core_cat},
    {"cd", core_cd},
    {"clear", core_clear},
    {"cp", core_cp},
    {"chmod", core_chmod},
    {"echo", core_echo},
    {"exec", core_exec},
    {"exit", core_exit},
    {"ls", core_ls},
    {"mkdir", core_mkdir},
    {"mv", core_mv},
    {"mount", core_mount},
    {"pwd", core_pwd},
    {"help", core_help},
    {null, null},
};

fn core_help(writer write, string_address input)
{
        string_format(write, "Dawning Shell, WIP, " TERM_RED TERM_BOLD "expect crashes! \n\n" TERM_RESET "Available built-in commands:\n");

        core_command address_to command = core_commands;

        while (command->name)
        {
                string_format(write, TERM_BOLD " -  %s" TERM_RESET "\n", command->name);
                command++;
        }

        write(str("\n"));
}