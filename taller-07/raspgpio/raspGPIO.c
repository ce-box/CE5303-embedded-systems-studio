#include "raspGPIO.h"

int enablePin(int pin)
{
    char *sysPath = getenv("SYS_PATH");
    char *_pin = malloc(sizeof(char) * 2);
    char *path = malloc(sizeof(char) * 512);
    sprintf(_pin, "%d", pin);
    sprintf(path, "%s/export", sysPath);

    int fd = open(path, O_WRONLY);

    if (fd == -1)
    {
        perror("Unable to open GPIO configuration file ...");
        exit(1);
    }

    if (write(fd, _pin, strlen(_pin)) == -1)
    {
        perror("Error enabling pin in GPIO configuration file ...");
        exit(1);
    }
    close(fd);
    free(path);
    free(_pin);

    return 0;
}

int disablePin(int pin)
{
    char *sysPath = getenv("SYS_PATH");
    char *_pin = malloc(sizeof(char) * 2);
    char *path = malloc(sizeof(char) * 512);
    sprintf(_pin, "%d", pin);
    sprintf(path, "%s/unexport", sysPath);

    int fd = open(path, O_WRONLY);

    if (fd == -1)
    {
        perror("Unable to open GPIO configuration file ...");
        exit(1);
    }

    if (write(fd, _pin, strlen(_pin)) == -1)
    {
        perror("Error disabling pin in GPIO configuration file ...");
        exit(1);
    }
    close(fd);
    free(path);
    free(_pin);
    
    return 0;
}

int pinMode(int pin, char *mode)
{
    char *sysPath = getenv("SYS_PATH");
    char *filePath = malloc(sizeof(char) * 512);
    sprintf(filePath, "%s/gpio%d/direction", sysPath, pin);

    int fd = open(filePath, O_WRONLY);

    if (fd == -1)
    {
        perror("Unable to open GPIO configuration file ...");
        exit(1);
    }

    if (write(fd, mode, strlen(mode)) == -1)
    {
        perror("Error setting pin mode in GPIO configuration file ...");
        exit(1);
    }

    close(fd);
    free(filePath);

    return 0;
}

int digitalWrite(int pin, int value)
{
    char *sysPath = getenv("SYS_PATH");
    char *filePath = malloc(sizeof(char) * 512);
    char *pinValue = malloc(sizeof(char) * 5);
    sprintf(filePath, "%s/gpio%d/value", sysPath, pin);
    sprintf(pinValue, "%d", value);

    int fd = open(filePath, O_WRONLY);

    if (fd == -1)
    {
        perror("Unable to open GPIO configuration file ...");
        exit(1);
    }

    if (write(fd, pinValue, strlen(pinValue)) == -1)
    {
        perror("Error setting pin value in GPIO configuration file ...");
        exit(1);
    }

    close(fd);
    free(pinValue);
    free(filePath);

    return 0;
}

int digitalRead(int pin)
{
    char *sysPath = getenv("SYS_PATH");
    char *filePath = malloc(sizeof(char) * 512);
    char *pinValue = malloc(sizeof(char) * 2);
    sprintf(filePath, "%s/gpio%d/value", sysPath, pin);
    int fd = open(filePath, O_RDONLY);

    if (fd == -1)
    {
        perror("Unable to open GPIO configuration file ...");
        exit(1);
    }

    if (read(fd, pinValue, 1) == -1)
    {
        perror("Error reading pin value in GPIO configuration file ...");
        exit(1);
    }

    int value = atoi(pinValue);

    close(fd);
    free(pinValue);
    free(filePath);

    return value;
}
