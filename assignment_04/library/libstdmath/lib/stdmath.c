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

double power(double base, int exp)
{
    double result = 1;
    while (exp-- > 0)
    {
        result *= base;
    }

    return result;
}

// Calcula la raíz cuadrada
double _sqrt(float n)
{
    double sum = 0;

    for (int i = 1; i <= n / 2; i++)
    {
        sum += (n - 1) / ((2 * n) * (power(i, 2) + i));
    }

    double A = 1 + sum;

    return A + (n - power(A, 2)) / 2 * A;
}
