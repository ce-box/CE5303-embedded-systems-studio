# Assignment 02

## GCC

GCC stands for GNU Compiler Collections which is used to compile mainly C and C++ language.

***

### Dependencies 📦

Before running this projects, you must install these dependencies:

```sh
sudo apt update
sudo apt install gcc \
                build-essential \
```

### Build and run library 🗃

#### Step-by-Step

To manually compile the library files:

```bash
# Build static library
gcc calc.c -o build/s_calc -L ./lib/ -l:libstdmath.a -lm
./s_calc
```

```bash
# Build shared library
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/lib
gcc calc.c -o build/d_calc -L ./lib/ -lstdmath -lm
./build/d_calc
```

It is also possible to build the library using scripts:

```bash
# Build libraries
sh lib/compile.sh
```

```bash
# Run shared library
sh run_shared.sh
```

```bash
# Run static library
sh run_static.sh
```

***

<p align="center">
<img src="https://static.platzi.com/media/achievements/badge-programacion-microcontroladores-pic-c-d3093418-a0e3-4b95-a6c2-77cf06af37f9.png" width="75"/>
</p>
