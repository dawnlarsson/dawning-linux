#include "../standard/linux.c"

#define lable TERM_BOLD "[Init]" TERM_RESET " "
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
        MountPoints ADDRESS_TO mount = mounts;

        while (mount->filesystem)
        {
                print(lable "Mounting ");
                print(mount->path);
                print("...");

                bipolar result = system_call_5(
                    syscall_mount,
                    (positive)mount->filesystem,
                    (positive)mount->path,
                    (positive)mount->filesystem,
                    (positive)mount->mount_flags,
                    NULL);

                if (result == 0)
                {
                        print(TERM_BOLD TERM_GREEN " OK");
                }
                else
                {
                        print(TERM_BOLD TERM_RED " FAILED");
                }

                print(TERM_RESET "\n");

                mount++;
        }
}

b32 main()
{
        system_call(syscall_setsid);

        mount_filesystems();

        positive process_id = system_call(syscall_fork);

        if (process_id != 0)
        {
                p8 ADDRESS_TO argv[] = {init_program};

                system_call_2(syscall_execve, (bipolar)init_program, (positive)argv);

                print(lable "Failed to execute init program");

                exit(1);
        }

        while (1)
                sleep(1, 0);
}
