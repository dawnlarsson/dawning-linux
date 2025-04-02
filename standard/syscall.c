/*
        Dawning Experimental C standard library

        single file syscall table for Linux and Apple platforms,
        can be used standalone or as part of the Dawning C standard library

        example usage without of Dawning C:
                #define LINUX 1
                #define X64 1
                syscall(read) // returns syscall_linux_x64_read ( 0 )

        Dawn Larsson - Apache-2.0 license
        github.com/dawnlarsson/dawning-linux/library/standard.c

        www.dawning.dev
*/

#ifdef LINUX

#ifdef X64
#define syscall(name) syscall_linux_x64_##name
#endif

#ifdef ARM64
#define syscall(name) syscall_linux_arm64_##name
#endif

#endif

#ifdef MACOS

#ifdef X64
#define syscall(name) syscall_macos_x64_##name
#endif

#ifdef ARM64
#define syscall(name) syscall_macos_arm64_##name
#endif

#endif

// Linux

#define syscall_linux_x64_read 0
#define syscall_linux_x64_write 1
#define syscall_linux_x64_open -1 // Deprecated use openat
#define syscall_linux_x64_close 3
#define syscall_linux_x64_stat -1 // Deprecated use fstat
#define syscall_linux_x64_fstat 5
#define syscall_linux_x64_lstat -1 // Deprecated use fstat
#define syscall_linux_x64_poll 7
#define syscall_linux_x64_lseek 8
#define syscall_linux_x64_mmap 9
#define syscall_linux_x64_mprotect 10
#define syscall_linux_x64_munmap 11
#define syscall_linux_x64_brk 12
#define syscall_linux_x64_rt_sigaction 13
#define syscall_linux_x64_rt_sigprocmask 14
#define syscall_linux_x64_rt_sigreturn 15
#define syscall_linux_x64_ioctl 16
#define syscall_linux_x64_pread64 17
#define syscall_linux_x64_pwrite64 18
#define syscall_linux_x64_readv 19
#define syscall_linux_x64_writev 20
#define syscall_linux_x64_access 21
#define syscall_linux_x64_pipe 22
#define syscall_linux_x64_select 23
#define syscall_linux_x64_sched_yield 24
#define syscall_linux_x64_mremap 25
#define syscall_linux_x64_msync 26
#define syscall_linux_x64_mincore 27
#define syscall_linux_x64_madvise 28
#define syscall_linux_x64_shmget 29
#define syscall_linux_x64_shmat 30
#define syscall_linux_x64_shmctl 31
#define syscall_linux_x64_dup 32
#define syscall_linux_x64_dup2 33
#define syscall_linux_x64_pause 34
#define syscall_linux_x64_nanosleep 35
#define syscall_linux_x64_getitimer 36
#define syscall_linux_x64_alarm 37
#define syscall_linux_x64_setitimer 38
#define syscall_linux_x64_getpid 39
#define syscall_linux_x64_sendfile 40
#define syscall_linux_x64_socket 41
#define syscall_linux_x64_connect 42
#define syscall_linux_x64_accept 43
#define syscall_linux_x64_sendto 44
#define syscall_linux_x64_recvfrom 45
#define syscall_linux_x64_sendmsg 46
#define syscall_linux_x64_recvmsg 47
#define syscall_linux_x64_shutdown 48
#define syscall_linux_x64_bind 49
#define syscall_linux_x64_listen 50
#define syscall_linux_x64_getsockname 51
#define syscall_linux_x64_getpeername 52
#define syscall_linux_x64_socketpair 53
#define syscall_linux_x64_setsockopt 54
#define syscall_linux_x64_getsockopt 55
#define syscall_linux_x64_clone 56
#define syscall_linux_x64_fork 57
#define syscall_linux_x64_vfork 58
#define syscall_linux_x64_execve 59
#define syscall_linux_x64_exit 60
#define syscall_linux_x64_wait4 61
#define syscall_linux_x64_kill 62
#define syscall_linux_x64_uname 63
#define syscall_linux_x64_semget 64
#define syscall_linux_x64_semop 65
#define syscall_linux_x64_semctl 66
#define syscall_linux_x64_shmdt 67
#define syscall_linux_x64_msgget 68
#define syscall_linux_x64_msgsnd 69
#define syscall_linux_x64_msgrcv 70
#define syscall_linux_x64_msgctl 71
#define syscall_linux_x64_fcntl 72
#define syscall_linux_x64_flock 73
#define syscall_linux_x64_fsync 74
#define syscall_linux_x64_fdatasync 75
#define syscall_linux_x64_truncate 76
#define syscall_linux_x64_ftruncate 77
#define syscall_linux_x64_getdents 78
#define syscall_linux_x64_getcwd 79
#define syscall_linux_x64_chdir 80
#define syscall_linux_x64_fchdir 81
#define syscall_linux_x64_rename 82
#define syscall_linux_x64_mkdir 83
#define syscall_linux_x64_rmdir 84
#define syscall_linux_x64_creat 85
#define syscall_linux_x64_link 86
#define syscall_linux_x64_unlink 87
#define syscall_linux_x64_symlink 88
#define syscall_linux_x64_readlink 89
#define syscall_linux_x64_chmod -1 // Deprecated use fchmod
#define syscall_linux_x64_fchmod 91
#define syscall_linux_x64_chown 92
#define syscall_linux_x64_fchown 93
#define syscall_linux_x64_lchown 94
#define syscall_linux_x64_umask 95
#define syscall_linux_x64_gettimeofday 96
#define syscall_linux_x64_getrlimit 97
#define syscall_linux_x64_getrusage 98
#define syscall_linux_x64_sysinfo 99
#define syscall_linux_x64_times 100
#define syscall_linux_x64_ptrace 101
#define syscall_linux_x64_getuid 102
#define syscall_linux_x64_syslog 103
#define syscall_linux_x64_getgid 104
#define syscall_linux_x64_setuid 105
#define syscall_linux_x64_setgid 106
#define syscall_linux_x64_geteuid 107
#define syscall_linux_x64_getegid 108
#define syscall_linux_x64_setpgid 109
#define syscall_linux_x64_getppid 110
#define syscall_linux_x64_getpgrp 111
#define syscall_linux_x64_setsid 112
#define syscall_linux_x64_setreuid 113
#define syscall_linux_x64_setregid 114
#define syscall_linux_x64_getgroups 115
#define syscall_linux_x64_setgroups 116
#define syscall_linux_x64_setresuid 117
#define syscall_linux_x64_getresuid 118
#define syscall_linux_x64_setresgid 119
#define syscall_linux_x64_getresgid 120
#define syscall_linux_x64_getpgid 121
#define syscall_linux_x64_setfsuid 122
#define syscall_linux_x64_setfsgid 123
#define syscall_linux_x64_getsid 124
#define syscall_linux_x64_capget 125
#define syscall_linux_x64_capset 126
#define syscall_linux_x64_rt_sigpending 127
#define syscall_linux_x64_rt_sigtimedwait 128
#define syscall_linux_x64_rt_sigqueueinfo 129
#define syscall_linux_x64_rt_sigsuspend 130
#define syscall_linux_x64_sigaltstack 131
#define syscall_linux_x64_utime 132
#define syscall_linux_x64_mknod 133
#define syscall_linux_x64_uselib 134
#define syscall_linux_x64_personality 135
#define syscall_linux_x64_ustat 136
#define syscall_linux_x64_statfs 137
#define syscall_linux_x64_fstatfs 138
#define syscall_linux_x64_sysfs 139
#define syscall_linux_x64_getpriority 140
#define syscall_linux_x64_setpriority 141
#define syscall_linux_x64_sched_setparam 142
#define syscall_linux_x64_sched_getparam 143
#define syscall_linux_x64_sched_setscheduler 144
#define syscall_linux_x64_sched_getscheduler 145
#define syscall_linux_x64_sched_get_priority_max 146
#define syscall_linux_x64_sched_get_priority_min 147
#define syscall_linux_x64_sched_rr_get_interval 148
#define syscall_linux_x64_mlock 149
#define syscall_linux_x64_munlock 150
#define syscall_linux_x64_mlockall 151
#define syscall_linux_x64_munlockall 152
#define syscall_linux_x64_vhangup 153
#define syscall_linux_x64_modify_ldt 154
#define syscall_linux_x64_pivot_root 155
#define syscall_linux_x64__sysctl 156
#define syscall_linux_x64_prctl 157
#define syscall_linux_x64_arch_prctl 158
#define syscall_linux_x64_adjtimex 159
#define syscall_linux_x64_setrlimit 160
#define syscall_linux_x64_chroot 161
#define syscall_linux_x64_sync 162
#define syscall_linux_x64_acct 163
#define syscall_linux_x64_settimeofday 164
#define syscall_linux_x64_mount 165
#define syscall_linux_x64_umount2 166
#define syscall_linux_x64_swapon 167
#define syscall_linux_x64_swapoff 168
#define syscall_linux_x64_reboot 169
#define syscall_linux_x64_sethostname 170
#define syscall_linux_x64_setdomainname 171
#define syscall_linux_x64_iopl 172
#define syscall_linux_x64_ioperm 173
#define syscall_linux_x64_create_module 174
#define syscall_linux_x64_init_module 175
#define syscall_linux_x64_delete_module 176
#define syscall_linux_x64_get_kernel_syms 177
#define syscall_linux_x64_query_module 178
#define syscall_linux_x64_quotactl 179
#define syscall_linux_x64_nfsservctl 180
#define syscall_linux_x64_getpmsg 181
#define syscall_linux_x64_putpmsg 182
#define syscall_linux_x64_afs_syscall 183
#define syscall_linux_x64_tuxcall 184
#define syscall_linux_x64_security 185
#define syscall_linux_x64_gettid 186
#define syscall_linux_x64_readahead 187
#define syscall_linux_x64_setxattr 188
#define syscall_linux_x64_lsetxattr 189
#define syscall_linux_x64_fsetxattr 190
#define syscall_linux_x64_getxattr 191
#define syscall_linux_x64_lgetxattr 192
#define syscall_linux_x64_fgetxattr 193
#define syscall_linux_x64_listxattr 194
#define syscall_linux_x64_llistxattr 195
#define syscall_linux_x64_flistxattr 196
#define syscall_linux_x64_removexattr 197
#define syscall_linux_x64_lremovexattr 198
#define syscall_linux_x64_fremovexattr 199
#define syscall_linux_x64_tkill 200
#define syscall_linux_x64_time 201
#define syscall_linux_x64_futex 202
#define syscall_linux_x64_sched_setaffinity 203
#define syscall_linux_x64_sched_getaffinity 204
#define syscall_linux_x64_set_thread_area 205
#define syscall_linux_x64_io_setup 206
#define syscall_linux_x64_io_destroy 207
#define syscall_linux_x64_io_getevents 208
#define syscall_linux_x64_io_submit 209
#define syscall_linux_x64_io_cancel 210
#define syscall_linux_x64_get_thread_area 211
#define syscall_linux_x64_lookup_dcookie 212
#define syscall_linux_x64_epoll_create 213
#define syscall_linux_x64_epoll_ctl_old 214
#define syscall_linux_x64_epoll_wait_old 215
#define syscall_linux_x64_remap_file_pages 216
#define syscall_linux_x64_getdents64 217
#define syscall_linux_x64_set_tid_address 218
#define syscall_linux_x64_restart_syscall 219
#define syscall_linux_x64_semtimedop 220
#define syscall_linux_x64_fadvise64 221
#define syscall_linux_x64_timer_create 222
#define syscall_linux_x64_timer_settime 223
#define syscall_linux_x64_timer_gettime 224
#define syscall_linux_x64_timer_getoverrun 225
#define syscall_linux_x64_timer_delete 226
#define syscall_linux_x64_clock_settime 227
#define syscall_linux_x64_clock_gettime 228
#define syscall_linux_x64_clock_getres 229
#define syscall_linux_x64_clock_nanosleep 230
#define syscall_linux_x64_exit_group 231
#define syscall_linux_x64_epoll_wait 232
#define syscall_linux_x64_epoll_ctl 233
#define syscall_linux_x64_tgkill 234
#define syscall_linux_x64_utimes 235
#define syscall_linux_x64_vserver 236
#define syscall_linux_x64_mbind 237
#define syscall_linux_x64_set_mempolicy 238
#define syscall_linux_x64_get_mempolicy 239
#define syscall_linux_x64_mq_open 240
#define syscall_linux_x64_mq_unlink 241
#define syscall_linux_x64_mq_timedsend 242
#define syscall_linux_x64_mq_timedreceive 243
#define syscall_linux_x64_mq_notify 244
#define syscall_linux_x64_mq_getsetattr 245
#define syscall_linux_x64_kexec_load 246
#define syscall_linux_x64_waitid 247
#define syscall_linux_x64_add_key 248
#define syscall_linux_x64_request_key 249
#define syscall_linux_x64_keyctl 250
#define syscall_linux_x64_ioprio_set 251
#define syscall_linux_x64_ioprio_get 252
#define syscall_linux_x64_inotify_init 253
#define syscall_linux_x64_inotify_add_watch 254
#define syscall_linux_x64_inotify_rm_watch 255
#define syscall_linux_x64_migrate_pages 256
#define syscall_linux_x64_openat 257
#define syscall_linux_x64_mkdirat 258
#define syscall_linux_x64_mknodat 259
#define syscall_linux_x64_fchownat 260
#define syscall_linux_x64_futimesat 261
#define syscall_linux_x64_newfstatat 262
#define syscall_linux_x64_unlinkat 263
#define syscall_linux_x64_renameat 264
#define syscall_linux_x64_linkat 265
#define syscall_linux_x64_symlinkat 266
#define syscall_linux_x64_readlinkat 267
#define syscall_linux_x64_fchmodat 268
#define syscall_linux_x64_faccessat 269
#define syscall_linux_x64_pselect6 270
#define syscall_linux_x64_ppoll 271
#define syscall_linux_x64_unshare 272
#define syscall_linux_x64_set_robust_list 273
#define syscall_linux_x64_get_robust_list 274
#define syscall_linux_x64_splice 275
#define syscall_linux_x64_tee 276
#define syscall_linux_x64_sync_file_range 277
#define syscall_linux_x64_vmsplice 278
#define syscall_linux_x64_move_pages 279
#define syscall_linux_x64_utimensat 280
#define syscall_linux_x64_epoll_pwait 281
#define syscall_linux_x64_signalfd 282
#define syscall_linux_x64_timerfd_create 283
#define syscall_linux_x64_eventfd 284
#define syscall_linux_x64_fallocate 285
#define syscall_linux_x64_timerfd_settime 286
#define syscall_linux_x64_timerfd_gettime 287
#define syscall_linux_x64_accept4 288
#define syscall_linux_x64_signalfd4 289
#define syscall_linux_x64_eventfd2 290
#define syscall_linux_x64_epoll_create1 291
#define syscall_linux_x64_dup3 292
#define syscall_linux_x64_pipe2 293
#define syscall_linux_x64_inotify_init1 294
#define syscall_linux_x64_preadv 295
#define syscall_linux_x64_pwritev 296
#define syscall_linux_x64_rt_tgsigqueueinfo 297
#define syscall_linux_x64_perf_event_open 298
#define syscall_linux_x64_recvmmsg 299
#define syscall_linux_x64_fanotify_init 300
#define syscall_linux_x64_fanotify_mark 301
#define syscall_linux_x64_prlimit64 302
#define syscall_linux_x64_name_to_handle_at 303
#define syscall_linux_x64_open_by_handle_at 304
#define syscall_linux_x64_clock_adjtime 305
#define syscall_linux_x64_syncfs 306
#define syscall_linux_x64_sendmmsg 307
#define syscall_linux_x64_setns 308
#define syscall_linux_x64_getcpu 309
#define syscall_linux_x64_process_vm_readv 310
#define syscall_linux_x64_process_vm_writev 311
#define syscall_linux_x64_kcmp 312
#define syscall_linux_x64_finit_module 313
#define syscall_linux_x64_sched_setattr 314
#define syscall_linux_x64_sched_getattr 315
#define syscall_linux_x64_renameat2 316
#define syscall_linux_x64_seccomp 317
#define syscall_linux_x64_getrandom 318
#define syscall_linux_x64_memfd_create 319
#define syscall_linux_x64_kexec_file_load 320
#define syscall_linux_x64_bpf 321
#define syscall_linux_x64_execveat 322
#define syscall_linux_x64_userfaultfd 323
#define syscall_linux_x64_membarrier 324
#define syscall_linux_x64_mlock2 325
#define syscall_linux_x64_copy_file_range 326
#define syscall_linux_x64_preadv2 327
#define syscall_linux_x64_pwritev2 328
#define syscall_linux_x64_pkey_mprotect 329
#define syscall_linux_x64_pkey_alloc 330
#define syscall_linux_x64_pkey_free 331
#define syscall_linux_x64_statx 332
#define syscall_linux_x64_io_pgetevents 333
#define syscall_linux_x64_rseq 334
#define syscall_linux_x64_uretprobe 335
#define syscall_linux_x64_pidfd_send_signal 424
#define syscall_linux_x64_io_uring_setup 425
#define syscall_linux_x64_io_uring_enter 426
#define syscall_linux_x64_io_uring_register 427
#define syscall_linux_x64_open_tree 428
#define syscall_linux_x64_move_mount 429
#define syscall_linux_x64_fsopen 430
#define syscall_linux_x64_fsconfig 431
#define syscall_linux_x64_fsmount 432
#define syscall_linux_x64_fspick 433
#define syscall_linux_x64_pidfd_open 434
#define syscall_linux_x64_clone3 435
#define syscall_linux_x64_close_range 436
#define syscall_linux_x64_openat2 437
#define syscall_linux_x64_pidfd_getfd 438
#define syscall_linux_x64_faccessat2 439
#define syscall_linux_x64_process_madvise 440
#define syscall_linux_x64_epoll_pwait2 441
#define syscall_linux_x64_mount_setattr 442
#define syscall_linux_x64_quotactl_fd 443
#define syscall_linux_x64_landlock_create_ruleset 444
#define syscall_linux_x64_landlock_add_rule 445
#define syscall_linux_x64_landlock_restrict_self 446
#define syscall_linux_x64_memfd_secret 447
#define syscall_linux_x64_process_mrelease 448
#define syscall_linux_x64_futex_waitv 449
#define syscall_linux_x64_set_mempolicy_home_node 450
#define syscall_linux_x64_cachestat 451
#define syscall_linux_x64_fchmodat2 452
#define syscall_linux_x64_map_shadow_stack 453
#define syscall_linux_x64_futex_wake 454
#define syscall_linux_x64_futex_wait 455
#define syscall_linux_x64_futex_requeue 456
#define syscall_linux_x64_statmount 457
#define syscall_linux_x64_listmount 458
#define syscall_linux_x64_lsm_get_self_attr 459
#define syscall_linux_x64_lsm_set_self_attr 460
#define syscall_linux_x64_lsm_list_modules 461
#define syscall_linux_x64_mseal 462
#define syscall_linux_x64_setxattrat 463
#define syscall_linux_x64_getxattrat 464
#define syscall_linux_x64_listxattrat 465
#define syscall_linux_x64_removexattrat 466

