#include "../library/standard.c"

#define init_program "/shell"

typedef struct
{
        string_address filesystem;
        string_address path;
} MountPoints;

MountPoints mounts[] = {
    {"proc", "/proc"},
    {"sysfs", "/sys"},
    {NULL, NULL},
};

fn mount_filesystems()
{
        MountPoints ADDRESS_TO mount = mounts;

        while (mount->filesystem)
        {
                print("[Dawning] Mounting ");
                print(mount->path);
                print("...");

                if (system_call_3(syscall_mount, (bipolar)mount->filesystem,
                                  (bipolar)mount->path, (bipolar)mount->filesystem) == 0)
                {
                        print(" [OK]");
                }
                else
                {
                        print(" [FAILED]");
                }

                print("\n");

                mount++;
        }
}

b32 main()
{
        system_call(syscall_setsid);

        mount_filesystems();

        bipolar process_id = system_call(syscall_fork);

        if (process_id != 0)
        {
                b8 ADDRESS_TO argv[] = {init_program};

                system_call_3(syscall_execve, (bipolar)init_program, (bipolar)argv, 0);
                print("Failed to execute init program");
        }

        while (1)
                system_call_1(syscall_nanosleep, (bipolar){1});
}