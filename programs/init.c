#include "../standard/library.c"

#define label TERM_BOLD "[Init]" TERM_RESET " "
#define init_program "/shell"

typedef struct
{
        string_address filesystem;
        string_address path;
        positive mount_flags;
} MountPoints;

MountPoints mounts[] = {
    {"proc", "/proc", MS_NONE},
    {"sysfs", "/sys", MS_NONE},
    {NULL, NULL},
};

fn mount_filesystems()
{
        MountPoints address_to mount = mounts;

        while (mount->filesystem)
        {
                log(label "Mounting ", 0);
                log(mount->path, 0);
                log(str("..."));

                bipolar result = system_call_4(
                    syscall(mount),
                    (positive)mount->filesystem,
                    (positive)mount->path,
                    (positive)mount->filesystem,
                    (positive)mount->mount_flags);

                if (result == 0)
                        log(str(TERM_BOLD TERM_GREEN " OK\n" TERM_RESET));
                else
                        log(str(TERM_BOLD TERM_RED " FAILED\n" TERM_RESET));

                log_flush();
                mount++;
        }
}

b32 main()
{
        system_call(syscall(setsid));

        mount_filesystems();

        positive process_id = system_call(syscall(clone));

        if (process_id == 0)
        {
                while (1)
                        sleep(1, 0);
        }

        p8 address_to argv[] = {init_program};

        bipolar result = system_call_2(syscall(execve), (positive)init_program, (positive)argv);

        log(label "Failed to execute init program", 0);
        log(str(" (error: "));
        bipolar_to_string(log, result);
        log(str(")\n"));

        log_flush();

        return 1;
}
