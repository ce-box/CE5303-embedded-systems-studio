clear
echo "compiling calc.c with static library ..."
gcc calc.c -o build/s_calc -L ./lib/ -l:libstdmath.a -lm
echo "runing s_calc ..."
./build/s_calc