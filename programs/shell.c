// A primitive pre-historic shell,
// it lobs rocks at the kernel and says ouga boga at the user.
#include "../standard/library.c"
#include "../standard/platform/shell.c"

#define PROMPT TERM_RESET TERM_BOLD " $ " TERM_RESET

#define MAX_INPUT 4096
p8 shell_buffer[MAX_INPUT];
positive input_length;

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
                shell_thread_instance(command, arguments);
        
        if (fork_result > 0)
        {
                positive status = 0;
                bipolar wait_result = system_call_4(syscall(wait4), fork_result, (positive)address_of status, 0, 0);
        } else
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

// process_command v2
fn process()
{
        string_address step = string_cut(shell_buffer, ' ');

        if(shell_buffer[input_length - 1] == '\n')
                shell_buffer[input_length - 1] = end;

        if (string_is(shell_buffer, '.') || string_is(shell_buffer, '/'))
                return shell_execute_command(shell_buffer, step);
        
        if (shell_builtin(step))
                return;
        
        string_format(log, "Command not found: '%s'\n", shell_buffer);
}

b32 main()
{
        system_call(syscall(setsid));
        system_call_2(2, (positive) "/dev/console", O_RDWR | O_NOCTTY);

        while (1)
        {
                memory_fill(shell_buffer, end, MAX_INPUT);

                log_direct(str(TERM_MAIN_BUFFER TERM_RESET TERM_SHOW_CURSOR PROMPT));

                input_length = system_call_3(syscall(read), 0, (positive)shell_buffer, MAX_INPUT);

                process();

                log_flush();
        }
}