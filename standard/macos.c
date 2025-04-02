#ifndef DAWN_MODERN_C_PLATFORM_MACOS
#define DAWN_MODERN_C_PLATFORM_MACOS

#include "library.c"

#ifdef ARM64

#define syscall_indirect 0x0
#define syscall_exit 0x1
#define syscall_fork 0x2
#define syscall_read 0x3
#define syscall_write 0x4
#define syscall_open 0x5
#define syscall_close 0x6
#define syscall_wait4 0x7
#define syscall_creat 0x8 // Deprecated
#define syscall_link 0x9
#define syscall_unlink 0xa
// #define syscall_execve 0xb // Deprecated
#define syscall_chdir 0xc
#define syscall_fchdir 0xd
#define syscall_mknod 0xe
#define syscall_chmod 0xf
#define syscall_chown 0x10
#define syscall_break 0x11 // Deprecated
#define syscall_getfsstat 0x12
#define syscall_lseek 0x13 // Deprecated
#define syscall_getpid 0x14
// #define syscall_mount 0x15 // Deprecated
// #define syscall_unmount 0x16 // Deprecated
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
#define syscall_fchflags 0x23
#define syscall_sync 0x24
#define syscall_kill 0x25
#define syscall_getppid 0x27
#define syscall_lstat 0x28
#define syscall_dup 0x29
#define syscall_pipe 0x2a
#define syscall_getegid 0x2b
#define syscall_profil 0x2c // Deprecated
#define syscall_ktrace 0x2d // Deprecated
#define syscall_sigaction 0x2e
#define syscall_getgid 0x2f
#define syscall_sigprocmask 0x30
#define syscall_getlogin 0x31
#define syscall_setlogin 0x32
#define syscall_acct 0x33
#define syscall_sigpending 0x34
#define syscall_sigaltstack 0x35
#define syscall_ioctl 0x36
#define syscall_reboot 0x37
#define syscall_revoke 0x38
#define syscall_symlink 0x39
#define syscall_readlink 0x3a
#define syscall_execve 0x3b
#define syscall_umask 0x3c
#define syscall_chroot 0x3d
// #define syscall_fstat 0x3e       // Deprecated
#define syscall_reserved_0 0x3f  // Reserved
#define syscall_getpagesize 0x40 // Deprecated
#define syscall_msync 0x41
#define syscall_vfork 0x42
#define syscall_vread 0x43   // Deprecated
#define syscall_vwrite 0x44  // Deprecated
#define syscall_sbrk 0x45    // Deprecated
#define syscall_sstk 0x46    // Deprecated
#define syscall_mmap 0x47    // Deprecated
#define syscall_vadvise 0x48 // Deprecated
#define syscall_munmap 0x49
#define syscall_mprotect 0x4a
#define syscall_vhangup 0x4b // Deprecated
#define syscall_vlimit 0x4c  // Deprecated
#define syscall_madvise 0x4d
#define syscall_mincore 0x4e
#define syscall_getgroups 0x4f
#define syscall_setgroups 0x50
#define syscall_getpgrp 0x51
#define syscall_setpgid 0x52
#define syscall_setitimer 0x53
#define syscall_wait 0x54 // Deprecated
#define syscall_swapon 0x55
#define syscall_getitimer 0x56
#define syscall_gethostname 0x57 // Deprecated
#define syscall_sethostname 0x58 // Deprecated
#define syscall_getdtablesize 0x59
#define syscall_dup2 0x5a
#define syscall_getdoprt 0x5b // Deprecated
#define syscall_fcntl 0x5c
#define syscall_select 0x5d
#define syscall_setdopt 0x5e // Deprecated
#define syscall_fsync 0x5f
#define syscall_setpriority 0x60
#define syscall_socket 0x61
#define syscall_connect 0x62
#define syscall_accept 0x63 // Deprecated
#define syscall_getpriority 0x64
#define syscall_send 0x65      // Deprecated
#define syscall_receive 0x66   // Deprecated
#define syscall_sigreturn 0x67 // Deprecated
#define syscall_bind 0x68
#define syscall_setsockopt 0x69
#define syscall_listen 0x6a
#define syscall_vtimes 0x6b  // Deprecated
#define syscall_sigvec 0x6c  // Deprecated
#define syscall_recvmsg 0x6d // Deprecated
#define syscall_vtrace 0x6e  // Deprecated
#define syscall_sigsuspend 0x6f4
#define syscall_gettimeofday 0x74
#define syscall_getrusage 0x75
#define syscall_getsockopt 0x76
#define syscall_resuba 0x77 // Deprecated
#define syscall_readv 0x78
#define syscall_writev 0x79
#define syscall_settimeofday 0x7a
#define syscall_fchown 0x7b
#define syscall_fchmod 0x7c
#define syscall_recvfrom 0x7d // Deprecated
#define syscall_setreuid 0x7e
#define syscall_setregid 0x7f
#define syscall_rename 0x80
#define syscall_truncate 0x81  // Deprecated
#define syscall_ftruncate 0x82 // Deprecated
#define syscall_flock 0x83
#define syscall_mkfifo 0x84
#define syscall_sendto 0x85
#define syscall_shutdown 0x86
#define syscall_socketpair 0x87
#define syscall_mkdir 0x88
#define syscall_rmdir 0x89
#define syscall_utimes 0x8a
#define syscall_futimes 0x8b
#define syscall_adjtime 0x8c
#define syscall_getpeername 0x8d // Deprecated
#define syscall_gethostid 0x8e
#define syscall_sethostid 0x8f // Deprecated
#define syscall_getrlimit 0x90 // Deprecated
#define syscall_setrlimit 0x91 // Deprecated
#define syscall_killpg 0x92    // Deprecated
#define syscall_setsid 0x93
#define syscall_setquota 0x94    // Deprecated
#define syscall_qquota 0x95      // Deprecated
#define syscall_getsockname 0x96 // Deprecated
#define syscall_getpgid 0x97
#define syscall_setprivexec 0x98
#define syscall_pread 0x99
#define syscall_pwrite 0x9a
#define syscall_nfssvc 0x9b
#define syscall_getdirentries 0x9c // Deprecated
#define syscall_statfs 0x9d
#define syscall_fstatfs 0x9e
#define syscall_unmount 0x9f
#define syscall_async_daemon 0xa0 // Deprecated
#define syscall_getfh 0xa1
#define syscall_getdomainname 0xa2 // Deprecated
#define syscall_setdomainname 0xa3 // Deprecated
#define syscall_reserved_1 0xa4
#define syscall_quotactl 0xa5
#define syscall_exportfs 0xa6 // Deprecated
#define syscall_mount 0xa7
#define syscall_ustat 0xa8 // Deprecated
#define syscall_csops 0xa9
#define syscall_csops_audittoken 0xaa
#define syscall_wait3 0xab  // Deprecated
#define syscall_rpause 0xac // Deprecated
#define syscall_waitid 0xad
#define syscall_getdents 0xae   // Deprecated
#define syscall_gc_control 0xaf // Deprecated

#endif

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