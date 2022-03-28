#!/bin/bash

HOME=$(pwd)

echo "Moving to libhello ..."
cd libhello
autoreconf --install
ls
cat configure

echo "Preparing for install library ..."
mkdir build
cd build
mkdir usr

echo "Configuring ..."
../configure --prefix=${HOME}/libhello/build/usr

echo "Building ..."
make

echo "Installing ..."
make install
cd usr
ls

echo "Verifying ..."
cd bin
ls

echo "Generating tar.gz file ..."
cd ../../
make distcheck

echo "Done ..."