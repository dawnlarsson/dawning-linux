#!/bin/sh

# x86_64 qemu
# qemu-system-x86_64 -kernel dist/bzImage -append "console=ttyS0" -smp 8 -m 4G -nographic

# x86_64 kvm using the efi stub
# qemu-system-x86_64 -kernel dist/bzImage -append "console=ttyS0" -smp 8 -m 4G -enable-kvm -device virtio-gpu

# qemu-system-x86_64 -enable-kvm -cpu host -smp 16 -display sdl -m 12G -kernel dist/bzImage

# qemu-system-x86_64 -smp 16 -m 12G -kernel dist/bzImage

qemu-system-x86_64 -enable-kvm -cpu host -smp 16 -m 12G -kernel dist/bzImage