#!/bin/bash

echo "[3] Memory Driver"
echo "[3] Compiling ..."
make -C /usr/src/linux-headers-$(uname -r) M=$(pwd modules)
echo "[3] Install Driver ..."
sudo mknode /dev/memory c 60 0
sudo chmod 666 /dev/memory
sudo insmod memory.ko
dmesg | tail -n 1
echo "[3] Verify installation ..."
if lsmod | grep -q "memory"; then
    echo "[3] <memory> driver installed ..."
fi
echo "[3] Write to memory  ..."
echo -n E > /dev/memory
echo "[3] Read from memory  ..."
cat /dev/memory
echo ""
echo "[3] Remove Driver ..."
sudo rmmod memory
dmesg | tail -n 1
echo "[3] Done"