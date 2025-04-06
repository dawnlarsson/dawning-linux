#!/bin/sh
source script/common

label REPOSITORY SETUP
        echo "Building $info_full_name"
        sudo sh script/setup

label DISTRO INFO
        echo "CONFIG_LOCALVERSION=\"$info_full_name\"" > artifacts/info
        echo "CONFIG_DEFAULT_HOSTNAME=\"$info_name-box\"" >> artifacts/info
        sudo sh script/fs_setup

label KERNEL CONFIGURATION
        sudo sh script/kernel_setup
        
        [ -z "$1" ] || sudo sh script/config any $@

        is_file artifacts/.config || \
                sudo sh script/config any arch/x64 debug_none limbo desktop

        make_flags=$(key make_flags)

label KERNEL CONFIG
        cp -r src/ linux/dawning
        line_add_padded "linux/Kconfig" "source \"dawning/Kconfig\""

        cd linux
        sudo make allnoconfig $make_flags > /dev/null
        sh scripts/kconfig/merge_config.sh -m .config ../artifacts/.config $make_flags > /dev/null
        sudo make olddefconfig $make_flags > /dev/null
        cd ..

label USER SPACE BUILD
        sh standard/build_kernel programs/init fs/init
        sh standard/build_kernel programs/shell fs/shell
        sh standard/build_kernel programs/duck fs/duck
        sh standard/build_kernel programs/edit fs/edit

label KERNEL BUILD
        sudo sh script/kernel_build