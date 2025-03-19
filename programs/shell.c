// A primitive pre-historic shell,
// it lobs rocks at the kernel and says ouga boga at the user.
#include "../library/standard.c"

#define MAX_INPUT 1024
#define MAX_ARGS 64

p8 command_buffer[MAX_INPUT];

#define O_RDONLY 00
#define O_WRONLY 01
#define O_RDWR 02
#define O_DIRECTORY 02
#define O_NOCTTY 0400
#define O_NONBLOCK 0
#define SIGTRAP 5
#define SIGKILL 9
#define SIGSTOP 20

#define CLEAR_SCREEN "\033[2J\033[H"
#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"
#define RESET "\033[0m"
#define PROMPT " $ "

typedef fn(ADDRESS_TO CommandFunc)();

typedef struct
{
        string_address name;
        CommandFunc func;
} Command;

fn exec_command(string_address args)
{
        p32 pid = system_call(syscall_fork);

        if (pid == 0)
        {
                system_call_2(syscall_execve, (positive)args, (positive)args);
                system_call_1(syscall_exit, 0);
        }

        system_call_1(syscall_wait4, pid);
}

fn cmd_echo()
{
        string_address args = strchr(command_buffer, ' ');
        print(args ? args + 1 : "");
        print("\n");
}

fn cmd_pwd()
{
        p8 buffer[MAX_INPUT] = {0};
        system_call_2(syscall_getcwd, (positive)buffer, MAX_INPUT);
        print(buffer);
        print("\n");
}

fn cmd_cd()
{
        string_address args = strchr(command_buffer, ' ');
        string_address path = args ? args + 1 : "/";

        if (system_call_1(syscall_chdir, (positive)path) != 0)
        {
                print("cd: No such directory: ");
                print(path);
                print("\n");
        }
}

#define DT_DIR 4
#define DT_REG 8
#define DT_LNK 10
#define O_DIRECTORY 0200000

struct linux_dirent64
{
        p64 d_ino;
        p64 d_off;
        p16 d_reclen;
        p8 d_type;
        b8 d_name[];
};

fn cmd_ls()
{
        string_address path = ".";
        string_address args = strchr(command_buffer, ' ');

        if (args && string_get(args + 1) != '\0')
        {
                path = args + 1;
        }

        bipolar fd = system_call_2(syscall_open, (positive)path, O_RDONLY | O_DIRECTORY);

        if (fd < 0)
        {
                print("ls: Cannot access '");
                print(path);
                print("': No such file or directory\n");
                return;
        }

        p8 buffer[1024];
        positive entries_count = 0;

        while (1)
        {
                bipolar nread = system_call_3(syscall_getdents64, fd, (positive)buffer, 1024);
                if (nread <= 0)
                        break;

                p8 ADDRESS_TO bpos = buffer;
                while (bpos < buffer + nread)
                {
                        struct linux_dirent64 ADDRESS_TO d = (struct linux_dirent64 ADDRESS_TO)bpos;

                        if (!(d->d_name[0] == '.' && (d->d_name[1] == '\0' ||
                                                      (d->d_name[1] == '.' && d->d_name[2] == '\0'))))
                        {
                                if (d->d_type == DT_DIR)
                                {
                                        print("\033[1;34m");
                                }
                                else if (d->d_type == DT_LNK)
                                {
                                        print("\033[1;36m");
                                }

                                print(d->d_name);
                                print("\033[0m  ");

                                entries_count++;
                                if (entries_count % 5 == 0)
                                        print("\n");
                        }

                        bpos += d->d_reclen;
                }
        }

        if (entries_count % 5 != 0)
                print("\n");

        system_call_1(syscall_close, fd);
}

fn cmd_exit()
{
        system_call_1(syscall_exit, 0);
}

fn cmd_clear()
{
        print(CLEAR_SCREEN);
}

Command commands[] = {
    {"echo", cmd_echo},
    {"pwd", cmd_pwd},
    {"cd", cmd_cd},
    {"ls", cmd_ls},
    {"exit", cmd_exit},
    {"clear", cmd_clear},
    {NULL, NULL},
};

fn extract_command_name(string_address dest, string_address source)
{
        while (string_get(source) && string_is(source, ' '))
                source++;

        while (string_get(source) && !string_is(source, ' ') && !string_is(source, '\n'))
        {
                string_set(dest, string_get(source));
                dest++;
                source++;
        }

        string_set(dest, '\0');
}

fn trim_newline(string_address soruce)
{
        string_address step = soruce;

        while (string_get(step))
                step++;

        if (step > soruce)
                step--;

        if (string_is(step, '\n'))
                string_set(step, '\0');
}

bipolar process_command()
{
        if (!string_get(command_buffer) || string_is(command_buffer, '\n'))
                return 0;

        trim_newline(command_buffer);

        p8 name[MAX_INPUT] = {0};
        extract_command_name(name, command_buffer);

        if (!string_get(name))
                return 0;

        Command ADDRESS_TO cmd = commands;
        while (cmd->name)
        {
                if (strcmp(cmd->name, name) == 0)
                {
                        cmd->func();
                        return 0;
                }
                cmd++;
        }

        if (string_index(command_buffer, 0) == '.' || string_index(command_buffer, 0) == '/')
        {
                exec_command(command_buffer);
                return 0;
        }

        print("Command not found: ");
        print(name);
        print("\n");

        return 0;
}

b32 main()
{
        memset(command_buffer, 0, MAX_INPUT);

        system_call_2(2, (positive) "/dev/console", O_RDWR | O_NOCTTY);

        while (1)
        {
                print(RESET PROMPT);

                p32 bytes_read = system_call_3(syscall_read, 0, (positive)command_buffer, MAX_INPUT);

                if (bytes_read > 0 && bytes_read < MAX_INPUT)
                        command_buffer[bytes_read] = '\0';

                process_command();

                memset(command_buffer, 0, MAX_INPUT);
        }
}