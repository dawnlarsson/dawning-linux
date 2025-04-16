// A primitive pre-historic shell,
// it lobs rocks at the kernel and says ouga boga at the user.
#include "../standard/library.c"
#include "../standard/platform/shell.c"

#define PROMPT TERM_RESET TERM_BOLD " $ " TERM_RESET

#define MAX_INPUT 4096

p8 shell_buffer[MAX_INPUT];
positive shell_buffer_length;

fn shell_thread_instance(string_address command, string_address arguments)
{
        string_address arguments_list[] = {command, arguments, null};

        bipolar exec_result = system_call_3(syscall(execve), (positive)command, (positive)arguments_list, 0);

        string_format(log, "failed with error: %b\n", exec_result);
        log_flush();

        exit(1);
}

fn shell_execute_command(string_address command, string_address arguments)
{
        log_flush();

        bipolar fork_result = system_call_1(syscall(clone), 0);

        if (fork_result == 0)
        {
                shell_thread_instance(command, arguments);
        }
        else if (fork_result > 0)
        {
                positive status = 0;
                bipolar wait_result = system_call_4(syscall(wait4), fork_result, (positive)address_of status, 0, 0);
        }
        else
        {
                string_format(log, "failed with error: %b\n", fork_result);
        }

        log_flush();
}

bool shell_builtin(string_address arguments)
{
        core_command address_to command = core_commands;

        while (command->name)
        {
                if (string_compare(command->name, shell_buffer))
                {
                        command++;
                        continue;
                }

                command->function(log, arguments);
                return true;
        }

        return false;
}

// Single pass command parser
fn process_command()
{
        if (shell_buffer[0] == 0)
                return;

        p32 length = 0;
        bool is_first_section = true;
        string_address arguments_buffer = null;

        while (shell_buffer[length] != '\0')
        {
                if (shell_buffer[length] != ' ')
                {
                        length++;
                        continue;
                }

                shell_buffer[length] = '\0';

                if (shell_buffer[length + 1] != ' ' && shell_buffer[length + 1] != '\0')
                {
                        is_first_section = false;
                        arguments_buffer = shell_buffer + length + 1;
                }

                break;
        }

        if (shell_buffer[0] == '.' || shell_buffer[0] == '/')
                return shell_execute_command(shell_buffer, arguments_buffer);

        if (shell_builtin(arguments_buffer))
                return;

        string_format(log, "Command not found: %s\n", shell_buffer);
}

b32 main()
{
        system_call(syscall(setsid));
        system_call_2(2, (positive) "/dev/console", O_RDWR | O_NOCTTY);

        while (1)
        {
                memory_fill(shell_buffer, 0, MAX_INPUT);

                log(str(TERM_MAIN_BUFFER TERM_RESET TERM_SHOW_CURSOR PROMPT));

                log_flush();

                shell_buffer_length = system_call_3(syscall(read), 0, (positive)shell_buffer, MAX_INPUT);

                if (shell_buffer_length > MAX_INPUT)
                        shell_buffer_length = MAX_INPUT;

                if (shell_buffer[shell_buffer_length - 1] == '\n')
                        shell_buffer[shell_buffer_length - 1] = '\0';

                process_command();
        }
}