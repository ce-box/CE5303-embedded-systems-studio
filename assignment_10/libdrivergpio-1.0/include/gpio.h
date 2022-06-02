// GPIO driver headers

void init_ptrs();

void sgpio_get_mode(int pinNum);
void sgpio_set_mode(int pinNum, int mode);
int gpio_read(int pinNum);
void gpio_write(int pinNum, int bit);

void gpio8_get_mode();
void gpio8_set_mode(int mode);
void gpio8_read();
void gpio8_write(int bit);