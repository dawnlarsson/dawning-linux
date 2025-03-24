![Dawning Linux Header (1) (1)](https://github.com/user-attachments/assets/041c002f-5f08-43c5-baf6-905d72689052)

<div align="center">
  <a href="https://discord.gg/cxRvzUyzG8">Discord<a>
  —
  <a> Docs (TBD) <a>
</div>
<br>

### **Experimental** Linux Distro

co-developed with Dawning-Standard C, an experimental micro runtime library.
The aim is to lay the groundwork for a flexible core that's entirely self contained in terms of 3rd party dependencies.

There is also going to be a fair bit of architectural differences from the usual mainstream distro setup, 
filesystem, dependency management, linking & runtime requirements.

## Build
your build environment needs to be able to preform a normal kernel build, and
the clang C compiler is needed

see what you need to install here: https://docs.kernel.org/process/changes.html

building the distro:
```
sudo sh build.sh
```

if you want to run this in a virtual machine for testing:
```
sh build.run.sh
```
but, you need https://www.qemu.org/

### Profile based build & configuration
**`profile/*`** — Compartmentalized kernel configuration files. 
these are merged before building the kernel, and they are selectively chosen based on your
requirements

#### Profiles
**`profile/any`** — Build required.

**`profile/arch/*`** — Architecture specific requirements.

**`profile/desktop`** — Low latency everyday desktop config, and gaming.

**`profile/debug`** — Kernel debugging and development options.

### Profile driven flags
Profiles also drive kernel flags and make options,
any profile can include keys that are added to the kernel build like so:

Make flags:
```
#> make_flags CFLAGS="-fno-unwind-tables"
```

C flags:
```
#> shared_flags -O3
```

Linker flags:
```
#> linker_flags -Qn
```

Rust flags:
```
#> rust_flags -C opt-level=3
```

### Configuration (WIP)
**`sh script/config <profile> <profile>...`** — Takes any amount of profile names, simply merged by file name matching...

### Scripts
**`script/build.fs`** — Generates /fs (initram fs) structural setup

**`script/build.kernel`** — Kernel compile.

**`script/get.kernel`** — Downloads the Linux Kernel from kernel.org, version usually the latest version.

**`script/clean`** — Removes any generated artifacts, resets the repo, but keeps downloaded kernel archive.

**`script/size`** — Utility script, just prints the file size in arg 1

### License
logos, branding, trademarks - Copyright Dawn Larsson 2025

This repo: Apache License 2.0

