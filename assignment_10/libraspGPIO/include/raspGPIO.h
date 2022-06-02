void init_ptrs();

void gpio_get_mode(int pin);
void gpio_set_mode(int pin, int mode);
int gpio_read(int pin);
void gpio_write(int pin, int bit);

void gpio8_get_mode();
void gpio8_set_mode(int mode);
void gpio8_read();
void gpio8_write(int bit);