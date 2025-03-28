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

#if defined(X64)
#define syscall_read 0
#define syscall_write 1
#define syscall_open -1 // Deprecated use openat
#define syscall_close 3
#define syscall_stat -1 // Deprecated use fstat
#define syscall_fstat 5
#define syscall_lstat -1 // Deprecated use fstat
#define syscall_poll 7
#define syscall_lseek 8
#define syscall_mmap 9
#define syscall_mprotect 10
#define syscall_munmap 11
#define syscall_brk 12
#define syscall_rt_sigaction 13
#define syscall_rt_sigprocmask 14
#define syscall_rt_sigreturn 15
#define syscall_ioctl 16
#define syscall_pread64 17
#define syscall_pwrite64 18
#define syscall_readv 19
#define syscall_writev 20
#define syscall_access 21
#define syscall_pipe 22
#define syscall_select 23
#define syscall_sched_yield 24
#define syscall_mremap 25
#define syscall_msync 26
#define syscall_mincore 27
#define syscall_madvise 28
#define syscall_shmget 29
#define syscall_shmat 30
#define syscall_shmctl 31
#define syscall_dup 32
#define syscall_dup2 33
#define syscall_pause 34
#define syscall_nanosleep 35
#define syscall_getitimer 36
#define syscall_alarm 37
#define syscall_setitimer 38
#define syscall_getpid 39
#define syscall_sendfile 40
#define syscall_socket 41
#define syscall_connect 42
#define syscall_accept 43
#define syscall_sendto 44
#define syscall_recvfrom 45
#define syscall_sendmsg 46
#define syscall_recvmsg 47
#define syscall_shutdown 48
#define syscall_bind 49
#define syscall_listen 50
#define syscall_getsockname 51
#define syscall_getpeername 52
#define syscall_socketpair 53
#define syscall_setsockopt 54
#define syscall_getsockopt 55
#define syscall_clone 56
#define syscall_fork 57
#define syscall_vfork 58
#define syscall_execve 59
#define syscall_exit 60
#define syscall_wait4 61
#define syscall_kill 62
#define syscall_uname 63
#define syscall_semget 64
#define syscall_semop 65
#define syscall_semctl 66
#define syscall_shmdt 67
#define syscall_msgget 68
#define syscall_msgsnd 69
#define syscall_msgrcv 70
#define syscall_msgctl 71
#define syscall_fcntl 72
#define syscall_flock 73
#define syscall_fsync 74
#define syscall_fdatasync 75
#define syscall_truncate 76
#define syscall_ftruncate 77
#define syscall_getdents 78
#define syscall_getcwd 79
#define syscall_chdir 80
#define syscall_fchdir 81
#define syscall_rename 82
#define syscall_mkdir 83
#define syscall_rmdir 84
#define syscall_creat 85
#define syscall_link 86
#define syscall_unlink 87
#define syscall_symlink 88
#define syscall_readlink 89
#define syscall_chmod -1 // Deprecated use fchmod
#define syscall_fchmod 91
#define syscall_chown 92
#define syscall_fchown 93
#define syscall_lchown 94
#define syscall_umask 95
#define syscall_gettimeofday 96
#define syscall_getrlimit 97
#define syscall_getrusage 98
#define syscall_sysinfo 99
#define syscall_times 100
#define syscall_ptrace 101
#define syscall_getuid 102
#define syscall_syslog 103
#define syscall_getgid 104
#define syscall_setuid 105
#define syscall_setgid 106
#define syscall_geteuid 107
#define syscall_getegid 108
#define syscall_setpgid 109
#define syscall_getppid 110
#define syscall_getpgrp 111
#define syscall_setsid 112
#define syscall_setreuid 113
#define syscall_setregid 114
#define syscall_getgroups 115
#define syscall_setgroups 116
#define syscall_setresuid 117
#define syscall_getresuid 118
#define syscall_setresgid 119
#define syscall_getresgid 120
#define syscall_getpgid 121
#define syscall_setfsuid 122
#define syscall_setfsgid 123
#define syscall_getsid 124
#define syscall_capget 125
#define syscall_capset 126
#define syscall_rt_sigpending 127
#define syscall_rt_sigtimedwait 128
#define syscall_rt_sigqueueinfo 129
#define syscall_rt_sigsuspend 130
#define syscall_sigaltstack 131
#define syscall_utime 132
#define syscall_mknod 133
#define syscall_uselib 134
#define syscall_personality 135
#define syscall_ustat 136
#define syscall_statfs 137
#define syscall_fstatfs 138
#define syscall_sysfs 139
#define syscall_getpriority 140
#define syscall_setpriority 141
#define syscall_sched_setparam 142
#define syscall_sched_getparam 143
#define syscall_sched_setscheduler 144
#define syscall_sched_getscheduler 145
#define syscall_sched_get_priority_max 146
#define syscall_sched_get_priority_min 147
#define syscall_sched_rr_get_interval 148
#define syscall_mlock 149
#define syscall_munlock 150
#define syscall_mlockall 151
#define syscall_munlockall 152
#define syscall_vhangup 153
#define syscall_modify_ldt 154
#define syscall_pivot_root 155
#define syscall__sysctl 156
#define syscall_prctl 157
#define syscall_arch_prctl 158
#define syscall_adjtimex 159
#define syscall_setrlimit 160
#define syscall_chroot 161
#define syscall_sync 162
#define syscall_acct 163
#define syscall_settimeofday 164
#define syscall_mount 165
#define syscall_umount2 166
#define syscall_swapon 167
#define syscall_swapoff 168
#define syscall_reboot 169
#define syscall_sethostname 170
#define syscall_setdomainname 171
#define syscall_iopl 172
#define syscall_ioperm 173
#define syscall_create_module 174
#define syscall_init_module 175
#define syscall_delete_module 176
#define syscall_get_kernel_syms 177
#define syscall_query_module 178
#define syscall_quotactl 179
#define syscall_nfsservctl 180
#define syscall_getpmsg 181
#define syscall_putpmsg 182
#define syscall_afs_syscall 183
#define syscall_tuxcall 184
#define syscall_security 185
#define syscall_gettid 186
#define syscall_readahead 187
#define syscall_setxattr 188
#define syscall_lsetxattr 189
#define syscall_fsetxattr 190
#define syscall_getxattr 191
#define syscall_lgetxattr 192
#define syscall_fgetxattr 193
#define syscall_listxattr 194
#define syscall_llistxattr 195
#define syscall_flistxattr 196
#define syscall_removexattr 197
#define syscall_lremovexattr 198
#define syscall_fremovexattr 199
#define syscall_tkill 200
#define syscall_time 201
#define syscall_futex 202
#define syscall_sched_setaffinity 203
#define syscall_sched_getaffinity 204
#define syscall_set_thread_area 205
#define syscall_io_setup 206
#define syscall_io_destroy 207
#define syscall_io_getevents 208
#define syscall_io_submit 209
#define syscall_io_cancel 210
#define syscall_get_thread_area 211
#define syscall_lookup_dcookie 212
#define syscall_epoll_create 213
#define syscall_epoll_ctl_old 214
#define syscall_epoll_wait_old 215
#define syscall_remap_file_pages 216
#define syscall_getdents64 217
#define syscall_set_tid_address 218
#define syscall_restart_syscall 219
#define syscall_semtimedop 220
#define syscall_fadvise64 221
#define syscall_timer_create 222
#define syscall_timer_settime 223
#define syscall_timer_gettime 224
#define syscall_timer_getoverrun 225
#define syscall_timer_delete 226
#define syscall_clock_settime 227
#define syscall_clock_gettime 228
#define syscall_clock_getres 229
#define syscall_clock_nanosleep 230
#define syscall_exit_group 231
#define syscall_epoll_wait 232
#define syscall_epoll_ctl 233
#define syscall_tgkill 234
#define syscall_utimes 235
#define syscall_vserver 236
#define syscall_mbind 237
#define syscall_set_mempolicy 238
#define syscall_get_mempolicy 239
#define syscall_mq_open 240
#define syscall_mq_unlink 241
#define syscall_mq_timedsend 242
#define syscall_mq_timedreceive 243
#define syscall_mq_notify 244
#define syscall_mq_getsetattr 245
#define syscall_kexec_load 246
#define syscall_waitid 247
#define syscall_add_key 248
#define syscall_request_key 249
#define syscall_keyctl 250
#define syscall_ioprio_set 251
#define syscall_ioprio_get 252
#define syscall_inotify_init 253
#define syscall_inotify_add_watch 254
#define syscall_inotify_rm_watch 255
#define syscall_migrate_pages 256
#define syscall_openat 257
#define syscall_mkdirat 258
#define syscall_mknodat 259
#define syscall_fchownat 260
#define syscall_futimesat 261
#define syscall_newfstatat 262
#define syscall_unlinkat 263
#define syscall_renameat 264
#define syscall_linkat 265
#define syscall_symlinkat 266
#define syscall_readlinkat 267
#define syscall_fchmodat 268
#define syscall_faccessat 269
#define syscall_pselect6 270
#define syscall_ppoll 271
#define syscall_unshare 272
#define syscall_set_robust_list 273
#define syscall_get_robust_list 274
#define syscall_splice 275
#define syscall_tee 276
#define syscall_sync_file_range 277
#define syscall_vmsplice 278
#define syscall_move_pages 279
#define syscall_utimensat 280
#define syscall_epoll_pwait 281
#define syscall_signalfd 282
#define syscall_timerfd_create 283
#define syscall_eventfd 284
#define syscall_fallocate 285
#define syscall_timerfd_settime 286
#define syscall_timerfd_gettime 287
#define syscall_accept4 288
#define syscall_signalfd4 289
#define syscall_eventfd2 290
#define syscall_epoll_create1 291
#define syscall_dup3 292
#define syscall_pipe2 293
#define syscall_inotify_init1 294
#define syscall_preadv 295
#define syscall_pwritev 296
#define syscall_rt_tgsigqueueinfo 297
#define syscall_perf_event_open 298
#define syscall_recvmmsg 299
#define syscall_fanotify_init 300
#define syscall_fanotify_mark 301
#define syscall_prlimit64 302
#define syscall_name_to_handle_at 303
#define syscall_open_by_handle_at 304
#define syscall_clock_adjtime 305
#define syscall_syncfs 306
#define syscall_sendmmsg 307
#define syscall_setns 308
#define syscall_getcpu 309
#define syscall_process_vm_readv 310
#define syscall_process_vm_writev 311
#define syscall_kcmp 312
#define syscall_finit_module 313
#define syscall_sched_setattr 314
#define syscall_sched_getattr 315
#define syscall_renameat2 316
#define syscall_seccomp 317
#define syscall_getrandom 318
#define syscall_memfd_create 319
#define syscall_kexec_file_load 320
#define syscall_bpf 321
#define syscall_execveat 322
#define syscall_userfaultfd 323
#define syscall_membarrier 324
#define syscall_mlock2 325
#define syscall_copy_file_range 326
#define syscall_preadv2 327
#define syscall_pwritev2 328
#define syscall_pkey_mprotect 329
#define syscall_pkey_alloc 330
#define syscall_pkey_free 331
#define syscall_statx 332
#define syscall_io_pgetevents 333
#define syscall_rseq 334
#define syscall_uretprobe 335
#define syscall_pidfd_send_signal 424
#define syscall_io_uring_setup 425
#define syscall_io_uring_enter 426
#define syscall_io_uring_register 427
#define syscall_open_tree 428
#define syscall_move_mount 429
#define syscall_fsopen 430
#define syscall_fsconfig 431
#define syscall_fsmount 432
#define syscall_fspick 433
#define syscall_pidfd_open 434
#define syscall_clone3 435
#define syscall_close_range 436
#define syscall_openat2 437
#define syscall_pidfd_getfd 438
#define syscall_faccessat2 439
#define syscall_process_madvise 440
#define syscall_epoll_pwait2 441
#define syscall_mount_setattr 442
#define syscall_quotactl_fd 443
#define syscall_landlock_create_ruleset 444
#define syscall_landlock_add_rule 445
#define syscall_landlock_restrict_self 446
#define syscall_memfd_secret 447
#define syscall_process_mrelease 448
#define syscall_futex_waitv 449
#define syscall_set_mempolicy_home_node 450
#define syscall_cachestat 451
#define syscall_fchmodat2 452
#define syscall_map_shadow_stack 453
#define syscall_futex_wake 454
#define syscall_futex_wait 455
#define syscall_futex_requeue 456
#define syscall_statmount 457
#define syscall_listmount 458
#define syscall_lsm_get_self_attr 459
#define syscall_lsm_set_self_attr 460
#define syscall_lsm_list_modules 461
#define syscall_mseal 462
#define syscall_setxattrat 463
#define syscall_getxattrat 464
#define syscall_listxattrat 465
#define syscall_removexattrat 466
#endif

