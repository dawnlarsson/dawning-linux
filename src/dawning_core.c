#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/mount.h>
#include <linux/namei.h>
#include <linux/path.h>
#include <linux/fs_struct.h>
#include <linux/mount.h>
#include <linux/mnt_namespace.h>

#define DAWN_MODERN_C_KERNEL
#include "../standard/library.c"

#define log(fmt, ...) \
        pr_alert("[Dawning] " fmt, ##__VA_ARGS__)

typedef struct
{
        string_address filesystem;
        string_address path;
        positive mount_flags;
} MountPoints;

MountPoints mounts[] = {
    {"proc", "/proc", MNT_INTERNAL},
    {"sysfs", "/sys", MNT_INTERNAL},
    {NULL, NULL},
};

fn dawn_init_mount()
{
        MountPoints ADDRESS_TO mount = mounts;

        while (mount->filesystem)
        {
                struct file_system_type ADDRESS_TO fs_type = get_fs_type(mount->filesystem);

                if (!fs_type)
                {
                        mount++;
                        continue;
                }

                struct vfsmount ADDRESS_TO mnt = vfs_kern_mount(fs_type, 0, mount->filesystem, NULL);
                put_filesystem(fs_type);

                if (IS_ERR(mnt))
                {
                        log("vfs_kern_mount failed\n");
                        mount++;
                        continue;
                }

                mntput(mnt);

                struct path mountpoint_path;
                int err = kern_path(mount->path, LOOKUP_DIRECTORY, ADDRESS_OF mountpoint_path);

                if (err)
                {
                        log("kern_path failed\n");
                        mount++;
                        continue;
                }

                // struct vfsmount ADDRESS_TO mnt = do_add_mount(mnt, &mountpoint_path, mount->filesystem, mount->mount_flags);

                path_put(ADDRESS_OF mountpoint_path);
                mount++;
        }
}

p32 __init dawn_start()
{
        dawn_init_mount();

        return 0;
}

late_initcall(dawn_start);