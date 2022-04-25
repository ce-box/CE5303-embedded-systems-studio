#!/bin/bash

echo "[4] Memory Driver 32 bits (4B)"
echo "[4] Compiling ..."
make -C /usr/src/linux-headers-$(uname -r) M=$(pwd modules)
echo "[4] Install Driver ..."
sudo mknode /dev/memory c 60 0
sudo chmod 666 /dev/memory
sudo insmod memory_32.ko
dmesg | tail -n 1
echo "[4] Verify installation ..."
if lsmod | grep -q "memory_32"; then
    echo "[4] <memory_32> driver installed ..."
fi
echo "[4] Write to memory  ..."
echo -n "ABCD" > /dev/memory
echo "[4] Read from memory  ..."
cat /dev/memory
echo ""
echo "[4] Remove Driver ..."
sudo rmmod memory_32
dmesg | tail -n 1
echo "[4] Done"