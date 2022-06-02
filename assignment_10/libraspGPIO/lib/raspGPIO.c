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

/**
 * It opens the /dev/mem file, maps the GPIO base physical address to a virtual address, and sets the
 * pointers to the registers
 */
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

/**
 * This function takes in a pin number and prints out the mode of that pin
 *
 * @param pin The pin number to get the mode of.
 */
void gpio_get_mode(int pin)
{
	// Check for pin number errors
	if (pin > 9 || pin < 2)
	{
		errx(1, "Error with pin number");
	}

	printf("Pin: %d, Mode: %u \n", pin, (*gpfsel0 >> (pin * 3)) & 7);
}

/**
 * It takes a pin number and a mode number, and sets the mode of the pin to the mode number
 *
 * @param pin The pin number to set the mode for.
 * @param mode The pin operation mode.
 */
void gpio_set_mode(int pin, int mode)
{
	// Check for mode and pin number errors
	if (mode > 7 || mode < 0)
	{
		errx(1, "Error with mode number");
	}
	if (pin > 9 || pin < 2)
	{
		errx(1, "Error with pin number");
	}

	// Assign mode to pin
	*gpfsel0 = *gpfsel0 | (mode << (pin * 3));
}

/**
 * It reads the value of a GPIO pin
 *
 * @param pin The pin number to read from.
 *
 * @return The value of the pin.
 */
int gpio_read(int pin)
{
	// Check for pin number errors
	if (pin > 9 || pin < 2)
	{
		errx(1, "Error with pin number");
	}

	return (*gplev0 >> pin) & 1;
}

/**
 * It writes a 1 or 0 to a GPIO pin
 *
 * @param pin The pin number to write to.
 * @param bit The value to write to the pin. 0 or 1.
 */
void gpio_write(int pin, int bit)
{
	// Check for pin number errors
	if (pin > 9 || pin < 2)
	{
		errx(1, "Error with pin number");
	}

	// Check if value to be written is 0 or 1
	if (bit)
	{
		// Value to write is a 1. Use gpset0
		*gpset0 = *gpset0 | (1 << pin);
	}
	else
	{
		// Value to write is 0. Use gpclr0
		*gpclr0 = *gpclr0 | (1 << pin);
	}
}

/**
 * It prints the mode of each pin in the GPIO8 group
 */
void gpio8_get_mode()
{
	// Check for each pin's mode
	for (int i = 2; i <= 9; i++)
	{
		printf("Pin: %d, Mode: %u \n", i, (*gpfsel0 >> (i * 3)) & 7);
	}
}

/**
 * It sets the mode of all the pins on GPIO8 to the mode specified by the user
 *
 * @param mode The pins operation mode.
 */
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

/**
 * It reads the value of each pin on the GPIO header and prints it to the screen
 */
void gpio8_read()
{
	// Read value for each pin
	for (int i = 2; i <= 9; i++)
	{
		printf("Pin: %d,  Value: %u \n", i, (*gplev0 >> i) & 1);
	}
}

/**
 * It writes a 1 to all pins in the GPIO8 bank if the value passed to it is 1, and writes a 0 to all
 * pins in the GPIO8 bank if the value passed to it is 0
 *
 * @param bit The value to be written to the GPIO pins.
 */
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
