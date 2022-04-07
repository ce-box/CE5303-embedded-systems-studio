#!/bin/bash

INSTALL_PATH=$(pwd)/build/usr

if [[ ! -d ./build ]]; then
    echo "Creating build directory ..."
    mkdir ./build
fi

cmake -S . -B ./build -DCMAKE_INSTALL_PREFIX:PATH=$INSTALL_PATH

cd build

echo "Building program ..."
make

echo "Installing program ..."
make install

export LD_LIBRARY_PATH=$(pwd)/usr/lib

echo "Verifying program ..."
./usr/bin/calc

echo "Packaging program ..."
make package_source