#define syscall_linux_arm64_io_setup 0
#define syscall_linux_arm64_io_destroy 1
#define syscall_linux_arm64_io_submit 2
#define syscall_linux_arm64_io_cancel 3
#define syscall_linux_arm64_io_getevents 4
#define syscall_linux_arm64_setxattr 5
#define syscall_linux_arm64_lsetxattr 6
#define syscall_linux_arm64_fsetxattr 7
#define syscall_linux_arm64_getxattr 8
#define syscall_linux_arm64_lgetxattr 9
#define syscall_linux_arm64_fgetxattr 10
#define syscall_linux_arm64_listxattr 11
#define syscall_linux_arm64_llistxattr 12
#define syscall_linux_arm64_flistxattr 13
#define syscall_linux_arm64_removexattr 14
#define syscall_linux_arm64_lremovexattr 15
#define syscall_linux_arm64_fremovexattr 16
#define syscall_linux_arm64_getcwd 17
#define syscall_linux_arm64_lookup_dcookie 18
#define syscall_linux_arm64_eventfd2 19
#define syscall_linux_arm64_epoll_create1 20
#define syscall_linux_arm64_epoll_ctl 21
#define syscall_linux_arm64_epoll_pwait 22
#define syscall_linux_arm64_dup 23
#define syscall_linux_arm64_dup3 24
#define syscall_linux_arm64_fcntl 25
#define syscall_linux_arm64_inotify_init1 26
#define syscall_linux_arm64_inotify_add_watch 27
#define syscall_linux_arm64_inotify_rm_watch 28
#define syscall_linux_arm64_ioctl 29
#define syscall_linux_arm64_ioprio_set 30
#define syscall_linux_arm64_ioprio_get 31
#define syscall_linux_arm64_flock 32
#define syscall_linux_arm64_mknodat 33
#define syscall_linux_arm64_mkdirat 34
#define syscall_linux_arm64_unlinkat 35
#define syscall_linux_arm64_symlinkat 36
#define syscall_linux_arm64_linkat 37
#define syscall_linux_arm64_renameat 38
#define syscall_linux_arm64_umount2 39
#define syscall_linux_arm64_mount 40
#define syscall_linux_arm64_pivot_root 41
#define syscall_linux_arm64_nfsservctl 42
#define syscall_linux_arm64_statfs 43
#define syscall_linux_arm64_fstatfs 44
#define syscall_linux_arm64_truncate 45
#define syscall_linux_arm64_ftruncate 46
#define syscall_linux_arm64_fallocate 47
#define syscall_linux_arm64_faccessat 48
#define syscall_linux_arm64_chdir 49
#define syscall_linux_arm64_fchdir 50
#define syscall_linux_arm64_chroot 51
#define syscall_linux_arm64_fchmod 52
#define syscall_linux_arm64_fchmodat 53
#define syscall_linux_arm64_fchownat 54
#define syscall_linux_arm64_fchown 55
#define syscall_linux_arm64_openat 56
#define syscall_linux_arm64_close 57
#define syscall_linux_arm64_vhangup 58
#define syscall_linux_arm64_pipe2 59
#define syscall_linux_arm64_quotactl 60
#define syscall_linux_arm64_getdents64 61
#define syscall_linux_arm64_lseek 62
#define syscall_linux_arm64_read 63
#define syscall_linux_arm64_write 64
#define syscall_linux_arm64_readv 65
#define syscall_linux_arm64_writev 66
#define syscall_linux_arm64_pread64 67
#define syscall_linux_arm64_pwrite64 68
#define syscall_linux_arm64_preadv 69
#define syscall_linux_arm64_pwritev 70
#define syscall_linux_arm64_sendfile 71
#define syscall_linux_arm64_pselect6 72
#define syscall_linux_arm64_ppoll 73
#define syscall_linux_arm64_signalfd4 74
#define syscall_linux_arm64_vmsplice 75
#define syscall_linux_arm64_splice 76
#define syscall_linux_arm64_tee 77
#define syscall_linux_arm64_readlinkat 78
#define syscall_linux_arm64_newfstatat 79
#define syscall_linux_arm64_fstat 80
#define syscall_linux_arm64_sync 81
#define syscall_linux_arm64_fsync 82
#define syscall_linux_arm64_fdatasync 83
#define syscall_linux_arm64_sync_file_range 84
#define syscall_linux_arm64_timerfd_create 85
#define syscall_linux_arm64_timerfd_settime 86
#define syscall_linux_arm64_timerfd_gettime 87
#define syscall_linux_arm64_utimensat 88
#define syscall_linux_arm64_acct 89
#define syscall_linux_arm64_capget 90
#define syscall_linux_arm64_capset 91
#define syscall_linux_arm64_personality 92
#define syscall_linux_arm64_exit 93
#define syscall_linux_arm64_exit_group 94
#define syscall_linux_arm64_waitid 95
#define syscall_linux_arm64_set_tid_address 96
#define syscall_linux_arm64_unshare 97
#define syscall_linux_arm64_futex 98
#define syscall_linux_arm64_set_robust_list 99
#define syscall_linux_arm64_get_robust_list 100
#define syscall_linux_arm64_nanosleep 101
#define syscall_linux_arm64_getitimer 102
#define syscall_linux_arm64_setitimer 103
#define syscall_linux_arm64_kexec_load 104
#define syscall_linux_arm64_init_module 105
#define syscall_linux_arm64_delete_module 106
#define syscall_linux_arm64_timer_create 107
#define syscall_linux_arm64_timer_gettime 108
#define syscall_linux_arm64_timer_getoverrun 109
#define syscall_linux_arm64_timer_settime 110
#define syscall_linux_arm64_timer_delete 111
#define syscall_linux_arm64_clock_settime 112
#define syscall_linux_arm64_clock_gettime 113
#define syscall_linux_arm64_clock_getres 114
#define syscall_linux_arm64_clock_nanosleep 115
#define syscall_linux_arm64_syslog 116
#define syscall_linux_arm64_ptrace 117
#define syscall_linux_arm64_sched_setparam 118
#define syscall_linux_arm64_sched_setscheduler 119
#define syscall_linux_arm64_sched_getscheduler 120
#define syscall_linux_arm64_sched_getparam 121
#define syscall_linux_arm64_sched_setaffinity 122
#define syscall_linux_arm64_sched_getaffinity 123
#define syscall_linux_arm64_sched_yield 124
#define syscall_linux_arm64_sched_get_priority_max 125
#define syscall_linux_arm64_sched_get_priority_min 126
#define syscall_linux_arm64_sched_rr_get_interval 127
#define syscall_linux_arm64_restart_syscall 128
#define syscall_linux_arm64_kill 129
#define syscall_linux_arm64_tkill 130
#define syscall_linux_arm64_tgkill 131
#define syscall_linux_arm64_sigaltstack 132
#define syscall_linux_arm64_rt_sigsuspend 133
#define syscall_linux_arm64_rt_sigaction 134
#define syscall_linux_arm64_rt_sigprocmask 135
#define syscall_linux_arm64_rt_sigpending 136
#define syscall_linux_arm64_rt_sigtimedwait 137
#define syscall_linux_arm64_rt_sigqueueinfo 138
#define syscall_linux_arm64_rt_sigreturn 139
#define syscall_linux_arm64_setpriority 140
#define syscall_linux_arm64_getpriority 141
#define syscall_linux_arm64_reboot 142
#define syscall_linux_arm64_setregid 143
#define syscall_linux_arm64_setgid 144
#define syscall_linux_arm64_setreuid 145
#define syscall_linux_arm64_setuid 146
#define syscall_linux_arm64_setresuid 147
#define syscall_linux_arm64_getresuid 148
#define syscall_linux_arm64_setresgid 149
#define syscall_linux_arm64_getresgid 150
#define syscall_linux_arm64_setfsuid 151
#define syscall_linux_arm64_setfsgid 152
#define syscall_linux_arm64_times 153
#define syscall_linux_arm64_setpgid 154
#define syscall_linux_arm64_getpgid 155
#define syscall_linux_arm64_getsid 156
#define syscall_linux_arm64_setsid 157
#define syscall_linux_arm64_getgroups 158
#define syscall_linux_arm64_setgroups 159
#define syscall_linux_arm64_uname 160
#define syscall_linux_arm64_sethostname 161
#define syscall_linux_arm64_setdomainname 162
#define syscall_linux_arm64_getrlimit 163
#define syscall_linux_arm64_setrlimit 164
#define syscall_linux_arm64_getrusage 165
#define syscall_linux_arm64_umask 166
#define syscall_linux_arm64_prctl 167
#define syscall_linux_arm64_getcpu 168
#define syscall_linux_arm64_gettimeofday 169
#define syscall_linux_arm64_settimeofday 170
#define syscall_linux_arm64_adjtimex 171
#define syscall_linux_arm64_getpid 172
#define syscall_linux_arm64_getppid 173
#define syscall_linux_arm64_getuid 174
#define syscall_linux_arm64_geteuid 175
#define syscall_linux_arm64_getgid 176
#define syscall_linux_arm64_getegid 177
#define syscall_linux_arm64_gettid 178
#define syscall_linux_arm64_sysinfo 179
#define syscall_linux_arm64_mq_open 180
#define syscall_linux_arm64_mq_unlink 181
#define syscall_linux_arm64_mq_timedsend 182
#define syscall_linux_arm64_mq_timedreceive 183
#define syscall_linux_arm64_mq_notify 184
#define syscall_linux_arm64_mq_getsetattr 185
#define syscall_linux_arm64_msgget 186
#define syscall_linux_arm64_msgctl 187
#define syscall_linux_arm64_msgrcv 188
#define syscall_linux_arm64_msgsnd 189
#define syscall_linux_arm64_semget 190
#define syscall_linux_arm64_semctl 191
#define syscall_linux_arm64_semtimedop 192
#define syscall_linux_arm64_semop 193
#define syscall_linux_arm64_shmget 194
#define syscall_linux_arm64_shmctl 195
#define syscall_linux_arm64_shmat 196
#define syscall_linux_arm64_shmdt 197
#define syscall_linux_arm64_socket 198
#define syscall_linux_arm64_socketpair 199
#define syscall_linux_arm64_bind 200
#define syscall_linux_arm64_listen 201
#define syscall_linux_arm64_accept 202
#define syscall_linux_arm64_connect 203
#define syscall_linux_arm64_getsockname 204
#define syscall_linux_arm64_getpeername 205
#define syscall_linux_arm64_sendto 206
#define syscall_linux_arm64_recvfrom 207
#define syscall_linux_arm64_setsockopt 208
#define syscall_linux_arm64_getsockopt 209
#define syscall_linux_arm64_shutdown 210
#define syscall_linux_arm64_sendmsg 211
#define syscall_linux_arm64_recvmsg 212
#define syscall_linux_arm64_readahead 213
#define syscall_linux_arm64_brk 214
#define syscall_linux_arm64_munmap 215
#define syscall_linux_arm64_mremap 216
#define syscall_linux_arm64_add_key 217
#define syscall_linux_arm64_request_key 218
#define syscall_linux_arm64_keyctl 219
#define syscall_linux_arm64_clone 220
#define syscall_linux_arm64_execve 221
#define syscall_linux_arm64_mmap 222
#define syscall_linux_arm64_fadvise64 223
#define syscall_linux_arm64_swapon 224
#define syscall_linux_arm64_swapoff 225
#define syscall_linux_arm64_mprotect 226
#define syscall_linux_arm64_msync 227
#define syscall_linux_arm64_mlock 228
#define syscall_linux_arm64_munlock 229
#define syscall_linux_arm64_mlockall 230
#define syscall_linux_arm64_munlockall 231
#define syscall_linux_arm64_mincore 232
#define syscall_linux_arm64_madvise 233
#define syscall_linux_arm64_remap_file_pages 234
#define syscall_linux_arm64_mbind 235
#define syscall_linux_arm64_get_mempolicy 236
#define syscall_linux_arm64_set_mempolicy 237
#define syscall_linux_arm64_migrate_pages 238
#define syscall_linux_arm64_move_pages 239
#define syscall_linux_arm64_rt_tgsigqueueinfo 240
#define syscall_linux_arm64_perf_event_open 241
#define syscall_linux_arm64_accept4 242
#define syscall_linux_arm64_recvmmsg 243
#define syscall_linux_arm64_wait4 260
#define syscall_linux_arm64_prlimit64 261
#define syscall_linux_arm64_fanotify_init 262
#define syscall_linux_arm64_fanotify_mark 263
#define syscall_linux_arm64_name_to_handle_at 264
#define syscall_linux_arm64_open_by_handle_at 265
#define syscall_linux_arm64_clock_adjtime 266
#define syscall_linux_arm64_syncfs 267
#define syscall_linux_arm64_setns 268
#define syscall_linux_arm64_sendmmsg 269
#define syscall_linux_arm64_process_vm_readv 270
#define syscall_linux_arm64_process_vm_writev 271
#define syscall_linux_arm64_kcmp 272
#define syscall_linux_arm64_finit_module 273
#define syscall_linux_arm64_sched_setattr 274
#define syscall_linux_arm64_sched_getattr 275
#define syscall_linux_arm64_renameat2 276
#define syscall_linux_arm64_seccomp 277
#define syscall_linux_arm64_getrandom 278
#define syscall_linux_arm64_memfd_create 279
#define syscall_linux_arm64_bpf 280
#define syscall_linux_arm64_execveat 281
#define syscall_linux_arm64_userfaultfd 282
#define syscall_linux_arm64_membarrier 283
#define syscall_linux_arm64_mlock2 284
#define syscall_linux_arm64_copy_file_range 285
#define syscall_linux_arm64_preadv2 286
#define syscall_linux_arm64_pwritev2 287
#define syscall_linux_arm64_pkey_mprotect 288
#define syscall_linux_arm64_pkey_alloc 289
#define syscall_linux_arm64_pkey_free 290
#define syscall_linux_arm64_statx 291
#define syscall_linux_arm64_io_pgetevents 292
#define syscall_linux_arm64_rseq 293
#define syscall_linux_arm64_kexec_file_load 294
#define syscall_linux_arm64_pidfd_send_signal 424
#define syscall_linux_arm64_io_uring_setup 425
#define syscall_linux_arm64_io_uring_enter 426
#define syscall_linux_arm64_io_uring_register 427
#define syscall_linux_arm64_open_tree 428
#define syscall_linux_arm64_move_mount 429
#define syscall_linux_arm64_fsopen 430
#define syscall_linux_arm64_fsconfig 431
#define syscall_linux_arm64_fsmount 432
#define syscall_linux_arm64_fspick 433
#define syscall_linux_arm64_pidfd_open 434
#define syscall_linux_arm64_clone3 435
#define syscall_linux_arm64_close_range 436
#define syscall_linux_arm64_openat2 437
#define syscall_linux_arm64_pidfd_getfd 438
#define syscall_linux_arm64_faccessat2 439
#define syscall_linux_arm64_process_madvise 440
#define syscall_linux_arm64_epoll_pwait2 441
#define syscall_linux_arm64_mount_setattr 442
#define syscall_linux_arm64_quotactl_fd 443
#define syscall_linux_arm64_landlock_create_ruleset 444
#define syscall_linux_arm64_landlock_add_rule 445
#define syscall_linux_arm64_landlock_restrict_self 446
#define syscall_linux_arm64_memfd_secret 447
#define syscall_linux_arm64_process_mrelease 448
#define syscall_linux_arm64_futex_waitv 449
#define syscall_linux_arm64_set_mempolicy_home_node 450
#define syscall_linux_arm64_cachestat 451
#define syscall_linux_arm64_fchmodat2 452
#define syscall_linux_arm64_map_shadow_stack 453
#define syscall_linux_arm64_futex_wake 454
#define syscall_linux_arm64_futex_wait 455
#define syscall_linux_arm64_futex_requeue 456
#define syscall_linux_arm64_statmount 457
#define syscall_linux_arm64_listmount 458
#define syscall_linux_arm64_lsm_get_self_attr 459
#define syscall_linux_arm64_lsm_set_self_attr 460
#define syscall_linux_arm64_lsm_list_modules 461
#define syscall_linux_arm64_mseal 462
#define syscall_linux_arm64_setxattrat 463
#define syscall_linux_arm64_getxattrat 464
#define syscall_linux_arm64_listxattrat 465
#define syscall_linux_arm64_removexattrat 466

