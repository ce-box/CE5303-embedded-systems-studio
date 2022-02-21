#include <stdio.h>
#include "lib/stdmath.h"

#define PI 3.141592654

void add_test() {
    int xv[] = {5, 21, 100, 34, -30, 11};
    int yv[] = {4, 56, 89, 44, 23, -1};

    for (int i = 0; i < 6; i++) {
        int x = xv[i], y = yv[i];
        printf("\033[01;33m[add]\033[0:m op: %i + %i , expected: %.1d, result: %.1f\n", x, y, x+y , _add(x,y)); 
    }
    printf("\n");
}

void sub_test() {
    int xv[] = {5, 21, 100, 34, -30, 11};
    int yv[] = {4, 56, 89, 44, 23, -1};

    for (int i = 0; i < 6; i++) {
        int x = xv[i], y = yv[i];
        printf("\033[01;32m[sub]\033[0:m op: %i - %i , expected: %.1d, result: %.1f\n", x, y, x-y , _sub(x,y)); 
    }
    printf("\n");
}

void mul_test() {
    int xv[] = {5, 4, 4, 34, -30, 12};
    int yv[] = {5, 14, 1, 0, -45, -3};

    for (int i = 0; i < 6; i++) {
        int x = xv[i], y = yv[i];
        printf("\033[01;36m[mul]\033[0:m op: %i * %i , expected: %.1d, result: %.1f\n", x, y, x*y , _mul(x,y)); 
    }
    printf("\n");
}

void div_test() {
    int xv[] = {5, 20, 100, -34, -30, 300};
    int yv[] = {5, 60, 89, -44, 23, 30};

    for (int i = 0; i < 5; i++) {
        int x = xv[i], y = yv[i];
        printf("\033[01;35m[div]\033[0:m op: %i / %i , expected: %.1d, result: %.1f\n", x, y, x/y , _div(x,y)); 
    }
    printf("\n");
}

void sqrt_test() {
    int xv[] = {2, 4, 16, 24, 49};

    for (int i = 0; i < 5; i++) {
        int x = xv[i];
        printf("\033[01;33m[sqrt]\033[0:m op: sqrt(%i), result: %.1f\n", x, _sqrt(x)); 
    }
    printf("\n");
}

void cos_test() {
    
    float xv[] = {0, PI/4, PI/2, 3*PI/4, PI}; // rads

    for (int i = 0; i < 5; i++) {
        float x = xv[i];
        printf("\033[01;31m[cos]\033[0:m op: cos(%.2f), result: %.3f\n", x, _cos(x)); 
    }
    printf("\n");
}

int main() {
    add_test();
    sub_test();
    mul_test();
    div_test();
    sqrt_test();
    cos_test();
    return 0;
}