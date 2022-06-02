# Assignment 10

## Raspberry PI GPIO Driver

**Students:** Gabriel Abarca, Esteban Alvarado, María Ávila, Olman Castro

**Student cards ID:** 2017110442, 2018109336, 2014089607, 2016003615
***

### Dependencies 📦

Before running this projects, you must install these dependencies:

```sh
sudo apt update
sudo apt install make \ 
                gcc \
                build-essential \
                autotools-dev \
                autoconf \
                libtool
```

> ⚠️ **In order to use the library, you first need to install the GPIO driver on the device. You can refer to the lab manual in sections 4, 5 and 7. Use the source code found in the sample/rasp-drivers directory.**

#### Compilation

```sh
source /opt/poky/2.3.4/environment-setup-cortexa7hf-neon-vfpv4-poky-linux-gnueabi $CC -o gpio gpio.c
```

***

### Build library 🗃

In this section we will use make, as part of autotools, for driver compilation.

#### Using tar.gz file

First, we need to extract the content of the `libraspgpio-1.0.tar.gz` file:

```sh
tar -xvf libstdmath-1.0.tar.gz
```

Then, move to the `libraspGPIO-1.0/` directory and create 2 directories:

```sh
mkdir build
cd build
mkdir usr
../configure --prefix=<path-to-your-usr-directory>
```

If you want to install the library permanently in your computer don't use the `--prefix` command flag.

Inside `build` directory run the follow commands:

```sh
make
make install
cd usr
ls
```

### Cloning repository

If you downloaded the repository and will be using the source code, just change to `libraspGPIO/` directory an run:

```bash
sh install.sh
```

This commands will build the program, and also generates an application package with all the necessary files for distribution to the user.

***

<p align="center">
<img src="https://static.platzi.com/media/achievements/badge-programacion-microcontroladores-pic-c-d3093418-a0e3-4b95-a6c2-77cf06af37f9.png" width="75"/>
</p>
