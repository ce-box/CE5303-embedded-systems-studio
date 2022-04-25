#!/bin/bash

echo "[1] Load and Remove module in user space"
echo "[1] Compiling ..."
make -C /usr/src/linux-headers-$(uname -r) M=$(pwd modules)
echo "[1] Install module ..."
sudo insmod nothing.ko
echo "[1] Verify installation ..."
if lsmod | grep -q "nothing"; then
    echo "[1] <nothing> module installed ..."
fi
echo "[1] Remove module ..."
sudo rmmod nothing
echo "[1] Done"