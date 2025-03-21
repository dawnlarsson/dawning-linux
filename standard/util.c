#include "../standard/linux.c"

#define MAX_INPUT 1024
#define MAX_ARGS 64

fn core_echo(string_address buffer)
{
        if (buffer != NULL)
                print(buffer);

        print("\n");
}

fn core_pwd(string_address buffer)
{
        p8 out_buffer[MAX_INPUT] = {0};
        system_call_2(syscall_getcwd, (positive)out_buffer, MAX_INPUT);
        print(out_buffer);
        print("\n");
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

fn core_exit(string_address buffer)
{
        exit(0);
}

fn core_clear(string_address buffer)
{
        print(TERM_CLEAR_SCREEN);
}

typedef fn(ADDRESS_TO core_command_function)(string_address buffer);

typedef struct
{
        string_address name;
        core_command_function function;
} core_command;

core_command core_commands[] = {
    {"basename", core_basename},
    {"cd", core_cd},
    {"clear", core_clear},
    {"echo", core_echo},
    {"exit", core_exit},
    {"ls", core_ls},
    {"mkdir", core_mkdir},
    {"pwd", core_pwd},
    {NULL, NULL},
};
