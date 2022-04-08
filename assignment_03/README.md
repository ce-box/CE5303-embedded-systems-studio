# Assignment 03

## Make

***

### Dependencies 📦

Before running this projects, you must install these dependencies:

```sh
sudo apt update
sudo apt install make \ 
                gcc \
                build-essential \
```

### Build library 🗃

In this section we will use the `make` command to compile our programs. To compile the programs run:

```bash
make
```

The library has the following structure:

```text
stdmath
    |
    |-- bin
    |-- include
    |    |-- stdmath.h
    |
    |-- lib
    |    |-- stdmath.c
    |    |-- Makefile
    |
    |-- src
    |    |-- main.c
    |    |-- Makefile   
    |
    |-- Makefile
```

### Run the program 🚀

The program generates two executable files: one that uses the static library and one that uses the shared library.

```bash
cd bin
./calculator_d
./calculator_s
```

***

<p align="center">
<img src="https://static.platzi.com/media/achievements/badge-programacion-microcontroladores-pic-c-d3093418-a0e3-4b95-a6c2-77cf06af37f9.png" width="75"/>
</p>
