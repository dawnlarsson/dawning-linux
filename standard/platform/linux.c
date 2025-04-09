/*
        Dawning Experimental C standard library

        Linux platform specific functions and definitions

        Dawn Larsson - Apache-2.0 license
        github.com/dawnlarsson/dawning-linux/library/standard.c

        www.dawning.dev
*/

#ifndef DAWN_MODERN_C_PLATFORM_LINUX
#define DAWN_MODERN_C_PLATFORM_LINUX

#include "library.c"

struct linux_dirent64
{
        p64 d_ino;
        p64 d_off;
        p16 d_reclen;
        p8 d_type;
        p8 d_name[];
};

positive2 term_size()
{
        positive2 size = {80, 24};

        struct
        {
                p16 rows;
                p16 cols;
                p16 xpixel;
                p16 ypixel;
        } data;

        if (!system_call_3(syscall(ioctl), 1, 0x5413, (positive)ADDRESS_OF data))
        {
                size.width = data.cols;
                size.height = data.rows;
        }

        return size;
}

// TODO: fixme
fn sleep(positive seconds, positive nanoseconds)
{
        return;

        struct timespec time = {seconds, nanoseconds};
        system_call_1(syscall(nanosleep), (positive)ADDRESS_OF time);
}

fn exit(b32 code)
{
        system_call_1(syscall(exit), code);
}

fn _start()
{
        // TODO: copy arguments from the stack

        b32 result = main();

        exit(result);
}

#endif