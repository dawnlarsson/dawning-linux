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

sh script/label REPOSITORY SETUP

sudo sh script/setup


sh script/label DISTRO INFO

echo "CONFIG_LOCALVERSION=\"$info_full_name\"" > artifacts/info
echo "CONFIG_DEFAULT_HOSTNAME=\"$info_name-box\"" >> artifacts/info

sudo sh script/build.fs


sh script/label KERNEL CONFIGURATION

sudo sh script/get.kernel

[ -z "$1" ] || sudo sh script/config any $@

sh script/is_file artifacts/.config || \
        sudo sh script/config any arch/x64 debug_none limbo desktop

cd linux
sudo make allnoconfig > /dev/null
sh scripts/kconfig/merge_config.sh -m .config ../artifacts/.config > /dev/null
sudo make olddefconfig > /dev/null
cd ..

sh script/label USER SPACE BUILD

# Compile runtime programs
sh standard/build_kernel programs/init fs/init
sh standard/build_kernel programs/shell fs/shell
sh standard/build_kernel programs/duck fs/duck
sh standard/build_kernel programs/edit fs/edit


sh script/label KERNEL BUILD

sudo sh script/build.kernel