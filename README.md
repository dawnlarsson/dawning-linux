![Dawning Linux Header (1)](https://github.com/user-attachments/assets/86ff911c-60c1-4af1-930d-910158a55f70)


<div align="center">
  ``
Eos

The goddess and personification of dawn.
``

  <a href="https://discord.gg/cxRvzUyzG8">Discord<a>
  —
  <a> Docs (TBD) <a>
</div>
<br>

Dawning Eos is built from the ground up with no external runtime dependencies. The **Dawning Standard C** library provides everything needed in a clean, minimal implementation.

It's a **fundamental reconsideration** of how operating systems and the software that runs on them should be designed, built, and configured. Software has become increasingly complex, dependent on sprawling ecosystems of libraries, and divorced from the hardware it runs on, Dawning Eos takes a different path.

Computing system should be comprehensible, predictable, and free from unnecessary abstractions.

**This is EARLY, this is experimental. It might not workout, but it sure is worth trying.**

### Why Dawning Standard C?
> Syntax shapes the way you think. Better thinking should be standardized.

Traditional type systems and APIs prioritize implementation details over clear expression of intent.

The Type system is explicit about ranges, memory layouts, and semantic meaning. 

Types like `positive`, `bipolar`, and `decimal` **communicate intention**, not just implementation.
The improved clarity aims to make systems programming **safer AND faster** by having **lower cognative load** on the programmer. 


By carefully re-designing the API and type expression, code can become more effective to think, write and audit.

### Build
your build environment needs to be able to preform a normal kernel build, and
the clang C compiler is needed

see what you need to install here: https://docs.kernel.org/process/changes.html

### building the distro
Minimal config for x86_x64
```
sudo sh build.sh arch/x64 debug_none
```

Minimal config for raspberry pis (WIP)
```
sudo sh build.sh arch/arm.pi debug_none
```

if you want to run this in a virtual machine for testing:
```
sh build.run.sh
```
but, you need https://www.qemu.org/

### Macos building
testing... you need gcc cross build compilers:
https://github.com/messense/homebrew-macos-cross-toolchains

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
logos, branding, trademarks - Copyright Dawn Larsson 2022

This repo: Apache License 2.0