// Macos

#define syscall_macos_arm64_indirect 0x0
#define syscall_macos_arm64_exit 0x1
#define syscall_macos_arm64_fork 0x2
#define syscall_macos_arm64_read 0x3
#define syscall_macos_arm64_write 0x4
#define syscall_macos_arm64_open 0x5
#define syscall_macos_arm64_close 0x6
#define syscall_macos_arm64_wait4 0x7
#define syscall_macos_arm64_creat 0x8 // Deprecated
#define syscall_macos_arm64_link 0x9
#define syscall_macos_arm64_unlink 0xa
// #define syscall_macos_arm64_execve 0xb // Deprecated
#define syscall_macos_arm64_chdir 0xc
#define syscall_macos_arm64_fchdir 0xd
#define syscall_macos_arm64_mknod 0xe
#define syscall_macos_arm64_chmod 0xf
#define syscall_macos_arm64_chown 0x10
#define syscall_macos_arm64_break 0x11 // Deprecated
#define syscall_macos_arm64_getfsstat 0x12
#define syscall_macos_arm64_lseek 0x13 // Deprecated
#define syscall_macos_arm64_getpid 0x14
// #define syscall_macos_arm64_mount 0x15 // Deprecated
// #define syscall_macos_arm64_unmount 0x16 // Deprecated
#define syscall_macos_arm64_setuid 0x17
#define syscall_macos_arm64_getuid 0x18
#define syscall_macos_arm64_geteuid 0x19
#define syscall_macos_arm64_ptrace 0x1a
#define syscall_macos_arm64_recvmsg 0x1b
#define syscall_macos_arm64_sendmsg 0x1c
#define syscall_macos_arm64_recvfrom 0x1d
#define syscall_macos_arm64_accept 0x1e
#define syscall_macos_arm64_getpeername 0x1f
#define syscall_macos_arm64_getsockname 0x20
#define syscall_macos_arm64_access 0x21
#define syscall_macos_arm64_chflags 0x22
#define syscall_macos_arm64_fchflags 0x23
#define syscall_macos_arm64_sync 0x24
#define syscall_macos_arm64_kill 0x25
#define syscall_macos_arm64_getppid 0x27
#define syscall_macos_arm64_lstat 0x28
#define syscall_macos_arm64_dup 0x29
#define syscall_macos_arm64_pipe 0x2a
#define syscall_macos_arm64_getegid 0x2b
#define syscall_macos_arm64_profil 0x2c // Deprecated
#define syscall_macos_arm64_ktrace 0x2d // Deprecated
#define syscall_macos_arm64_sigaction 0x2e
#define syscall_macos_arm64_getgid 0x2f
#define syscall_macos_arm64_sigprocmask 0x30
#define syscall_macos_arm64_getlogin 0x31
#define syscall_macos_arm64_setlogin 0x32
#define syscall_macos_arm64_acct 0x33
#define syscall_macos_arm64_sigpending 0x34
#define syscall_macos_arm64_sigaltstack 0x35
#define syscall_macos_arm64_ioctl 0x36
#define syscall_macos_arm64_reboot 0x37
#define syscall_macos_arm64_revoke 0x38
#define syscall_macos_arm64_symlink 0x39
#define syscall_macos_arm64_readlink 0x3a
#define syscall_macos_arm64_execve 0x3b
#define syscall_macos_arm64_umask 0x3c
#define syscall_macos_arm64_chroot 0x3d
#define syscall_macos_arm64_fstat 0x3e       // Deprecated
#define syscall_macos_arm64_reserved_0 0x3f  // Reserved
#define syscall_macos_arm64_getpagesize 0x40 // Deprecated
#define syscall_macos_arm64_msync 0x41
#define syscall_macos_arm64_vfork 0x42
#define syscall_macos_arm64_vread 0x43   // Deprecated
#define syscall_macos_arm64_vwrite 0x44  // Deprecated
#define syscall_macos_arm64_sbrk 0x45    // Deprecated
#define syscall_macos_arm64_sstk 0x46    // Deprecated
#define syscall_macos_arm64_mmap 0x47    // Deprecated
#define syscall_macos_arm64_vadvise 0x48 // Deprecated
#define syscall_macos_arm64_munmap 0x49
#define syscall_macos_arm64_mprotect 0x4a
#define syscall_macos_arm64_vhangup 0x4b // Deprecated
#define syscall_macos_arm64_vlimit 0x4c  // Deprecated
#define syscall_macos_arm64_madvise 0x4d
#define syscall_macos_arm64_mincore 0x4e
#define syscall_macos_arm64_getgroups 0x4f
#define syscall_macos_arm64_setgroups 0x50
#define syscall_macos_arm64_getpgrp 0x51
#define syscall_macos_arm64_setpgid 0x52
#define syscall_macos_arm64_setitimer 0x53
#define syscall_macos_arm64_wait 0x54 // Deprecated
#define syscall_macos_arm64_swapon 0x55
#define syscall_macos_arm64_getitimer 0x56
#define syscall_macos_arm64_gethostname 0x57 // Deprecated
#define syscall_macos_arm64_sethostname 0x58 // Deprecated
#define syscall_macos_arm64_getdtablesize 0x59
#define syscall_macos_arm64_dup2 0x5a
#define syscall_macos_arm64_getdoprt 0x5b // Deprecated
#define syscall_macos_arm64_fcntl 0x5c
#define syscall_macos_arm64_select 0x5d
#define syscall_macos_arm64_setdopt 0x5e // Deprecated
#define syscall_macos_arm64_fsync 0x5f
#define syscall_macos_arm64_setpriority 0x60
#define syscall_macos_arm64_socket 0x61
#define syscall_macos_arm64_connect 0x62
#define syscall_macos_arm64_accept 0x63 // Deprecated
#define syscall_macos_arm64_getpriority 0x64
#define syscall_macos_arm64_send 0x65      // Deprecated
#define syscall_macos_arm64_receive 0x66   // Deprecated
#define syscall_macos_arm64_sigreturn 0x67 // Deprecated
#define syscall_macos_arm64_bind 0x68
#define syscall_macos_arm64_setsockopt 0x69
#define syscall_macos_arm64_listen 0x6a
#define syscall_macos_arm64_vtimes 0x6b  // Deprecated
#define syscall_macos_arm64_sigvec 0x6c  // Deprecated
#define syscall_macos_arm64_recvmsg 0x6d // Deprecated
#define syscall_macos_arm64_vtrace 0x6e  // Deprecated
#define syscall_macos_arm64_sigsuspend 0x6f4
#define syscall_macos_arm64_gettimeofday 0x74
#define syscall_macos_arm64_getrusage 0x75
#define syscall_macos_arm64_getsockopt 0x76
#define syscall_macos_arm64_resuba 0x77 // Deprecated
#define syscall_macos_arm64_readv 0x78
#define syscall_macos_arm64_writev 0x79
#define syscall_macos_arm64_settimeofday 0x7a
#define syscall_macos_arm64_fchown 0x7b
#define syscall_macos_arm64_fchmod 0x7c
#define syscall_macos_arm64_recvfrom 0x7d // Deprecated
#define syscall_macos_arm64_setreuid 0x7e
#define syscall_macos_arm64_setregid 0x7f
#define syscall_macos_arm64_rename 0x80
#define syscall_macos_arm64_truncate 0x81  // Deprecated
#define syscall_macos_arm64_ftruncate 0x82 // Deprecated
#define syscall_macos_arm64_flock 0x83
#define syscall_macos_arm64_mkfifo 0x84
#define syscall_macos_arm64_sendto 0x85
#define syscall_macos_arm64_shutdown 0x86
#define syscall_macos_arm64_socketpair 0x87
#define syscall_macos_arm64_mkdir 0x88
#define syscall_macos_arm64_rmdir 0x89
#define syscall_macos_arm64_utimes 0x8a
#define syscall_macos_arm64_futimes 0x8b
#define syscall_macos_arm64_adjtime 0x8c
#define syscall_macos_arm64_getpeername 0x8d // Deprecated
#define syscall_macos_arm64_gethostid 0x8e
#define syscall_macos_arm64_sethostid 0x8f // Deprecated
#define syscall_macos_arm64_getrlimit 0x90 // Deprecated
#define syscall_macos_arm64_setrlimit 0x91 // Deprecated
#define syscall_macos_arm64_killpg 0x92    // Deprecated
#define syscall_macos_arm64_setsid 0x93
#define syscall_macos_arm64_setquota 0x94    // Deprecated
#define syscall_macos_arm64_qquota 0x95      // Deprecated
#define syscall_macos_arm64_getsockname 0x96 // Deprecated
#define syscall_macos_arm64_getpgid 0x97
#define syscall_macos_arm64_setprivexec 0x98
#define syscall_macos_arm64_pread 0x99
#define syscall_macos_arm64_pwrite 0x9a
#define syscall_macos_arm64_nfssvc 0x9b
#define syscall_macos_arm64_getdirentries 0x9c // Deprecated
#define syscall_macos_arm64_statfs 0x9d
#define syscall_macos_arm64_fstatfs 0x9e
#define syscall_macos_arm64_unmount 0x9f
#define syscall_macos_arm64_async_daemon 0xa0 // Deprecated
#define syscall_macos_arm64_getfh 0xa1
#define syscall_macos_arm64_getdomainname 0xa2 // Deprecated
#define syscall_macos_arm64_setdomainname 0xa3 // Deprecated
#define syscall_macos_arm64_reserved_1 0xa4
#define syscall_macos_arm64_quotactl 0xa5
#define syscall_macos_arm64_exportfs 0xa6 // Deprecated
#define syscall_macos_arm64_mount 0xa7
#define syscall_macos_arm64_ustat 0xa8 // Deprecated
#define syscall_macos_arm64_csops 0xa9
#define syscall_macos_arm64_csops_audittoken 0xaa
#define syscall_macos_arm64_wait3 0xab  // Deprecated
#define syscall_macos_arm64_rpause 0xac // Deprecated
#define syscall_macos_arm64_waitid 0xad
#define syscall_macos_arm64_getdents 0xae    // Deprecated
#define syscall_macos_arm64_gc_control 0xaf  // Deprecated
#define syscall_macos_arm64_add_profill 0xb0 // Deprecated
#define syscall_macos_arm64_kdebug_typefilter 0xb1
#define syscall_macos_arm64_kdebug_trace_string 0xb2
#define syscall_macos_arm64_kdebug_trace64 0xb3
#define syscall_macos_arm64_kdebug_trace 0xb4
#define syscall_macos_arm64_setgid 0xb5
#define syscall_macos_arm64_setegid 0xb6
#define syscall_macos_arm64_seteuid 0xb7
#define syscall_macos_arm64_sigreturn 0xb8
#define syscall_macos_arm64_thread_selfcounts 0xba
#define syscall_macos_arm64_fdatasync 0xbb
#define syscall_macos_arm64_stat 0xbc
#define syscall_macos_arm64_fstat 0xbd
#define syscall_macos_arm64_lstat 0xbe
#define syscall_macos_arm64_pathconf 0xbf
#define syscall_macos_arm64_fpathconf 0xc0
#define syscall_macos_arm64_getfsstat 0xc1 // Deprecated
#define syscall_macos_arm64_getrlimit 0xc2
#define syscall_macos_arm64_setrlimit 0xc3
#define syscall_macos_arm64_getdirentries 0xc4
#define syscall_macos_arm64_mmap 0xc5
#define syscall_macos_arm64___syscall 0xc6 // Deprecated
#define syscall_macos_arm64_lseek 0xc7
#define syscall_macos_arm64_truncate 0xc8
#define syscall_macos_arm64_ftruncate 0xc9
#define syscall_macos_arm64_sysctl 0xca
#define syscall_macos_arm64_mlock 0xcb
#define syscall_macos_arm64_munlock 0xcc
#define syscall_macos_arm64_undelete 0xcd
// ...Deprecated & Reserved...
#define syscall_macos_arm64_open_dprotected_np 0xd8
#define syscall_macos_arm64_fsgetpath_ext 0xd9
#define syscall_macos_arm64_openat_dprotected_np 0xda
// #define syscall_macos_arm64_fstat 0xdb // Deprecated
#define syscall_macos_arm64_getattrlist 0xdc
#define syscall_macos_arm64_setattrlist 0xdd
#define syscall_macos_arm64_getdirentriesattr 0xde
#define syscall_macos_arm64_exchangedata 0xdf
#define syscall_macos_arm64_searchfs 0xe1
#define syscall_macos_arm64_delete 0xe2
#define syscall_macos_arm64_copyfile 0xe3
#define syscall_macos_arm64_fgetattrlist 0xe4
#define syscall_macos_arm64_fsetattrlist 0xe5
#define syscall_macos_arm64_poll 0xe6
#define syscall_macos_arm64_watchevent 0xe7 // Deprecated
#define syscall_macos_arm64_waitevent 0xe8  // Deprecated
#define syscall_macos_arm64_modwatch 0xe9   // Deprecated
#define syscall_macos_arm64_getxattr 0xea
#define syscall_macos_arm64_fgetxattr 0xeb
#define syscall_macos_arm64_setxattr 0xec
#define syscall_macos_arm64_fsetxattr 0xed
#define syscall_macos_arm64_removexattr 0xee
#define syscall_macos_arm64_fremovexattr 0xef
#define syscall_macos_arm64_listxattr 0xf0
#define syscall_macos_arm64_flistxattr 0xf1
#define syscall_macos_arm64_fsctl 0xf2
#define syscall_macos_arm64_initgroups 0xf3
#define syscall_macos_arm64_posix_spawn 0xf4
#define syscall_macos_arm64_ffsctl 0xf5
#define syscall_macos_arm64_reserved_2 0xf6
#define syscall_macos_arm64_nfsclnt 0xf7 // Deprecated
#define syscall_macos_arm64_fhopen 0xf8
#define syscall_macos_arm64_reserved_3 0xf9
#define syscall_macos_arm64_minherit 0xfa
#define syscall_macos_arm64_semsys 0xfb
#define syscall_macos_arm64_msgsys 0xfc
#define syscall_macos_arm64_shmsys 0xfd
#define syscall_macos_arm64_semctl 0xfe
#define syscall_macos_arm64_semget 0xff
#define syscall_macos_arm64_semop 0x100
#define syscall_macos_arm64_semconfig 0x101 // Deprecated
#define syscall_macos_arm64_msgctl 0x102
#define syscall_macos_arm64_msgget 0x103
#define syscall_macos_arm64_msgsnd 0x104
#define syscall_macos_arm64_msgrcv 0x105
#define syscall_macos_arm64_shmat 0x106
#define syscall_macos_arm64_shmctl 0x107
#define syscall_macos_arm64_shmdt 0x108
#define syscall_macos_arm64_shmget 0x109
#define syscall_macos_arm64_shm_open 0x10a
#define syscall_macos_arm64_shm_unlink 0x10b
#define syscall_macos_arm64_sem_open 0x10c
#define syscall_macos_arm64_sem_close 0x10d
#define syscall_macos_arm64_sem_unlink 0x10e
#define syscall_macos_arm64_sem_wait 0x10f
#define syscall_macos_arm64_sem_trywait 0x110
#define syscall_macos_arm64_sem_post 0x111
#define syscall_macos_arm64_sysctlbyname 0x112
#define syscall_macos_arm64_sem_init 0x113    // Deprecated
#define syscall_macos_arm64_sem_destroy 0x114 // Deprecated
#define syscall_macos_arm64_open_extended 0x115
#define syscall_macos_arm64_umask_extended 0x116
#define syscall_macos_arm64_stat_extended 0x117
#define syscall_macos_arm64_lstat_extended 0x118
#define syscall_macos_arm64_fstat_extended 0x119
#define syscall_macos_arm64_chmod_extended 0x11a
#define syscall_macos_arm64_fchmod_extended 0x11b
#define syscall_macos_arm64_access_extended 0x11c
#define syscall_macos_arm64_settid 0x11d
#define syscall_macos_arm64_gettid 0x11e
#define syscall_macos_arm64_setsgroups 0x11f
#define syscall_macos_arm64_getsgroups 0x120
#define syscall_macos_arm64_setwgroups 0x121
#define syscall_macos_arm64_getwgroups 0x122
#define syscall_macos_arm64_mkfifo_extended 0x123
#define syscall_macos_arm64_mkdir_extended 0x124
#define syscall_macos_arm64_identitysvc 0x125
#define syscall_macos_arm64_shared_region_check_np 0x126
#define syscall_macos_arm64_sharedd_region_map_np 0x127
#define syscall_macos_arm64_vm_pressure_monitor 0x128
#define syscall_macos_arm64_psynch_rw_longrdlock 0x129
#define syscall_macos_arm64_psynch_rw_yieldwrlock 0x12a
#define syscall_macos_arm64_psynch_rw_downgrade 0x12b
#define syscall_macos_arm64_psynch_rw_upgrade 0x12c
#define syscall_macos_arm64_psynch_mutexwait 0x12d
#define syscall_macos_arm64_psynch_mutexdrop 0x12e
#define syscall_macos_arm64_psynch_cvbroad 0x12f
#define syscall_macos_arm64_psynch_cvsignal 0x130
#define syscall_macos_arm64_psynch_cvwait 0x131
#define syscall_macos_arm64_psynch_rw_rdlock 0x132
#define syscall_macos_arm64_psynch_rw_wrlock 0x133
#define syscall_macos_arm64_psynch_rw_unlock 0x134
#define syscall_macos_arm64_psynch_rw_unlock2 0x135
#define syscall_macos_arm64_getsid 0x136
#define syscall_macos_arm64_settid_with_pid 0x137
#define syscall_macos_arm64_psynch_cvclrprepost 0x138
#define syscall_macos_arm64_aio_fsync 0x139
#define syscall_macos_arm64_aio_return 0x13a
#define syscall_macos_arm64_aio_suspend 0x13b
#define syscall_macos_arm64_aio_cancel 0x13c
#define syscall_macos_arm64_aio_error 0x13d
#define syscall_macos_arm64_aio_read 0x13e
#define syscall_macos_arm64_aio_write 0x13f
#define syscall_macos_arm64_lio_listio 0x140
#define syscall_macos_arm64___pthread_cond_wait 0x141 // Deprecated
#define syscall_macos_arm64_iopolicysys 0x142
#define syscall_macos_arm64_process_policy 0x143
#define syscall_macos_arm64_mlockall 0x144
#define syscall_macos_arm64_munlockall 0x145
#define syscall_macos_arm64_reserved_4 0x146
#define syscall_macos_arm64_issetugid 0x147
#define syscall_macos_arm64___pthread_kill 0x148
#define syscall_macos_arm64___pthread_sigmask 0x149
#define syscall_macos_arm64___sigwait 0x14a
#define syscall_macos_arm64___disable_threadsignal 0x14b
#define syscall_macos_arm64___pthread_markcancel 0x14c
#define syscall_macos_arm64___pthread_canceled 0x14d
#define syscall_macos_arm64___semwait_signal 0x14e
#define syscall_macos_arm64_utrace 0x14f // Deprecated
#define syscall_macos_arm64_proc_info 0x150
#define syscall_macos_arm64_sendfile 0x151
#define syscall_macos_arm64_stat64 0x152
#define syscall_macos_arm64_fstat64 0x153
#define syscall_macos_arm64_lstat64 0x154
#define syscall_macos_arm64_stat64_extended 0x155
#define syscall_macos_arm64_fstat64_extended 0x156
#define syscall_macos_arm64_lstat64_extended 0x157
#define syscall_macos_arm64_getdirentries64 0x158
#define syscall_macos_arm64_statfs64 0x159
#define syscall_macos_arm64_fstatfs64 0x15a
#define syscall_macos_arm64_getfsstat64 0x15b
#define syscall_macos_arm64___pthread_chdir 0x15c
#define syscall_macos_arm64___pthread_fchdir 0x15d
#define syscall_macos_arm64_audit 0x15e
#define syscall_macos_arm64_auditon 0x15f
#define syscall_macos_arm64_reserved_5 0x160
#define syscall_macos_arm64_getauid 0x161
#define syscall_macos_arm64_setauid 0x162
#define syscall_macos_arm64_getaudit 0x163 // Deprecated
#define syscall_macos_arm64_setaudit 0x164 // Deprecated
#define syscall_macos_arm64_getaudit_addr 0x165
#define syscall_macos_arm64_setaudit_addr 0x166
#define syscall_macos_arm64_auditctl 0x167
#define syscall_macos_arm64_bsdthread_create 0x168
#define syscall_macos_arm64_bsdthread_terminate 0x169
#define syscall_macos_arm64_kqueue 0x16a
#define syscall_macos_arm64_kevent 0x16b
#define syscall_macos_arm64_lchown 0x16c
#define syscall_macos_arm64_stack_snapshot 0x16d // Deprecated
#define syscall_macos_arm64_bsdthread_register 0x16e
#define syscall_macos_arm64_workq_open 0x16f
#define syscall_macos_arm64_workq_kernreturn 0x170
#define syscall_macos_arm64_kevent64 0x171
#define syscall_macos_arm64___old_semwait_signal 0x172          // Deprecated
#define syscall_macos_arm64___old_semwait_signal_nocancel 0x173 // Deprecated
#define syscall_macos_arm64_thread_selfid 0x174
#define syscall_macos_arm64_ledger 0x175
#define syscall_macos_arm64_kevent_qos 0x176
#define syscall_macos_arm64_kevent_id 0x177
// ...Reserved...
#define syscall_macos_arm64___mac_execve 0x17c
#define syscall_macos_arm64___mac_syscall 0x17d
#define syscall_macos_arm64___mac_get_file 0x17e
#define syscall_macos_arm64___mac_set_file 0x17f
#define syscall_macos_arm64___mac_get_link 0x180
#define syscall_macos_arm64___mac_set_link 0x181
#define syscall_macos_arm64___mac_get_proc 0x182
#define syscall_macos_arm64___mac_set_proc 0x183
#define syscall_macos_arm64___mac_get_fd 0x184
#define syscall_macos_arm64___mac_set_fd 0x185
#define syscall_macos_arm64___mac_get_pid 0x186
// ...Reserved...
#define syscall_macos_arm64_pselect 0x18a
#define syscall_macos_arm64_pselect_nocancel 0x18b
#define syscall_macos_arm64_read_nocancel 0x18c
#define syscall_macos_arm64_write_nocancel 0x18d
#define syscall_macos_arm64_open_nocancel 0x18e
#define syscall_macos_arm64_close_nocancel 0x18f
#define syscall_macos_arm64_wait4_nocancel 0x190