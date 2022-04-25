# Assignment 08

## Drivers in Linux

***

This assignment presents a brief introduction to drivers in linux. In this tutorial we'll create a driver for memory management, using the Linux standards for initiate, open, release, read, write and finish device controllers.

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

```sh
bash run.sh
```

or

```sh
chmod +x run.sh
./run.sh
```

The output of the memory driver's test must be like those:

![Memory Driver (1 bit)](https://github.com/ce-box/CE5303-embedded-systems-studio/blob/master/assignment_08/imgs/mem1.png)
![Memory Driver (32 bit)](https://github.com/ce-box/CE5303-embedded-systems-studio/blob/master/assignment_08/imgs/mem32.png)

***

<p align="center">
<img src="https://static.platzi.com/media/achievements/badge-programacion-microcontroladores-pic-c-d3093418-a0e3-4b95-a6c2-77cf06af37f9.png" width="75"/>
</p>
