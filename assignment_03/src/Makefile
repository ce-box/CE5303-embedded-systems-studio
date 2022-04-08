build: 
	cd ..
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(PWD)/lib
	gcc -I../include calculator.c -o ../bin/calculator_s -L ../lib/ -l:libstdmath.a -lm
	gcc -I../include calculator.c -o ../bin/calculator_d -L ../lib/ -lstdmath -lm
