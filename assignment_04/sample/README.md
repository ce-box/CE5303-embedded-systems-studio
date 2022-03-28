# Assignment 04

## Introduction to Autotools

***

### Dependencies

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

### 1. Autotools in user mode

Run `sh install-libpng.sh` to install libpng library using `autotools` in user mode.

### 2. Autotools in dev mode

In this section we will use `autotools` in dev mode for build a simple *Hello World* program, for this we will use the `helloworld.c` source code file.

```bash
cd helloworld
sh install.sh
```

This commands will build the program, and also generates an application package with all the necessary files for distribution to the user.

### 3. Autotools for libraries

In this section we will use `libtool`, as part of `autotools`, for dynamic library generation.

```bash
cd libhello
sh install.sh
```

This commands will build the program, and also generates an application package with all the necessary files for distribution to the user.