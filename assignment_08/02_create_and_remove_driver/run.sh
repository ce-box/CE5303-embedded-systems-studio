#!/bin/bash

echo "[2] Load and Remove Driver in user space"
echo "[2] Compiling ..."
make -C /usr/src/linux-headers-$(uname -r) M=$(pwd modules)
echo "[2] Install Driver ..."
sudo insmod hello.ko
dmesg | tail -n 1
echo "[2] Verify installation ..."
if lsmod | grep -q "hello"; then
    echo "[2] <hello> driver installed ..."
fi
echo "[2] Remove Driver ..."
sudo rmmod hello
dmesg | tail -n 1
echo "[2] Done"