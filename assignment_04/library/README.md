# Assignment 04

## libstdmath

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

### Build library 🗃

In this section we will use `libtool`, as part of `autotools`, for dynamic library generation.

#### Using tar.gz file
First, we need to extract the content of the `libstdmath-1.0.tar.gz` file:

```sh
tar -xvf libstdmath-1.0.tar.gz
```

Then, move to the `libstdmath-1.0/` directory and create 2 directories:

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

If you downloaded the repository and will be using the source code, just change to `libstdmath/` directory an run:

```bash
sh install.sh
```

This commands will build the program, and also generates an application package with all the necessary files for distribution to the user.

***

<p align="center">
<img src="https://static.platzi.com/media/achievements/badge-programacion-microcontroladores-pic-c-d3093418-a0e3-4b95-a6c2-77cf06af37f9.png" width="75"/>
</p>
