#include "../standard/linux.c"

#define MAX_INPUT 1024
#define MAX_ARGS 64

fn core_basename(string_address buffer)
{
        if (buffer == NULL)
        {
                print("basename: missing operand\n");
                return;
        }

        string_address base = string_last_of(buffer, '/');

        print(base);
        print("\n");
}

fn core_cat(string_address buffer)
{
        if (buffer == NULL)
        {
                print("cat: missing operand\n");
                return;
        }

        bipolar file_descriptor = system_call_2(syscall_open, (positive)buffer, O_RDONLY);

        if (file_descriptor < 0)
        {
                print("cat: Cannot open file: ");
                print(buffer);
                print("\n");
                return;
        }

        p8 out_buffer[2048];
        while (1)
        {
                bipolar nread = system_call_3(syscall_read, file_descriptor, (positive)out_buffer, 2048);
                if (nread <= 0)
                        break;

                system_call_3(syscall_write, 1, (positive)out_buffer, nread);
        }

        system_call_1(syscall_close, file_descriptor);
}

fn core_cd(string_address buffer)
{
        if (buffer == NULL)
        {
                buffer = "/";
        }

        if (system_call_1(syscall_chdir, (positive)buffer) != 0)
        {
                print("cd: No such directory: ");
                print(buffer);
                print("\n");
        }
}

fn core_clear(string_address buffer)
{
        print(TERM_CLEAR_SCREEN);
}

fn core_chmod(string_address buffer)
{
        if (buffer == NULL)
        {
                print("chmod: missing operand\n");
                return;
        }

        if (system_call_2(syscall_chmod, (positive)buffer, 0777) != 0)
        {
                print("chmod: Cannot change permissions: ");
                print(buffer);
                print("\n");
        }
}

fn core_cp(string_address buffer)
{
        if (buffer == NULL)
        {
                print("cp: missing operand\n");
                return;
        }

        string_address source = buffer;
        string_address destination = strchr(buffer, ' ');

        if (destination == NULL)
        {
                print("cp: missing destination\n");
                return;
        }

        ADDRESS_TO destination = '\0';
        destination++;

        bipolar source_fd = system_call_2(syscall_open, (positive)source, O_RDONLY);
        if (source_fd < 0)
        {
                print("cp: Cannot open source file: ");
                print(source);
                print("\n");
                return;
        }

        bipolar destination_fd = system_call_2(syscall_open, (positive)destination, O_CREAT | O_WRONLY);
        if (destination_fd < 0)
        {
                print("cp: Cannot open destination file: ");
                print(destination);
                print("\n");
                return;
        }

        p8 out_buffer[1024];
        while (1)
        {
                bipolar nread = system_call_3(syscall_read, source_fd, (positive)out_buffer, 1024);
                if (nread <= 0)
                        break;

                system_call_3(syscall_write, destination_fd, (positive)out_buffer, nread);
        }

        system_call_1(syscall_close, source_fd);
        system_call_1(syscall_close, destination_fd);
}

fn core_echo(string_address buffer)
{
        if (buffer != NULL)
                print(buffer);

        print("\n");
}

fn core_exec(string_address buffer)
{
        p8 ADDRESS_TO argv[] = {buffer};

        bipolar result = system_call_2(syscall_execve, (positive)buffer, (positive)argv);
}

fn core_ls(string_address buffer)
{
        const p32 max_line_entries = 8;

        if (buffer == NULL)
        {
                buffer = ".";
        }

        bipolar file_descriptor = system_call_2(syscall_open, (positive)buffer, O_RDONLY | O_DIRECTORY);

        if (file_descriptor < 0)
        {
                print("ls: Cannot access '");
                print(buffer);
                print("': No such file or directory\n");
                return;
        }

        p8 out_buffer[MAX_INPUT];
        positive entries_count = 0;

        while (1)
        {
                bipolar nread = system_call_3(syscall_getdents64, file_descriptor, (positive)out_buffer, MAX_INPUT);
                if (nread <= 0)
                        break;

                p8 ADDRESS_TO bpos = out_buffer;
                while (bpos < out_buffer + nread)
                {
                        struct linux_dirent64 ADDRESS_TO d = (struct linux_dirent64 ADDRESS_TO)bpos;

                        if (!(d->d_name[0] == '.' && (d->d_name[1] == '\0' ||
                                                      (d->d_name[1] == '.' && d->d_name[2] == '\0'))))
                        {
                                if (d->d_type == DT_DIR)
                                {
                                        print(TERM_BOLD TERM_BLUE);
                                }
                                else if (d->d_type == DT_LNK)
                                {
                                        print(TERM_CYAN);
                                }
                                else if (d->d_type == DT_REG)
                                {
                                        print(TERM_RESET);
                                }
                                else
                                {
                                        print(TERM_YELLOW);
                                }

                                print(d->d_name);
                                print(TERM_RESET " ");

                                entries_count++;
                                if (entries_count % max_line_entries == 0)
                                        print("\n");
                        }

                        bpos += d->d_reclen;
                }
        }

        if (entries_count % max_line_entries != 0)
                print("\n");

        system_call_1(syscall_close, file_descriptor);
}

fn core_pwd(string_address buffer)
{
        p8 out_buffer[MAX_INPUT] = {0};
        system_call_2(syscall_getcwd, (positive)out_buffer, MAX_INPUT);
        print(out_buffer);
        print("\n");
}

fn core_mkdir(string_address buffer)
{
        if (buffer == NULL)
        {
                print("mkdir: missing operand\n");
                return;
        }

        if (system_call_2(syscall_mkdir, (positive)buffer, 0777) != 0)
        {
                print("mkdir: Cannot create directory: ");
                print(buffer);
                print("\n");
        }
}

fn core_mv(string_address buffer)
{
        if (buffer == NULL)
        {
                print("mv: missing operand\n");
                return;
        }

        string_address source = buffer;
        string_address destination = strchr(buffer, ' ');

        if (destination == NULL)
        {
                print("mv: missing destination\n");
                return;
        }

        ADDRESS_TO destination = '\0';
        destination++;

        if (system_call_2(syscall_rename, (positive)source, (positive)destination) != 0)
        {
                print("mv: Cannot move file: ");
                print(source);
                print("\n");
        }
}

fn core_exit(string_address buffer)
{
        exit(0);
}

fn core_help();

typedef fn(ADDRESS_TO core_command_function)(string_address buffer);

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
    {"pwd", core_pwd},
    {"help", core_help},
    {NULL, NULL},
};

fn core_help(string_address buffer)
{
        print("Dawning Shell, WIP, " TERM_RED TERM_BOLD "expect crashes! \n\n" TERM_RESET);
        print("Available built-in commands:\n");

        core_command ADDRESS_TO command = core_commands;

        while (command->name)
        {
                print(" - " TERM_BOLD);
                print(command->name);
                print(TERM_RESET "\n");

                command++;
        }

        print("\n");
}