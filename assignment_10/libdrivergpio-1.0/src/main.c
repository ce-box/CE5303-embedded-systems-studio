#include <gpio.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	// Initialize pins
	init_ptrs();

	// INDIVIDUAL GPIOs

	// Set modes
	sgpio_set_mode(3, 2);
	sgpio_set_mode(5, 1);
	sgpio_set_mode(7, 0);

	// Get current modes to check
	sgpio_get_mode(3);
	sgpio_get_mode(5);
	sgpio_get_mode(7);

	// Write values
	gpio_write(3, 1);
	gpio_write(5, 0);
	gpio_write(7, 1);

	// Get current values to check
	printf("Pin 3 with value %u", gpio_read(3));
	printf("Pin 5 with value %u", gpio_read(5));
	printf("Pin 7 with value %u", gpio_read(7));

	// GROUP GPIOs

	// Set mode
	gpio8_set_mode(1);

	// Get current mode to check
	gpio8_get_mode();

	// Write value
	gpio8_write(1);

	// Wait for write to finish
	sleep(1);

	// Get current values to check
	gpio8_read();

	return 0;
}
