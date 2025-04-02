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
#include "syscall.c"

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

#define DT_DIR 4
#define DT_REG 8
#define DT_LNK 10
#define DT_FIFO 1
#define DT_SOCK 12
#define DT_CHR 2
#define DT_BLK 6

#define O_RDONLY 00
#define O_WRONLY 01
#define O_RDWR 02
#define O_NOCTTY 0400
#define O_NONBLOCK 0
#define O_DIRECTORY 0200000
#define O_CREAT 0100

#define AT_FDCWD -100

#define SIGTRAP 5
#define SIGKILL 9
#define SIGSTOP 20

#define CLONE_CHILD_CLEARTID 0x00200000
#define CLONE_CHILD_SETTID 0x01000000
#define SIGCHLD 17

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

struct timespec
{
        positive tv_sec;
        positive tv_nsec;
};

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