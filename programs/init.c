#include "../standard/linux.c"
#include "../standard/linux/writer.c"

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
                write(str("..."));

                bipolar result = system_call_4(
                    syscall_mount,
                    (positive)mount->filesystem,
                    (positive)mount->path,
                    (positive)mount->filesystem,
                    (positive)mount->mount_flags);

                if (result == 0)
                        write(str(TERM_BOLD TERM_GREEN " OK\n" TERM_RESET));
                else
                        write(str(TERM_BOLD TERM_RED " FAILED\n" TERM_RESET));

                writer_flush();
                mount++;
        }
}

b32 main()
{
        system_call(syscall_setsid);

        mount_filesystems();

        positive process_id = system_call(syscall_clone);

        if (process_id == 0)
        {
                while (1)
                        sleep(1, 0);
        }

        p8 ADDRESS_TO argv[] = {init_program};

        bipolar result = system_call_2(syscall_execve, (positive)init_program, (positive)argv);

        write(lable "Failed to execute init program", 0);
        write(str(" (error: "));
        bipolar_to_string(write, result);
        write(str(")\n"));

        writer_flush();

        return 1;
}