#if defined(ARM64)
#define syscall_io_setup 0
#define syscall_io_destroy 1
#define syscall_io_submit 2
#define syscall_io_cancel 3
#define syscall_io_getevents 4
#define syscall_setxattr 5
#define syscall_lsetxattr 6
#define syscall_fsetxattr 7
#define syscall_getxattr 8
#define syscall_lgetxattr 9
#define syscall_fgetxattr 10
#define syscall_listxattr 11
#define syscall_llistxattr 12
#define syscall_flistxattr 13
#define syscall_removexattr 14
#define syscall_lremovexattr 15
#define syscall_fremovexattr 16
#define syscall_getcwd 17
#define syscall_lookup_dcookie 18
#define syscall_eventfd2 19
#define syscall_epoll_create1 20
#define syscall_epoll_ctl 21
#define syscall_epoll_pwait 22
#define syscall_dup 23
#define syscall_dup3 24
#define syscall_fcntl 25
#define syscall_inotify_init1 26
#define syscall_inotify_add_watch 27
#define syscall_inotify_rm_watch 28
#define syscall_ioctl 29
#define syscall_ioprio_set 30
#define syscall_ioprio_get 31
#define syscall_flock 32
#define syscall_mknodat 33
#define syscall_mkdirat 34
#define syscall_unlinkat 35
#define syscall_symlinkat 36
#define syscall_linkat 37
#define syscall_renameat 38
#define syscall_umount2 39
#define syscall_mount 40
#define syscall_pivot_root 41
#define syscall_nfsservctl 42
#define syscall_statfs 43
#define syscall_fstatfs 44
#define syscall_truncate 45
#define syscall_ftruncate 46
#define syscall_fallocate 47
#define syscall_faccessat 48
#define syscall_chdir 49
#define syscall_fchdir 50
#define syscall_chroot 51
#define syscall_fchmod 52
#define syscall_fchmodat 53
#define syscall_fchownat 54
#define syscall_fchown 55
#define syscall_openat 56
#define syscall_close 57
#define syscall_vhangup 58
#define syscall_pipe2 59
#define syscall_quotactl 60
#define syscall_getdents64 61
#define syscall_lseek 62
#define syscall_read 63
#define syscall_write 64
#define syscall_readv 65
#define syscall_writev 66
#define syscall_pread64 67
#define syscall_pwrite64 68
#define syscall_preadv 69
#define syscall_pwritev 70
#define syscall_sendfile 71
#define syscall_pselect6 72
#define syscall_ppoll 73
#define syscall_signalfd4 74
#define syscall_vmsplice 75
#define syscall_splice 76
#define syscall_tee 77
#define syscall_readlinkat 78
#define syscall_newfstatat 79
#define syscall_fstat 80
#define syscall_sync 81
#define syscall_fsync 82
#define syscall_fdatasync 83
#define syscall_sync_file_range 84
#define syscall_timerfd_create 85
#define syscall_timerfd_settime 86
#define syscall_timerfd_gettime 87
#define syscall_utimensat 88
#define syscall_acct 89
#define syscall_capget 90
#define syscall_capset 91
#define syscall_personality 92
#define syscall_exit 93
#define syscall_exit_group 94
#define syscall_waitid 95
#define syscall_set_tid_address 96
#define syscall_unshare 97
#define syscall_futex 98
#define syscall_set_robust_list 99
#define syscall_get_robust_list 100
#define syscall_nanosleep 101
#define syscall_getitimer 102
#define syscall_setitimer 103
#define syscall_kexec_load 104
#define syscall_init_module 105
#define syscall_delete_module 106
#define syscall_timer_create 107
#define syscall_timer_gettime 108
#define syscall_timer_getoverrun 109
#define syscall_timer_settime 110
#define syscall_timer_delete 111
#define syscall_clock_settime 112
#define syscall_clock_gettime 113
#define syscall_clock_getres 114
#define syscall_clock_nanosleep 115
#define syscall_syslog 116
#define syscall_ptrace 117
#define syscall_sched_setparam 118
#define syscall_sched_setscheduler 119
#define syscall_sched_getscheduler 120
#define syscall_sched_getparam 121
#define syscall_sched_setaffinity 122
#define syscall_sched_getaffinity 123
#define syscall_sched_yield 124
#define syscall_sched_get_priority_max 125
#define syscall_sched_get_priority_min 126
#define syscall_sched_rr_get_interval 127
#define syscall_restart_syscall 128
#define syscall_kill 129
#define syscall_tkill 130
#define syscall_tgkill 131
#define syscall_sigaltstack 132
#define syscall_rt_sigsuspend 133
#define syscall_rt_sigaction 134
#define syscall_rt_sigprocmask 135
#define syscall_rt_sigpending 136
#define syscall_rt_sigtimedwait 137
#define syscall_rt_sigqueueinfo 138
#define syscall_rt_sigreturn 139
#define syscall_setpriority 140
#define syscall_getpriority 141
#define syscall_reboot 142
#define syscall_setregid 143
#define syscall_setgid 144
#define syscall_setreuid 145
#define syscall_setuid 146
#define syscall_setresuid 147
#define syscall_getresuid 148
#define syscall_setresgid 149
#define syscall_getresgid 150
#define syscall_setfsuid 151
#define syscall_setfsgid 152
#define syscall_times 153
#define syscall_setpgid 154
#define syscall_getpgid 155
#define syscall_getsid 156
#define syscall_setsid 157
#define syscall_getgroups 158
#define syscall_setgroups 159
#define syscall_uname 160
#define syscall_sethostname 161
#define syscall_setdomainname 162
#define syscall_getrlimit 163
#define syscall_setrlimit 164
#define syscall_getrusage 165
#define syscall_umask 166
#define syscall_prctl 167
#define syscall_getcpu 168
#define syscall_gettimeofday 169
#define syscall_settimeofday 170
#define syscall_adjtimex 171
#define syscall_getpid 172
#define syscall_getppid 173
#define syscall_getuid 174
#define syscall_geteuid 175
#define syscall_getgid 176
#define syscall_getegid 177
#define syscall_gettid 178
#define syscall_sysinfo 179
#define syscall_mq_open 180
#define syscall_mq_unlink 181
#define syscall_mq_timedsend 182
#define syscall_mq_timedreceive 183
#define syscall_mq_notify 184
#define syscall_mq_getsetattr 185
#define syscall_msgget 186
#define syscall_msgctl 187
#define syscall_msgrcv 188
#define syscall_msgsnd 189
#define syscall_semget 190
#define syscall_semctl 191
#define syscall_semtimedop 192
#define syscall_semop 193
#define syscall_shmget 194
#define syscall_shmctl 195
#define syscall_shmat 196
#define syscall_shmdt 197
#define syscall_socket 198
#define syscall_socketpair 199
#define syscall_bind 200
#define syscall_listen 201
#define syscall_accept 202
#define syscall_connect 203
#define syscall_getsockname 204
#define syscall_getpeername 205
#define syscall_sendto 206
#define syscall_recvfrom 207
#define syscall_setsockopt 208
#define syscall_getsockopt 209
#define syscall_shutdown 210
#define syscall_sendmsg 211
#define syscall_recvmsg 212
#define syscall_readahead 213
#define syscall_brk 214
#define syscall_munmap 215
#define syscall_mremap 216
#define syscall_add_key 217
#define syscall_request_key 218
#define syscall_keyctl 219
#define syscall_clone 220
#define syscall_execve 221
#define syscall_mmap 222
#define syscall_fadvise64 223
#define syscall_swapon 224
#define syscall_swapoff 225
#define syscall_mprotect 226
#define syscall_msync 227
#define syscall_mlock 228
#define syscall_munlock 229
#define syscall_mlockall 230
#define syscall_munlockall 231
#define syscall_mincore 232
#define syscall_madvise 233
#define syscall_remap_file_pages 234
#define syscall_mbind 235
#define syscall_get_mempolicy 236
#define syscall_set_mempolicy 237
#define syscall_migrate_pages 238
#define syscall_move_pages 239
#define syscall_rt_tgsigqueueinfo 240
#define syscall_perf_event_open 241
#define syscall_accept4 242
#define syscall_recvmmsg 243
#define syscall_wait4 260
#define syscall_prlimit64 261
#define syscall_fanotify_init 262
#define syscall_fanotify_mark 263
#define syscall_name_to_handle_at 264
#define syscall_open_by_handle_at 265
#define syscall_clock_adjtime 266
#define syscall_syncfs 267
#define syscall_setns 268
#define syscall_sendmmsg 269
#define syscall_process_vm_readv 270
#define syscall_process_vm_writev 271
#define syscall_kcmp 272
#define syscall_finit_module 273
#define syscall_sched_setattr 274
#define syscall_sched_getattr 275
#define syscall_renameat2 276
#define syscall_seccomp 277
#define syscall_getrandom 278
#define syscall_memfd_create 279
#define syscall_bpf 280
#define syscall_execveat 281
#define syscall_userfaultfd 282
#define syscall_membarrier 283
#define syscall_mlock2 284
#define syscall_copy_file_range 285
#define syscall_preadv2 286
#define syscall_pwritev2 287
#define syscall_pkey_mprotect 288
#define syscall_pkey_alloc 289
#define syscall_pkey_free 290
#define syscall_statx 291
#define syscall_io_pgetevents 292
#define syscall_rseq 293
#define syscall_kexec_file_load 294
#define syscall_pidfd_send_signal 424
#define syscall_io_uring_setup 425
#define syscall_io_uring_enter 426
#define syscall_io_uring_register 427
#define syscall_open_tree 428
#define syscall_move_mount 429
#define syscall_fsopen 430
#define syscall_fsconfig 431
#define syscall_fsmount 432
#define syscall_fspick 433
#define syscall_pidfd_open 434
#define syscall_clone3 435
#define syscall_close_range 436
#define syscall_openat2 437
#define syscall_pidfd_getfd 438
#define syscall_faccessat2 439
#define syscall_process_madvise 440
#define syscall_epoll_pwait2 441
#define syscall_mount_setattr 442
#define syscall_quotactl_fd 443
#define syscall_landlock_create_ruleset 444
#define syscall_landlock_add_rule 445
#define syscall_landlock_restrict_self 446
#define syscall_memfd_secret 447
#define syscall_process_mrelease 448
#define syscall_futex_waitv 449
#define syscall_set_mempolicy_home_node 450
#define syscall_cachestat 451
#define syscall_fchmodat2 452
#define syscall_map_shadow_stack 453
#define syscall_futex_wake 454
#define syscall_futex_wait 455
#define syscall_futex_requeue 456
#define syscall_statmount 457
#define syscall_listmount 458
#define syscall_lsm_get_self_attr 459
#define syscall_lsm_set_self_attr 460
#define syscall_lsm_list_modules 461
#define syscall_mseal 462
#define syscall_setxattrat 463
#define syscall_getxattrat 464
#define syscall_listxattrat 465
#define syscall_removexattrat 466
#endif

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

        if (!system_call_3(syscall_ioctl, 1, 0x5413, (positive)ADDRESS_OF data))
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
        system_call_1(syscall_nanosleep, (positive)ADDRESS_OF time);
}

fn exit(b32 code)
{
        system_call_1(syscall_exit, code);
}

fn _start()
{
        // TODO: copy arguments from the stack

        b32 result = main();

        exit(result);
}

#endif