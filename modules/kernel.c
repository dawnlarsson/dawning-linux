#ifndef DAWN_MODERN_C_KERNEL
#define DAWN_MODERN_C_KERNEL

#define __MODULE__
#define _LINUX_MODULE_H

#include <linux/kernel.h>

#include "../standard/library.c"

static int __init standard_init_module()
{
        b32 result = main();
        return result;
}

static void __exit standard_exit_module()
{
        printk(KERN_ALERT "exiting module\n");
        return;
}

module_init(standard_init_module);
module_exit(standard_exit_module);

#endif
