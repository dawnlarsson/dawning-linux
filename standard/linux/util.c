#include "../linux.c"

// kernel page is normaly 4096 bytes
const positive page_size = 4096;

fn core_basename(writer write, string_address input)
{
        if (input == NULL)
                return write(str("basename: missing operand\n"));

        path_basename(write, input);

        write(str("\n"));
}

fn core_cat(writer write, string_address input)
{
        if (input == NULL)
                return write(str("cat: missing operand\n"));

        bipolar file_descriptor = system_call_2(syscall_open, (positive)input, O_RDONLY);
        if (file_descriptor < 0)
        {
                write(str("cat: Cannot open file: "));
                write(input, 0);
                write(str("\n"));
                return;
        }

        p8 buffer[page_size];

        while (1)
        {
                bipolar bytes_read = system_call_3(syscall_read, file_descriptor, (positive)buffer, page_size);

                if (bytes_read <= 0)
                        break;

                write(buffer, bytes_read);
        }

        system_call_1(syscall_close, file_descriptor);
}

// TODOs:
// - empty buffer should go to home directory & handle ~
// - "cd -" aka cd $OLDPWD
fn core_cd(writer write, string_address buffer)
{
        if (buffer == NULL)
                buffer = "/";

        if (!system_call_1(syscall_chdir, (positive)buffer))
                return;

        write(str("cd: No such directory: "));
        write(buffer, 0);
        write(str("\n"));
}

fn core_clear(writer write, string_address buffer)
{
        write(TERM_CLEAR_SCREEN, sizeof(TERM_CLEAR_SCREEN));
}

fn core_chmod(writer write, string_address buffer)
{
        if (buffer == NULL)
                return write(str("chmod: missing operand\n"));

        if (!system_call_2(syscall_chmod, (positive)buffer, 0777))
                return;

        write(str("chmod: Cannot change permissions: "));
        write(buffer, 0);
        write(str("\n"));
}

fn core_cp(writer write, string_address buffer)
{
        if (buffer == NULL)
                return write(str("cp: missing operand\n"));

        string_address source = buffer;
        string_address destination = string_first_of(buffer, ' ');

        if (destination == NULL)
                return write(str("cp: missing destination\n"));

        ADDRESS_TO destination = '\0';
        destination++;

        bipolar source_fd = system_call_2(syscall_open, (positive)source, O_RDONLY);
        if (source_fd < 0)
        {
                write(str("cp: Cannot open source file: "));
                write(source, 0);
                write(str("\n"));
                return;
        }

        bipolar destination_fd = system_call_2(syscall_open, (positive)destination, O_CREAT | O_WRONLY);
        if (destination_fd < 0)
        {
                write(str("cp: Cannot open destination file: "));
                write(destination, 0);
                write(str("\n"));
                return;
        }

        p8 out_buffer[page_size];

        while (1)
        {
                bipolar bytes_read = system_call_3(syscall_read, source_fd, (positive)out_buffer, page_size);

                if (bytes_read <= 0)
                        break;

                system_call_3(syscall_write, destination_fd, (positive)out_buffer, bytes_read);
        }

        system_call_1(syscall_close, source_fd);
        system_call_1(syscall_close, destination_fd);
}

fn core_echo(writer write, string_address buffer)
{
        if (buffer != NULL)
                write(buffer, 0);

        write(str("\n"));
}

fn core_exec(writer write, string_address buffer)
{
        p8 ADDRESS_TO argv[] = {buffer};

        system_call_2(syscall_execve, (positive)buffer, (positive)argv);
}

// - Blue: Directories
// - Cyan: Symbolic links
// - Default: Regular files
// - Yellow: Special files (FIFO, sockets, devices, etc.)
fn core_ls(writer write, string_address buffer)
{
        const p32 max_line_entries = 8;

        if (buffer == NULL)
                buffer = ".";

        bipolar file_descriptor = system_call_2(syscall_open, (positive)buffer, O_RDONLY | O_DIRECTORY);

        if (file_descriptor < 0)
        {
                write(str("ls: Cannot access '"));
                write(buffer, 0);
                write(str("': No such file or directory\n"));
                return;
        }

        p8 out_buffer[page_size];

        positive entries_count = 0;

        while (1)
        {
                bipolar bytes_read = system_call_3(syscall_getdents64, file_descriptor, (positive)out_buffer, page_size);

                if (bytes_read <= 0)
                        break;

                p8 ADDRESS_TO step = out_buffer;

                while (step < out_buffer + bytes_read)
                {
                        struct linux_dirent64 ADDRESS_TO entry = (struct linux_dirent64 ADDRESS_TO)step;

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

                        write(entry->d_name, 0);

                        write(str(TERM_RESET " "));
                        entries_count++;

                        if (entries_count % max_line_entries == 0)
                                write(str("\n"));

                        step += entry->d_reclen;
                }
        }

        if (entries_count % max_line_entries != 0)
                write(str("\n"));

        system_call_1(syscall_close, file_descriptor);
}

fn core_pwd(writer write, string_address buffer)
{
        p8 out_buffer[4096] = {0};
        system_call_2(syscall_getcwd, (positive)out_buffer, 4096);
        write(out_buffer, 0);
        write(str("\n"));
}

fn core_mkdir(writer write, string_address buffer)
{
        if (buffer == NULL)
                return write(str("mkdir: missing operand\n"));

        if (!system_call_2(syscall_mkdir, (positive)buffer, 0777))
                return;

        write(str("mkdir: Cannot create directory: "));
        write(buffer, 0);
        write(str("\n"));
}

fn core_mv(writer write, string_address buffer)
{
        if (buffer == NULL)
                return write(str("mv: missing operand\n"));

        string_address source = buffer;
        string_address destination = string_first_of(buffer, ' ');

        if (destination == NULL)
                return write(str("mv: missing destination\n"));

        ADDRESS_TO destination = '\0';
        destination++;

        if (!system_call_2(syscall_rename, (positive)source, (positive)destination))
                return;

        write(str("mv: Cannot move file: "));
        write(source, 0);
        write(str("\n"));
}

fn core_mount(writer write, string_address buffer)
{
        if (buffer == NULL)
                return write(str("mount: missing operand\n"));

        string_address source = buffer;
        string_address destination = string_first_of(buffer, ' ');

        if (destination == NULL)
                return write(str("mount: missing destination\n"));

        ADDRESS_TO destination = '\0';
        destination++;

        if (!system_call_5(syscall_mount, (positive)source, (positive)destination, (positive)source, MS_BIND, NULL))
                return;

        write(str("mount: Cannot mount filesystem: "));
        write(source, 0);
        write(str("\n"));
}

fn core_exit(writer write, string_address buffer)
{
        exit(0);
}

fn core_help(writer write, string_address buffer);

typedef fn(ADDRESS_TO core_command_function)(writer write, string_address buffer);

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
    {NULL, NULL},
};

fn core_help(writer write, string_address buffer)
{
        write(str("Dawning Shell, WIP, " TERM_RED TERM_BOLD "expect crashes! \n\n" TERM_RESET));
        write(str("Available built-in commands:\n"));

        core_command ADDRESS_TO command = core_commands;

        while (command->name)
        {
                write(str(" - " TERM_BOLD));
                write(command->name, 0);
                write(str(TERM_RESET "\n"));

                command++;
        }

        write(str("\n"));
}