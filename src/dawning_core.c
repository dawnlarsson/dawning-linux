#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/mount.h>
#include <linux/namei.h>
#include <linux/path.h>
#include <linux/fs_struct.h>

#define DAWN_MODERN_C_KERNEL
#include "../standard/library.c"

#define lable TERM_BOLD "[Init]" TERM_RESET " "
#define init_program "/shell"

typedef struct
{
        string_address filesystem;
        string_address path;
        positive mount_flags;
} MountPoints;

MountPoints mounts[] = {
    {"proc", "/proc", 0},
    {"sysfs", "/sys", 0},
    {NULL, NULL},
};

static fn mount_filesystems(void)
{
        MountPoints ADDRESS_TO mount = mounts;

        while (mount->filesystem)
        {
                pr_alert("Dawning Init: mount %s on %s with flags %lu\n",
                         mount->filesystem, mount->path, mount->mount_flags);

                bipolar result = do_mount(NULL, mount->filesystem, mount->path, mount->mount_flags, mount->filesystem);
                if (result == 0)
                        pr_alert("Dawning Init: mount %s on %s with flags %lu OK\n",
                                 mount->filesystem, mount->path, mount->mount_flags);
                else
                        pr_alert("Dawning Init: mount %s on %s with flags %lu FAILED\n",
                                 mount->filesystem, mount->path, mount->mount_flags);

                mount++;
        }
}

static int __init dawning_start(void)
{
        pr_alert("Dawning Core: Starting...\n");

        mount_filesystems();

        return 0;
}

late_initcall(dawning_start);