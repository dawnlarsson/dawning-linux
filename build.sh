#!/bin/sh
sh script/is_safe || exit 1

# the version of the release
# this is <year><month><day>
# the granularity of the version depends on if it's a major or minor release
# for example, first release of the year would be "25"
# the second release of the year would be "25.2" and so on
# day granularity is used for patch/fix/minor releases
info_version="25"
info_name="dawning-linux"

info_full_name="$info_name-$info_version"

sudo sh script/setup

echo "CONFIG_LOCALVERSION=\"$info_full_name\"" > artifacts/info
echo "CONFIG_DEFAULT_HOSTNAME=\"$info_name-box\"" >> artifacts/info

sudo sh script/build.fs

# Compile runtime programs
sh standard/build programs/init fs/init
sh standard/build programs/shell fs/shell
sh standard/build programs/duck fs/duck

# Download kernel
sudo sh script/get.kernel

sh script/is_file artifacts/.config || \
        sudo sh script/config any arch/x64 debug_none limbo desktop

cd linux
sudo make allnoconfig
sh scripts/kconfig/merge_config.sh -m .config ../artifacts/.config
sudo make olddefconfig
cd ..

# Compile kernel
sudo sh script/build.kernel