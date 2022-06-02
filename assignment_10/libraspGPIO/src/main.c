#include <raspGPIO.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * It tests the GPIO functions
 */
void test_gpio()
{
	printf("[2] GPIO Test ...\n");

	printf("\t[2.1] Set mode ...\n");
	gpio_set_mode(2, 0);
	gpio_set_mode(4, 1);
	gpio_set_mode(6, 2);

	printf("\t[2.2] Get mode ...\n");
	gpio_get_mode(2);
	gpio_get_mode(4);
	gpio_get_mode(6);

	printf("\t[2.3] Write ...\n");
	gpio_write(2, 1);
	gpio_write(4, 0);
	gpio_write(6, 1);

	printf("\t[2.4] Read ...\n");
	printf("\t\tPin %i,  Value: %u\n", 2, gpio_read(2));
	printf("\t\tPin %i,  Value: %u\n", 4, gpio_read(4));
	printf("\t\tPin %i,  Value: %u\n", 6, gpio_read(6));
}

/**
 * It tests the GPIO8 functionality
 */
void test_gpio8()
{
	printf("[3] GPIO8 Test ...\n");

	printf("\t[3.1] Set mode ...\n");
	gpio8_set_mode(1);

	printf("\t[3.2] Get mode ...\n");
	gpio8_get_mode();

	printf("\t[3.3] Write ...\n");
	gpio8_write(1);

	// Wait for write to finish
	sleep(1);

	printf("\t[3.4] Read ...\n");
	gpio8_read();
}

int main(int argc, char const *argv[])
{
	/* Calling the functions test_gpio and test_gpio8. */
	printf("[1] Start program ...\n");
	init_ptrs();

	test_gpio();
	test_gpio8();

	printf("[4] Finished program ...\n");

	return 0;
}
