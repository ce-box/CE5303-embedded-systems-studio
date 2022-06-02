#include <config.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

// Static base
static unsigned GPIO_BASE = 0x3f200000;

// Registers pointers
volatile unsigned int *gpfsel0;
volatile unsigned int *gpset0;
volatile unsigned int *gpclr0;
volatile unsigned int *gplev0;

// Initialize pointers: performs memory mapping, exits if mapping fails
void init_ptrs()
{
	int fd = -1;

	// Loading /dev/mem into a file
	if ((fd = open("/dev/mem", O_RDWR, 0)) == -1)
	{
		err(1, "Error opening /dev/mem");
	}

	// Mapping GPIO base physical address
	gpfsel0 = (unsigned int *)mmap(0, getpagesize(), PROT_WRITE, MAP_SHARED, fd, GPIO_BASE);

	// Check for mapping errors
	if (gpfsel0 == MAP_FAILED)
	{
		errx(1, "Error during mapping GPIO");
	}

	// Set registers pointers
	gpset0 = gpfsel0 + 0x7;
	gpclr0 = gpfsel0 + 0xA;
	gplev0 = gpfsel0 + 0xD;
}

// Gets mode of a single GPIO pin
void sgpio_get_mode(int pinNum)
{
	// Check for pin number errors
	if (pinNum > 9 || pinNum < 2)
	{
		errx(1, "Error with pin number");
	}

	printf("Mode %u for pin number %d", (*gpfsel0 >> (pinNum * 3)) & 7, pinNum);
}

// Set mode of single GPIO pin
void sgpio_set_mode(int pinNum, int mode)
{
	// Check for mode and pin number errors
	if (mode > 7 || mode < 0)
	{
		errx(1, "Error with mode number");
	}
	if (pinNum > 9 || pinNum < 2)
	{
		errx(1, "Error with pin number");
	}

	// Assign mode to pin
	*gpfsel0 = *gpfsel0 | (mode << (pinNum * 3));
}

// Reads value of single GPIO pin by number
int gpio_read(int pinNum)
{
	// Check for pin number errors
	if (pinNum > 9 || pinNum < 2)
	{
		errx(1, "Error with pin number");
	}

	return (*gplev0 >> pinNum) & 1;
}

// Writes value to single GPIO pin by number
void gpio_write(int pinNum, int bit)
{
	// Check for pin number errors
	if (pinNum > 9 || pinNum < 2)
	{
		errx(1, "Error with pin number");
	}

	// Check if value to be written is 0 or 1
	if (bit)
	{
		// Value to write is a 1. Use gpset0
		*gpset0 = *gpset0 | (1 << pinNum);
	}
	else
	{
		// Value to write is 0. Use gpclr0
		*gpclr0 = *gpclr0 | (1 << pinNum);
	}
}

// Gets current mode of all pins
void gpio8_get_mode()
{
	// Check for each pin's mode
	for (int i = 2; i <= 9; i++)
	{
		printf("Mode %u selected for pin number %d", (*gpfsel0 >> (i * 3)) & 7, i);
	}
}

// Sets specified mode to all pins
void gpio8_set_mode(int mode)
{
	// Check for mode number errors
	if (mode > 7 || mode < 0)
	{
		errx(1, "Error with mode number");
	}

	// Set mode of all pins
	for (int i = 2; i <= 9; i++)
	{
		*gpfsel0 = *gpfsel0 | (mode << (i * 3));
	}
}

// Reads value of all pins
void gpio8_read()
{
	// Read value for each pin
	for (int i = 2; i <= 9; i++)
	{
		printf("Value %u for pin number %d", (*gplev0 >> i) & 1, i);
	}
}

// Writes value bit to all pins
void gpio8_write(int bit)
{
	// Check if value to be written is 0 or 1
	if (bit)
	{
		// Write 1 to all pins
		for (int i = 2; i <= 9; i++)
		{
			// Use gpset0 as value to write is 1
			*gpset0 = *gpset0 | (1 << i);
		}
	}
	else
	{
		// Write 0 to all pins
		for (int i = 2; i <= 9; i++)
		{
			// Use gpclr0 as value to write is 0
			*gpclr0 = *gpclr0 | (1 << i);
		}
	}
}
