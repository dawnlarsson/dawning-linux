// A primitive pre-historic shell,
// it lobs rocks at the kernel and says ouga boga at the user.
#include "../standard/util.c"

#define PROMPT TERM_BOLD " $ " TERM_RESET

p8 buffer[MAX_INPUT];
positive buffer_length;

fn exec_command(string_address command, string_address args)
{
        if (command[0] != '/')
        {
                print("TODO: exec relative paths, try exec for now :) \n");
                return;
        }

        positive process_id = system_call(syscall_fork);

        if (process_id < 0)
        {
                print("Failed to fork (error: ");
                print_bipolar(process_id);
                print(")\n");
                return;
        }

        if (process_id == 0)
        {
                p8 ADDRESS_TO argv[] = {command};

                bipolar result = system_call_2(syscall_execve, (positive)command, (positive)argv);

                print("Failed to execute command (error: ");
                print_bipolar(result);
                print(")\n");
                exit(1);
        }

        system_call_1(syscall_wait4, process_id);
}

// Single pass command parser
fn process_command()
{
        if (buffer[0] == 0)
                return;

        p32 length = 0;
        string_address arguments_buffer;
        bool is_first_section = true;

        bool is_executable = false;

        if (buffer[0] == '.' || buffer[0] == '/')
        {
                is_executable = true;
        }

        while (buffer[length] != '\0')
        {
                if (is_first_section)
                {
                        if (buffer[length] == ' ' || buffer[length] == '\n')
                        {
                                if (buffer[length + 1] == ' ' || buffer[length + 1] == '\0')
                                {
                                        print("Invalid command\n");
                                        return;
                                }

                                buffer[length] = '\0';
                                is_first_section = false;

                                length++;
                                arguments_buffer = buffer + length;

                                // we don't care about arguments for now
                                break;
                        }
                }

                length++;
        }

        if (is_first_section)
        {
                arguments_buffer = NULL;
        }

        if (is_executable)
        {
                exec_command(buffer, arguments_buffer);
                return;
        }

        core_command ADDRESS_TO command = core_commands;

        while (command->name)
        {
                if (string_compare(command->name, buffer) == 0)
                {
                        command->function(arguments_buffer);
                        return;
                }
                command++;
        }

        print("Command not found: ");
        print(buffer);
        print("\n");
}

b32 main()
{
        system_call(syscall_setsid);
        system_call_2(2, (positive) "/dev/console", O_RDWR | O_NOCTTY);

        while (1)
        {
                memory_fill(buffer, 0, MAX_INPUT);

                print(TERM_RESET PROMPT);

                buffer_length = system_call_3(syscall_read, 0, (positive)buffer, MAX_INPUT);

                if (buffer_length > MAX_INPUT)
                        buffer_length = MAX_INPUT;

                if (buffer[buffer_length - 1] == '\n')
                        buffer[buffer_length - 1] = '\0';

                process_command();
        }
}