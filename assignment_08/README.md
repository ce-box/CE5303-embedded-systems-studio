# Assignment 08

## Drivers in Linux

***

This assignment presents a brief introduction to drivers in linux. In this tutorial we'll create a driver for memory management, using the Linux standards for initiate, open, release, read, write and finish device controllers.

A driver is a software application that allows you to implement routines for control and access to hardware modules and devices. In Linux, the driver is implemented from a C language file, which, after compilation, will generate a kernel module (.ko) corresponding to the device driver.

For a better comprehension of this assignment, you can check the instruction manual and the linux official documentation.

### Dependencies 📦

Before running this projects, you must install these dependencies:

```sh
sudo apt update
sudo apt install make \ 
                gcc \
                build-essential \
                linux-headers-$(uname -r)
```

### Build library 🗃

In this section we will use `make`, as part of `autotools`, for driver compilation.

First, clone the repository:

```sh
git clone https://github.com/ce-box/CE5303-embedded-systems-studio
cd assignment_08
```

Each directory brings an script to compile and run the program:

#### 1. Load and Remove Driver in User Space

In this first driver, it is shown how to add and remove a driver without any functionality.

```sh
cd ./01_load_and_remove_module
bash run.sh
```

#### 2. Load and Remove Driver in Kernel Space

The following example demonstrates how to define a (simple) functionality to load and remove a driver, in kernel space.

```sh
cd ./02_create_and_remove_driver
bash run.sh
```

#### 3. Memory Driver

In this section, a complete driver for a memory “device” will be developed, which will allow writing and reading a byte from it. This example does not have much practical use, but it gives an illustrative approach to the creation of drivers, as it is a complete driver and easy to implement (it does not interact with external hardware).

```sh
cd ./03_memory_driver
bash run.sh
```

The output of the memory driver's test must be like those:

![Memory Driver (1 bit)](https://github.com/ce-box/CE5303-embedded-systems-studio/blob/master/assignment_08/imgs/mem1.png)

#### 4. Memory Driver for 32-bit Data

In this section, the above driver is modified to support 32-bit wide writes and reads to the virtual device.

```sh
cd ./04_memory_driver_32b
bash run.sh
```

The output of the memory driver's test must be like those:
![Memory Driver (32 bit)](https://github.com/ce-box/CE5303-embedded-systems-studio/blob/master/assignment_08/imgs/mem32.png)

***

<p align="center">
<img src="https://static.platzi.com/media/achievements/badge-programacion-microcontroladores-pic-c-d3093418-a0e3-4b95-a6c2-77cf06af37f9.png" width="75"/>
</p>
