// A primitive pre-historic shell
#include "../library/standard.c"

#define MAX_INPUT 1024
#define MAX_ARGS 64

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
        u8 ADDRESS_TO name;
        CommandFunc func;
} Command;

u8 ADDRESS_TO command_buffer[MAX_INPUT] = {0};

fn exec_command(u8 ADDRESS_TO args)
{
        u32 pid = system_call(syscall_fork);

        if (pid == 0)
                return;

        u32 argc = 0;
        u8 ADDRESS_TO arg = args;

        while (arg)
        {
                if (arg == ' ')
                        argc++;
                arg++;
        }

        system_call_2(syscall_execve, (positive)args[0], (positive)args);
        system_call_1(syscall_exit, 0);
}

fn cmd_echo()
{
        print("echo\n");
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
    {"exit", cmd_exit},
    {"clear", cmd_clear},
    {NULL, NULL}};

fn extract_command_name(u8 ADDRESS_TO dest, u8 ADDRESS_TO src)
{
        while (ADDRESS_TO src && ADDRESS_TO src != ' ')
        {
                ADDRESS_TO dest++ = ADDRESS_TO src++;
        }
        ADDRESS_TO dest = '\0';
}

bipolar process_command()
{
        u8 command_name[MAX_INPUT] = {0};
        extract_command_name(command_name, command_buffer);

        Command ADDRESS_TO cmd = commands;
        while (cmd->name)
        {
                if (strcmp(cmd->name, command_name) == 0)
                {
                        cmd->func();
                        return 0;
                }
                cmd++;
        }

        if (command_buffer[0] == '.' || command_buffer[0] == '/')
        {
                exec_command(command_buffer);
                return 0;
        }

        print("Command not found: ");
        print(command_name);

        return 0;
}

i32 main()
{
        system_call_2(2, (positive) "/dev/console", O_RDWR | O_NOCTTY);

        while (1)
        {
                print(RESET PROMPT);

                system_call_3(syscall_read, 0, (positive)command_buffer, MAX_INPUT);

                process_command();
        }
}