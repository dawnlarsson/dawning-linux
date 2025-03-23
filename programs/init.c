#include "../standard/linux.c"

// TODO: just a placeholder, we are going to buffer the writes in the std
fn write(ADDRESS data, positive length)
{
        if (length == 0)
        {
                length = string_length(data);
        }

        system_call_3(syscall_write, stdout, (positive)data, length);
}

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
                write(lable "Mounting ", 0);
                write(mount->path, 0);
                write("...", 4);

                bipolar result = system_call_5(
                    syscall_mount,
                    (positive)mount->filesystem,
                    (positive)mount->path,
                    (positive)mount->filesystem,
                    (positive)mount->mount_flags,
                    NULL);

                if (result == 0)
                {
                        write(TERM_BOLD TERM_GREEN " OK", 0);
                }
                else
                {
                        write(TERM_BOLD TERM_RED " FAILED", 0);
                }

                write(TERM_RESET "\n", 6);

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

                bipolar result = system_call_2(syscall_execve, (positive)init_program, (positive)argv);

                write(lable "Failed to execute init program", 0);
                write(" (error: ", 10);
                string_to_bipolar(write, result);
                write(")\n", 2);

                exit(1);
        }

        while (1)
                sleep(1, 0);
}
