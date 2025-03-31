#!/bin/sh

kernel_image=$(sh script/key kernel_image)
kernel_export=$(sh script/key kernel_export)

arch=$(sh script/key_single arch)
virt=$(sh script/key_single virt)

if [ "$arch" = "x86_64" ]; then
        args=" -enable-kvm -cpu host -smp 4 -m 4G"
fi

if [ "$arch" = "arm64" ]; then
        args=" -machine raspi4b -m 2G -smp 4"
fi

$virt $args -kernel $kernel_export