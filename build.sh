#!/bin/sh

# the version of the release
# this is <year><month><day>
# the granularity of the version depends on if it's a major or minor release
# for example, first release of the year would be "25"
# the second release of the year would be "25.2" and so on
# day granularity is used for patch/fix/minor releases
info_version="25"
info_name="dawning-linux"
target_platform="x86_64"

info_full_name="$info_name-$info_version"

sudo sh script/repo.setup

echo "CONFIG_LOCALVERSION=\"$info_full_name\"" > config/info
echo "CONFIG_DEFAULT_HOSTNAME=\"$info_name-box\"" >> config/info

sudo sh script/build.fs

sudo sh script/get.kernel