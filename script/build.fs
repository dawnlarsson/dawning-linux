#!/bin/sh

if [ -d fs ]; then
    exit 1
fi

echo "Creating fs/ system directories"

mkdir -p fs/sys
mkdir -p fs/proc
mkdir -p fs/dev

# mkdir -p fs/root
# mkdir -p fs/etc
# mkdir -p fs/sbin
# mkdir -p fs/tmp
# mkdir -p fs/var

mknod fs/dev/tty c 5 0
mknod fs/dev/console c 5 1
mknod fs/dev/null c 1 3
mknod fs/dev/zero c 1 5
mknod fs/dev/random c 1 8
mknod fs/dev/urandom c 1 9
