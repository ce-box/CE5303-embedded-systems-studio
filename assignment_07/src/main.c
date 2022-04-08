#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raspGPIO.h"

void setup()
{
    putenv("SYS_PATH=/sys/class/gpio");

    // Enable pins
    for (int pin = 2; pin <= 4; pin++)
    {
        enablePin(pin);
        printf("Pin %d enabled ...\n", pin);
    }

    // Inputs
    pinMode(2, INPUT);
    printf("Pin 2: INPUT ...\n");

    pinMode(3, OUTPUT);
    printf("Pin 3: OUTPUT ...\n");

    pinMode(4, OUTPUT);
    printf("Pin 4: OUTPUT ...\n");
}

void loop()
{
    // LED 1: Start routine
    digitalWrite(3, HIGH);
    printf("LED 1: ON ...\n");
    sleep(2);
    digitalWrite(3, LOW);
    printf("LED 1: OFF ...\n");
    sleep(2);

    // LED 2: Blink
    printf("LED 2: Start Blink ...\n");
    blink(4, 1000, 5);
    printf("LED 2: Finish Blink ...\n");

    // Get input
    int maxTime = 15;
    time_t start = time(0);

    while ((time(0) - start) < maxTime)
    {
        printf("Pin 2 -> Value: %d ...\n", digitalRead(2));
    }

    // LED 1: Ending routine
    digitalWrite(3, HIGH);
    printf("LED 1: ON ...\n");
    sleep(2);
    digitalWrite(3, LOW);
    printf("LED 1: OFF ...\n");
    sleep(2);
}

void shutdown()
{
    // Disable pins
    for (int pin = 2; pin <= 4; pin++)
    {
        disablePin(pin);
        printf("Pin %d disabled ...\n", pin);
    }
}

int main(int argc, char const *argv[])
{
    setup();
    loop();
    shutdown();
    return 0;
}
