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

fn exec_command(u8 ADDRESS_TO args)
{
        int pid = system_call(syscall_fork);

        if (pid == 0)
                return;

        system_call_2(syscall_execve, (positive)args[0], (positive)args);
        system_call_1(syscall_exit, 0);
}

bipolar parse_input(u8 ADDRESS_TO input, u8 ADDRESS_TO args)
{
        u8 ADDRESS_TO curr = input;

        positive count = 0;
        positive in_token = 0;

        args[0] = ADDRESS_TO curr;

        while (ADDRESS_TO curr)
        {
                if (ADDRESS_TO curr == ' ' || ADDRESS_TO curr == '\n')
                {
                        ADDRESS_TO curr = '\0';
                        in_token = 0;
                }
                else if (!in_token)
                {
                        args[count++] = ADDRESS_TO curr;
                        in_token = 1;
                        if (count >= 32 - 1)
                                break;
                }
                curr++;
        }

        args[count] = NULL;

        return count;
}

// Builtin command handlers - avoid process spawning for common operations
bipolar handle_builtin(u8 ADDRESS_TO args, positive arg_count)
{
        // Compare first char for quick rejection
        if (!args[0])
                return 0;

        if (str_compare(ADDRESS_OF args[0], "exit"))
        {
                system_call_1(syscall_exit, 0);
        }

        u8 ADDRESS_TO path = "/bin/";
        u8 ADDRESS_TO software = "/software/";

        u8 command_buffer[256] = {0};
        command_buffer[256] = '\0';

        str_copy(command_buffer, path);
        str_copy(command_buffer + str_length(path), ADDRESS_OF args[0]);

        u8 ADDRESS_TO argv[] = {"/bin/top"};
        system_call_3(syscall_execve, (bipolar) "/bin/top", (bipolar)argv, 0);

        print("Error not found");
        print(command_buffer);

        return 0;
}

fn input_clear(char ADDRESS_TO input_buffer)
{
        for (int i = 0; i < MAX_INPUT; i++)
        {
                input_buffer[i] = '\0';
        }
}

u32 main()
{
        system_call_2(2, (positive) "/dev/console", O_RDWR | O_NOCTTY);

        char input_buffer[MAX_INPUT];
        char ADDRESS_TO args[MAX_ARGS];

        // input_clear(input_buffer);

        while (1)
        {
                system_call_3(syscall_write, 1, (positive)PROMPT, sizeof(PROMPT) - 1);

                // Read input
                int bytes = system_call_3(syscall_read, 0, (positive)input_buffer, MAX_INPUT);
                if (bytes <= 0)
                        continue;

                print(RESET);

                // Parse and execute
                int arg_count = parse_input(input_buffer, args);

                if (arg_count > 0)
                {
                        if (!handle_builtin(args, arg_count))
                        {
                                exec_command(args);
                        }
                }

                // input_clear(input_buffer);
        }
}