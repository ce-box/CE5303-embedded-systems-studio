clear
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/lib
echo "exported to PATH -> $LD_LIBRARY_PATH"
echo "compiling with dynamic library ..."
gcc calc.c -o build/d_calc -L ./lib/ -lstdmath -lm
echo "runing d_calc ..."
./build/d_calc