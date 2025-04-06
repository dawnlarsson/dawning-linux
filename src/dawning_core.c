#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/sched.h>

static int __init dawning_start(void)
{
        pr_alert("Dawning Core: Starting...\n");
        return 0;
}

late_initcall(dawning_start);