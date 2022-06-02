#include <config.h>
#include <stdio.h>
#include <stdlib.h>

#define CYCLES 5

unsigned int exec_time = 0;

/**
 * A Linear Feedback Shift Register (LFSR) that generates a pseudo-random number.
 *
 * @param seed the seed for the LFSR
 *
 * @return The result of the LFSR function is the seed shifted right by 1 bit, with the result of the
 * XOR operation of the 5 bits being shifted into the leftmost bit.
 */
unsigned int LFSR(unsigned int seed)
{
    unsigned int bit1 = 1 & (seed >> 2);
    unsigned int bit2 = 1 & (seed >> 6);
    unsigned int bit3 = 1 & (seed >> 8);
    unsigned int bit4 = 1 & (seed >> 10);
    unsigned int bit5 = 1 & (seed >> 20);

    unsigned int result = ((((bit1 ^ bit2) ^ bit3) ^ bit4) ^ bit5) << 31;

    return (seed >> 1) | result;
}

/**
 * It opens the timer device, reads the current value of the timer, and returns that value
 *
 * @return The number of clock cycles since the timer was started.
 */
unsigned int read_timer()
{
    char read[8];
    FILE *fd = fopen("/dev/timer", "rb");

    if (fd == NULL)
    {
        printf("Error: timer could not be opened ...\n");
        exit(1);
    }

    fread(read, sizeof(read), 1, fd);
    fclose(fd);

    unsigned int result = strtol(read, NULL, 16);

    return result;
}

/**
 * It reads the timer, then runs the timer value through the random number generator function a bunch
 * of times, and returns the final value
 *
 * @return A random number
 */
unsigned int generate_random_number()
{

    unsigned int seed = read_timer();

    for (int i = 0; i < CYCLES; i++)
    {
        seed = generate_random_number(seed);
    }

    return seed;
}

/**
 * It opens the timer device, writes a 1 to it, and closes it
 */
void start_timer()
{
    FILE *fd = fopen("/dev/timer", "wb");

    if (fd == NULL)
    {
        printf("Error: timer could not be opened ...\n");
        exit(1);
    }

    fwrite("1", 1, 1, fd); // start -> 1
    fclose(fd);
}

/**
 * It opens the timer device, writes a 0 to it, and closes it
 *
 * @return The return value is the number of bytes written to the file.
 */
int stop_timer()
{
    FILE *fd = fopen("/dev/timer", "wb");

    if (fd == NULL)
    {
        printf("Error: timer could not be opened ...\n");
        exit(1);
    }

    fwrite("0", 1, 1, fd); // stop -> 0
    fclose(fd);

    return 0;
}
