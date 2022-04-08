build: stdmath.o
	gcc stdmath.o -shared -o libstdmath.so
	ar rcs libstdmath.a stdmath.o
	rm stdmath.o

stdmath.o:
	gcc -I../include stdmath.c -c -fpic
	