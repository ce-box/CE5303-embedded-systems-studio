#!/bin/bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/build
export SYS_PATH="./test/gpio"
gcc example.c -o example -L ./build/ -lHardwareController
./example