#include "stdmath.h"
#include <math.h>

// Suma dos números
float _add(float x, float y) {
    return x + y;
}

// Realiza una resta de dos números
float _sub(float x, float y) {
    return x - y;
}

// Multiplica dos números
float _mul(float x, float y) {
    return x * y;
}

// Realiza la división de dos números
double _div(float x, float y) {
    if (y == 0.0)
        exit(-1);
    return x / y;
}

// Calcula la raíz cuadrada
double _sqrt(float x) {
    return sqrt(x);
}

// Calcula el factorial de un número entero
long double  fact(int x) {
    if (x == 0)
        return 1;
    return x * fact(x-1);
}

// Calcula un valor aproximado de la funcion cos(x)
double _cos(float x) {
    int n = 0;
    int itr = 100;
    double val = 0;
    while (n < itr) {
        val += pow(-1, n) * pow(x, 2*n) / fact(2*n);
        n++;
    }
    return val;
}
