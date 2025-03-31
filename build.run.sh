#!/bin/sh

# x86_64 qemu
# qemu-system-x86_64 -kernel dist/bzImage -append "console=ttyS0" -smp 8 -m 4G -nographic

# x86_64 kvm using the efi stub
# qemu-system-x86_64 -kernel dist/bzImage -append "console=ttyS0" -smp 8 -m 4G -enable-kvm -device virtio-gpu

# qemu-system-x86_64 -enable-kvm -cpu host -smp 16 -display sdl -m 12G -kernel dist/bzImage

# qemu-system-x86_64 -smp 16 -m 12G -kernel dist/bzImage

# qemu-system-x86_64 -enable-kvm -cpu host -smp 16 -m 12G -kernel dist/bzImage

kernel_image=$(sh script/key kernel_image)
kernel_export=$(sh script/key kernel_export)

arch=$(sh script/key_single arch)

if [ "$arch" = "x86_64" ]; then
    qemu-system-x86_64 -enable-kvm -cpu host -smp 4 -m 4G -kernel $kernel_export
fi

if [ "$arch" = "arm64" ]; then
    qemu-system-aarch64 -machine virt -cpu cortex-a53 -smp 4 -m 4G -kernel $kernel_export
fi


# qemu-system-x86_64 -smp 6 -m 4G -kernel dist/bootx64.efi