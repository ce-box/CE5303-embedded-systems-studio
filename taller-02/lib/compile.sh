#!/bin/sh

echo "compiling dynamic library ..."
gcc stdmath.c -c -fpic
gcc stdmath.o -shared -o libstdmath.so
echo "dynamic library done ..."
echo "compiling static library ..."
ar rcs libstdmath.a stdmath.o
echo "static library done ..."
rm stdmath.o
echo "-------------------------------\n[DONE]"
