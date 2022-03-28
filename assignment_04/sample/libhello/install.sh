#!/bin/bash

HOME=$(pwd)

echo "Run installation scripts ..."
sudo apt install autoconf libtool autotools-dev
autoreconf --install
ls
cat configure

echo "Preparing for install library ..."
mkdir build
cd build
mkdir usr

echo "Configuring ..."
../configure --prefix=${HOME}/build/usr

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