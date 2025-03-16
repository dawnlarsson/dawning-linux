#include "../library/standard.c"

#define init_program "/shell"

#define syscall_setsid 112

i32 main()
{
        system_call(syscall_setsid);

        bipolar process_id = system_call(syscall_fork);

        if (process_id != 0)
        {
                u8 ADDRESS_TO argv[] = {init_program};

                system_call_3(syscall_execve, (bipolar)init_program, (bipolar)argv, 0);
                print("Failed to execute init program");
                goto force_recovery;
        }

        const u8 proc_fs[] = "proc";
        const u8 proc_path[] = "/proc";
        print("mounting /proc");
        system_call_3(syscall_mount, (bipolar)proc_fs, (bipolar)proc_path, (bipolar)proc_fs);

        const u8 sys_fs[] = "sysfs";
        const u8 sys_path[] = "/sys";
        print("mounting /sys");
        system_call_3(syscall_mount, (bipolar)sys_fs, (bipolar)sys_path, (bipolar)sys_fs);

force_recovery:
        while (1)
        {
                system_call_1(syscall_nanosleep, (bipolar){0, 50000});
        }

        goto force_recovery;
}