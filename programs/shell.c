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

        if (length > MAX_INPUT)
        {
                system_call_3(syscall_write, stdout, (positive)data, length);
                return;
        }

        memory_copy(writer_buffer + writer_buffer_length, data, length);
        writer_buffer_length += length;
}

fn shell_thread_instance(string_address command, string_address arguments)
{
        string_address arguments_list[] = {command, arguments, NULL};

        bipolar exec_result = system_call_3(syscall_execve, (positive)command, (positive)arguments_list, 0);

        write(str("failed with error: "));
        write(bipolar_to_string(exec_result), 0);
        write(str("\n"));

        writer_flush();

        exit(1);
}

fn shell_execute_command(string_address command, string_address arguments)
{
        writer_flush();

        bipolar fork_result = system_call_1(syscall_fork, 0);

        if (fork_result == 0)
        {
                shell_thread_instance(command, arguments);
        }
        else if (fork_result > 0)
        {
                positive status = 0;
                bipolar wait_result = system_call_4(syscall_wait4, fork_result, (positive)ADDRESS_OF status, 0, 0);
        }
        else
        {
                write(str("failed with error: "));
                write(bipolar_to_string(fork_result), 0);
                write(str("\n"));
        }

        writer_flush();
}

bool shell_builtin(string_address arguments)
{
        core_command ADDRESS_TO command = core_commands;

        while (command->name)
        {
                if (string_compare(command->name, buffer))
                {
                        command++;
                        continue;
                }

                command->function(write, arguments);
                return true;
        }

        return false;
}

// Single pass command parser
fn process_command()
{
        if (buffer[0] == 0)
                return;

        p32 length = 0;
        bool is_first_section = true;
        string_address arguments_buffer = NULL;

        while (buffer[length] != '\0')
        {
                if (buffer[length] != ' ')
                {
                        length++;
                        continue;
                }

                buffer[length] = '\0';

                if (buffer[length + 1] != ' ' && buffer[length + 1] != '\0')
                {
                        is_first_section = false;
                        arguments_buffer = buffer + length + 1;
                }

                break;
        }

        if (buffer[0] == '.' || buffer[0] == '/')
                return shell_execute_command(buffer, arguments_buffer);

        if (shell_builtin(arguments_buffer))
                return;

        write(str("Command not found: "));
        write(buffer, 0);
        write(str("\n"));
}

b32 main()
{
        system_call(syscall_setsid);
        system_call_2(2, (positive) "/dev/console", O_RDWR | O_NOCTTY);

        while (1)
        {
                memory_fill(buffer, 0, MAX_INPUT);

                write(str(PROMPT));

                writer_flush();

                buffer_length = system_call_3(syscall_read, 0, (positive)buffer, MAX_INPUT);

                if (buffer_length > MAX_INPUT)
                        buffer_length = MAX_INPUT;

                if (buffer[buffer_length - 1] == '\n')
                        buffer[buffer_length - 1] = '\0';

                process_command();
        }
}