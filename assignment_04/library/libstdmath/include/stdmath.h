/* ---------------------------------------------------------------------------
 * file: stdmath.h
 * autor: Esteban Alvarado
 *
 * @brief Biblioteca que permite realizar cálculos matemáticos con las
 *        operaciones básicas: suma(+), resta(-), multiplicacion(*),
 *        división(/), raíz cuadrada (sqrt) y coseno por aproximación.
 *
 * @version 1.0
 * ---------------------------------------------------------------------------*/

#ifndef STD_MATH
#define STD_MATH

#include <stdlib.h>

float _add(float x, float y);
float _sub(float x, float y);
float _mul(float x, float y);
double _div(float x, float y);
double _sqrt(float x);

#endif