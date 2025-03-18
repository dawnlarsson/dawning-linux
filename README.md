![image](https://github.com/user-attachments/assets/dd6ba21d-8f3f-481a-a36c-301d79435a80)

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

### Profile based build & configuration
**`profile/*`** — Compartmentalized kernel configuration files. 
these are merged before building the kernel, and they are selectively chosen based on your
requirements

#### Profiles
**`profile/any`** — Build required.

**`profile/desktop`** — Low latency everyday desktop config, and gaming.

**`profile/debug`** — Kernel debugging and development options.

`TODO: debug<level> - debug01 - debug02 ect... `

### Configuration (WIP)
**`sh script/config <profile> <profile>...`** — Takes any amount of profile names, simply merged by file name matching...

### Scripts
**`script/build.fs`** — Generates /fs (initram fs) structural setup

**`script/build.kernel`** — Kernel compile.

**`script/get.kernel`** — Downloads the Linux Kernel from kernel.org, version usually the latest version.

**`script/repo.clean`** — Removes any generated artifacts, resets the repo, but keeps downloaded kernel archive.

**`script/size`** — Utility script, just prints the file size in arg 1

## build:
```
sudo sh build.sh
```

### License
logos, branding, trademarks - Copyright Dawn Larsson 2025

This repo: Apache License 2.0

