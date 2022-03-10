#ifndef RASPGPIO_H_INCLUDED
#define RASPGPIO_H_INCLUDED

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define INPUT "in"
#define OUTPUT "out"
#define HIGH 1
#define LOW 0

const char *sysPath = "/sys/class/gpio";

int pinMode(int pin, char *mode);
int digitalWrite(int pin, int value);
int digitalRead(int pin);
int enablePin(int pin);
int disablePin(int pin);

#endif
