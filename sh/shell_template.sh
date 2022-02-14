#!/usr/bin/env bash


SELF_ADIR=$(cd $(dirname $0); pwd)
SELF_RDIR=$(dirname $(realpath $0))

CURDIR=$(pwd)
SELF_ARDIR=${SELF_ADIR/$CURDIR/.}
SELF_RRDIR=${SELF_RDIR/$CURDIR/.}

#TOPDIR=xx
#SRCDIR=xx

echo SELF_ADIR :$SELF_ADIR
echo SELF_RDIR :$SELF_RDIR
echo SELF_ARDIR:$SELF_ARDIR
echo SELF_RRDIR:$SELF_RRDIR
echo CURDIR    :$CURDIR


# in-param check
if [ -z "$1" ]; then
    echo "usage: $0 <arg1>"
    exit 1
fi

