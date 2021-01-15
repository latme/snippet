#!/bin/bash


pkg=$1


function getDepends()
{
    # use tr to del < >
    echo $(apt-cache depends $1 | grep Depends | cut -d: -f2 | tr -d "<>")
}

function getFirstWord()
{
    echo $1
}

function getNonFirstWords()
{
    shift
    echo $@
}

packages=""
depends=""

while [ -n "$pkg" ]; do
    deps=$(getDepends $pkg)
    echo "$pkg: $deps"

    # check if have repeat package
    for dep in $deps; do
        pkgs="$packages $depends"
        for p in $pkgs; do
            if [ "$p" == "$dep" ]; then
                dep=""
                break
            fi
        done
        depends="$depends $dep"
    done

    # addition package
    packages="$packages $pkg"
    #echo "depends :$depends"
    #echo "packages:$packages"
    #echo ""

    # next pkg
    pkg=$(getFirstWord $depends)
    depends=$(getNonFirstWords $depends)
    #echo next-pkg :$pkg
    #echo next-deps:$depends
    #echo ""
done

echo ""
echo will download packages:
echo =======================
echo $packages

