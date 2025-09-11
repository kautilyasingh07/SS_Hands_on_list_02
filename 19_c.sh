#!/bin/bash

:<<'END_COMMENT'

====================================================================================================================================
Name: 19_c.sh
Author : KAUTILYA SINGH
Description : 
Create a FIFO file by
    c. use strace command to find out, which command (mknod or mkfifo) is better.
====================================================================================================================================

END_COMMENT



strace mknod testfifo p
strace mkfifo testfifo2





:<<'END_COMMENT'
Output:

Kautilya-Singh:./19_c.sh
execve("/usr/bin/mknod", ["mknod", "testfifo", "p"], 0x7fff9a047040 /* 48 vars */) = 0
brk(NULL)                               = 0x5bc187824000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ce71d80d000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=61179, ...}) = 0
mmap(NULL, 61179, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7ce71d7fe000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0644, st_size=174472, ...}) = 0
mmap(NULL, 181960, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7ce71d7d1000
mmap(0x7ce71d7d7000, 118784, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7ce71d7d7000
mmap(0x7ce71d7f4000, 24576, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x23000) = 0x7ce71d7f4000
mmap(0x7ce71d7fa000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7ce71d7fa000
mmap(0x7ce71d7fc000, 5832, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7ce71d7fc000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7ce71d400000
mmap(0x7ce71d428000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7ce71d428000
mmap(0x7ce71d5b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7ce71d5b0000
mmap(0x7ce71d5ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7ce71d5ff000
mmap(0x7ce71d605000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7ce71d605000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0644, st_size=625344, ...}) = 0
mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7ce71d737000
mmap(0x7ce71d739000, 450560, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7ce71d739000
mmap(0x7ce71d7a7000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x70000) = 0x7ce71d7a7000
mmap(0x7ce71d7cf000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7ce71d7cf000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ce71d734000
arch_prctl(ARCH_SET_FS, 0x7ce71d734800) = 0
set_tid_address(0x7ce71d734ad0)         = 15017
set_robust_list(0x7ce71d734ae0, 24)     = 0
rseq(0x7ce71d735120, 0x20, 0, 0x53053053) = 0
mprotect(0x7ce71d5ff000, 16384, PROT_READ) = 0
mprotect(0x7ce71d7cf000, 4096, PROT_READ) = 0
mprotect(0x7ce71d7fa000, 4096, PROT_READ) = 0
mprotect(0x5bc166f15000, 4096, PROT_READ) = 0
mprotect(0x7ce71d84b000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7ce71d7fe000, 61179)           = 0
statfs("/sys/fs/selinux", 0x7ffe3e1133a0) = -1 ENOENT (No such file or directory)
statfs("/selinux", 0x7ffe3e1133a0)      = -1 ENOENT (No such file or directory)
getrandom("\x9d\x99\x78\x12\x7a\x47\x5c\x3d", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x5bc187824000
brk(0x5bc187845000)                     = 0x5bc187845000
openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0444, st_size=0, ...}) = 0
read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 380
read(3, "", 1024)                       = 0
close(3)                                = 0
access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=5719296, ...}) = 0
mmap(NULL, 5719296, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7ce71ce00000
close(3)                                = 0
mknodat(AT_FDCWD, "testfifo", S_IFIFO|0666) = 0
close(1)                                = 0
close(2)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++
execve("/usr/bin/mkfifo", ["mkfifo", "testfifo2"], 0x7fff9e37af88 /* 48 vars */) = 0
brk(NULL)                               = 0x648b22d26000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7124b4bd2000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=61179, ...}) = 0
mmap(NULL, 61179, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7124b4bc3000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0644, st_size=174472, ...}) = 0
mmap(NULL, 181960, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7124b4b96000
mmap(0x7124b4b9c000, 118784, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7124b4b9c000
mmap(0x7124b4bb9000, 24576, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x23000) = 0x7124b4bb9000
mmap(0x7124b4bbf000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7124b4bbf000
mmap(0x7124b4bc1000, 5832, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7124b4bc1000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7124b4800000
mmap(0x7124b4828000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7124b4828000
mmap(0x7124b49b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7124b49b0000
mmap(0x7124b49ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7124b49ff000
mmap(0x7124b4a05000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7124b4a05000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0644, st_size=625344, ...}) = 0
mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7124b4afc000
mmap(0x7124b4afe000, 450560, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7124b4afe000
mmap(0x7124b4b6c000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x70000) = 0x7124b4b6c000
mmap(0x7124b4b94000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7124b4b94000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7124b4af9000
arch_prctl(ARCH_SET_FS, 0x7124b4af9800) = 0
set_tid_address(0x7124b4af9ad0)         = 15021
set_robust_list(0x7124b4af9ae0, 24)     = 0
rseq(0x7124b4afa120, 0x20, 0, 0x53053053) = 0
mprotect(0x7124b49ff000, 16384, PROT_READ) = 0
mprotect(0x7124b4b94000, 4096, PROT_READ) = 0
mprotect(0x7124b4bbf000, 4096, PROT_READ) = 0
mprotect(0x648aefc88000, 4096, PROT_READ) = 0
mprotect(0x7124b4c10000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7124b4bc3000, 61179)           = 0
statfs("/sys/fs/selinux", 0x7ffe80f0cca0) = -1 ENOENT (No such file or directory)
statfs("/selinux", 0x7ffe80f0cca0)      = -1 ENOENT (No such file or directory)
getrandom("\x1b\x48\x21\x46\x7e\xe7\x1e\x04", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x648b22d26000
brk(0x648b22d47000)                     = 0x648b22d47000
openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0444, st_size=0, ...}) = 0
read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 380
read(3, "", 1024)                       = 0
close(3)                                = 0
access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=5719296, ...}) = 0
mmap(NULL, 5719296, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7124b4200000
close(3)                                = 0
mknodat(AT_FDCWD, "testfifo2", S_IFIFO|0666) = 0
close(1)                                = 0
close(2)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++


END_COMMENT


