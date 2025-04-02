#ifndef DAWN_MODERN_C_PLATFORM_MACOS
#define DAWN_MODERN_C_PLATFORM_MACOS

#if defined(ARM64)

#define syscall_indirect 0x0
#define syscall_exit 0x1
#define syscall_fork 0x2
#define syscall_read 0x3
#define syscall_write 0x4
#define syscall_open 0x5
#define syscall_close 0x6
#define syscall_wait4 0x7
#define syscall_creat -1 // Deprecated
#define syscall_link 0x9
#define syscall_unlink 0xA
#define syscall_execve -1 // Deprecated
#define syscall_chdir 0xC
#define syscall_fchdir 0xD
#define syscall_mknod 0xE
#define syscall_chmod 0xF
#define syscall_chown 0x10
#define syscall_break -1 // Deprecated
#define syscall_getfsstat 0x12
#define syscall_lseek -1 // Deprecated
#define syscall_getpid 0x14
#define syscall_mount -1   // Deprecated
#define syscall_unmount -1 // Deprecated
#define syscall_setuid 0x17
#define syscall_getuid 0x18
#define syscall_geteuid 0x19
#define syscall_ptrace 0x1a
#define syscall_recvmsg 0x1b
#define syscall_sendmsg 0x1c
#define syscall_recvfrom 0x1d
#define syscall_accept 0x1e
#define syscall_getpeername 0x1f
#define syscall_getsockname 0x20
#define syscall_access 0x21
#define syscall_chflags 0x22

#endif

#include "library.c"

fn exit()
{
        system_call_1(syscall_exit, 0);
}

fn start()
{
        b32 result = main();

        exit(result);
}

#endif