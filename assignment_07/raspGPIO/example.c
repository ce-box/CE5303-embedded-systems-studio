#include "include/raspGPIO.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    char *sysPath = getenv("SYS_PATH");
    printf("%s\n", sysPath);
    for (int pin = 1; pin < 10; pin++)
    {
        // Enable pin
        enablePin(pin);
        printf("pin enabled ...\n");
        
        // Set pin mode
        if (pin % 2 == 0)
        {
            pinMode(pin, OUTPUT);
            printf("pin set as OUTPUT ...\n");
        } else {
            pinMode(pin, INPUT);
            printf("pin set as INPUT ...\n");
        }

        // Write on outputs
        if (pin % 2 == 0)
        {
            int value = HIGH; //rand() % 2;
            //printf("%d\n", value);
            digitalWrite(pin, value);
            printf("pin value set to %d ...\n", value);
        }
        
        // Read pin value
        printf("pin %d : %d\n", pin, digitalRead(pin));
        
        // Disable pin
        disablePin(pin);
        printf("pin disabled ...\n");
    }
    return 0;
}
