#include <linux/namei.h>

// todo: investigate the requirement to manually include this
int path_mount(const char *dev_name, struct path *path,
               const char *type_page, unsigned long flags, void *data_page);

#define DAWN_MODERN_C_KERNEL
#include "../standard/library.c"

#define log_k(fmt, ...) \
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
    {null, null},
};

fn dawn_init_mount()
{
        MountPoints address_to mount = mounts;

        while (mount->filesystem)
        {
                struct path path;

                int ret = kern_path(mount->path, LOOKUP_FOLLOW, &path);

                if (ret)
                {
                        log_k("Mounting %s to %s failed with error: %d\n", mount->filesystem, mount->path, ret);
                        mount++;
                        continue;
                }

                ret = path_mount(mount->filesystem, &path, mount->filesystem, mount->mount_flags, null);
                path_put(&path);

                if (!ret)
                {
                        log_k("Mounted %s to %s\n", mount->filesystem, mount->path);
                }

                mount++;
        }
}

b32 __init dawn_start()
{
        log_k("Dawning Eos - Kernel Extentions starting...\n");

        dawn_init_mount();

        return 0;
}

late_initcall(dawn_start);