#include "stdmath.h"

// Suma dos números
float _add(float x, float y)
{
    return x + y;
}

// Realiza una resta de dos números
float _sub(float x, float y)
{
    return x - y;
}

// Multiplica dos números
float _mul(float x, float y)
{
    return x * y;
}

// Realiza la división de dos números
double _div(float x, float y)
{
    if (y == 0.0)
        exit(-1);
    return x / y;
}

// Calcula la raíz cuadrada
double _sqrt(float x)
{
    double A = 1;

    for (int i = 0; i < x / 2; i++)
    {
        A += ((x - 1) / (i * (i + 1))) / (2 * x);
    }

    return A + (x - A * A) / (2 * A);
}
