#!/bin/bash

HOME=$(pwd)

echo "Downloading libpng ..."
mkdir libpng
cd libpng
wget https://sourceforge.net/projects/libpng/files/libpng16/1.6.34/libpng-1.6.34.tar.gz

echo "Extracting files ..."
tar -xvf libpng-1.6.34.tar.gz
cd libpng-1.6.34
ls
cat configure

echo "Preparing for install library ..."
mkdir build
cd build
mkdir usr

echo "Configuring ..."
../configure --prefix=${HOME}/libpng/libpng-1.6.34/build/usr

echo "Building ..."
make

echo "Installing ..."
make install
cd usr
ls

echo "Verifying ..."
cd bin
./libpng16-config

echo "Done ..."