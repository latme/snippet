#!/bin/bash


sudo rm -f /var/cache/apt/archives/*.deb
sudo apt install --reinstall -d -y $@
ls  -lhR           /var/cache/apt/               2>/dev/null
tar -cf deb.$1.tar /var/cache/apt/archives/*.deb 2>/dev/null

