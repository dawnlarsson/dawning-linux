#include "../library/standard.c"

#define lable "[Init] "
#define init_program "/shell"

#define MS_NONE 0
#define MS_RDONLY 1
#define MS_NOSUID 2
#define MS_NODEV 4
#define MS_NOEXEC 8
#define MS_SYNCHRONOUS 16
#define MS_REMOUNT 32
#define MS_MANDLOCK 64
#define MS_DIRSYNC 128
#define MS_NOSYMFOLLOW 256
#define MS_NOATIME 1024
#define MS_NODIRATIME 2048
#define MS_BIND 4096
#define MS_MOVE 8192
#define MS_REC 16384
#define MS_SILENT 32768
#define MS_POSIXACL (1 << 16)
#define MS_UNBINDABLE (1 << 17)
#define MS_PRIVATE (1 << 18)
#define MS_SLAVE (1 << 19)
#define MS_SHARED (1 << 20)
#define MS_RELATIME (1 << 21)
#define MS_KERNMOUNT (1 << 22)
#define MS_I_VERSION (1 << 23)
#define MS_STRICTATIME (1 << 24)

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

                system_call_2(syscall_execve, (bipolar)init_program, (bipolar)argv);
                print(lable "Failed to execute init program");

                system_call_1(syscall_exit, 1);
        }

        while (1)
                system_call_1(syscall_nanosleep, (positive)1);
}
