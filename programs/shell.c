// A primitive pre-historic shell,
// it lobs rocks at the kernel and says ouga boga at the user.
#include "../standard/linux/util.c"

#define PROMPT TERM_RESET TERM_BOLD " $ " TERM_RESET

#define MAX_INPUT 4096

p8 buffer[MAX_INPUT];
positive buffer_length;

p8 writer_buffer[MAX_INPUT];
positive writer_buffer_length;

fn writer_flush()
{
        if (writer_buffer_length == 0)
                return;

        system_call_3(syscall_write, stdout, (positive)writer_buffer, writer_buffer_length);

        writer_buffer_length = 0;
}

fn write(ADDRESS data, positive length)
{
        if (length == 0)
                length = string_length(data);

        if (length + writer_buffer_length > MAX_INPUT)
                writer_flush();

        memory_copy(writer_buffer + writer_buffer_length, data, length);
        writer_buffer_length += length;
}

fn exec_command(string_address command, string_address args)
{
        if (command[0] != '/')
        {
                write("TODO: exec relative paths\n", 26);
                return;
        }

        positive process_id = system_call(syscall_fork);

        if (process_id < 0)
        {
                write("Failed to fork (error: ", 24);
                string_to_bipolar(write, process_id);
                write(")\n", 2);
                return;
        }

        if (process_id == 0)
        {
                p8 ADDRESS_TO argv[] = {command};

                bipolar result = system_call_2(syscall_execve, (positive)command, (positive)argv);

                write("Failed to execute command (error: ", 35);
                string_to_bipolar(write, result);
                write(")\n", 2);
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
                is_executable = true;

        while (buffer[length] != '\0')
        {
                if (is_first_section)
                {
                        if (buffer[length] == ' ' || buffer[length] == '\n')
                        {
                                buffer[length] = '\0';

                                if (buffer[length + 1] == ' ' || buffer[length + 1] == '\0')
                                        break;

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
                arguments_buffer = NULL;

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
                        command->function(write, arguments_buffer);
                        return;
                }
                command++;
        }

        write("Command not found: ", 20);
        write(buffer, 0);
        write("\n", 1);
}

b32 main()
{
        system_call(syscall_setsid);
        system_call_2(2, (positive) "/dev/console", O_RDWR | O_NOCTTY);

        while (1)
        {
                memory_fill(buffer, 0, MAX_INPUT);

                write(PROMPT, sizeof(PROMPT));

                writer_flush();

                buffer_length = system_call_3(syscall_read, 0, (positive)buffer, MAX_INPUT);

                if (buffer_length > MAX_INPUT)
                        buffer_length = MAX_INPUT;

                if (buffer[buffer_length - 1] == '\n')
                        buffer[buffer_length - 1] = '\0';

                process_command();
        }
}