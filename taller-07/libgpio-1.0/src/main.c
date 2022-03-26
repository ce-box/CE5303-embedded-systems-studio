#include <gpio.h>

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // Se habilitan los pines
    printf("Se van a habilitar los pines 2, 3 y 4\n");
    enablePin(2);
    enablePin(3);
    enablePin(4);
    printf("Se habilitaron los pines 2, 3 y 4 exitosamente\n");

    // Se configuran los pines 2 y 3 como salidas
    printf("Se van a configurar los pines 2 y 3 como salidas\n");
    pinMode(2, "out");
    pinMode(3, "out");
    printf("Se configuraron los pines 2 y 3 como salidas exitosamente\n");

    // Se configura el pin 4 como entrada
    printf("Se va a configurar el pin 4 como entrada\n");
    pinMode(4, "in");
    printf("Se configuro el pin 4 como entrada exitosamente\n");

    // Se escriben valores al pin 2
    printf("Se van a escribir valores al pin 2\n");
    printf("Se va a escribir un 1\n");
    digitalWrite(2, 1);
    sleep(2);
    printf("Se va a escribir un 0\n");
    digitalWrite(2, 0);
    sleep(2);
    printf("Se va a escribir un 1\n");
    digitalWrite(2, 1);
    sleep(2);
    printf("Se va a escribir un 1\n");
    digitalWrite(2, 1);
    sleep(2);
    printf("Se va a escribir un 1\n");
    digitalWrite(2, 1);
    sleep(2);
    printf("Se va a escribir un 0\n");
    digitalWrite(2, 0);
    sleep(2);
    printf("Se va a escribir un 0\n");
    digitalWrite(2, 0);
    sleep(2);
    printf("Se va a escribir un 1\n");
    digitalWrite(2, 1);
    sleep(2);
    printf("Se va a escribir un 0\n");
    digitalWrite(2, 0);
    sleep(2);
    printf("Se escribieron los valores al pin 2 exitosamente\n");

    // Se configura el pin 3 para utilizar la funcion de blink, a 1000 Hz por 5 segundos
    printf("Se va a colocar el pin 3 a parpadear a 1000 Hz por 5 segundos\n");
    blink(3, 1000, 5);
    printf("El parpadeo fue completado exitosamente\n");

    // Se lee el pin 4 y se muestra en pantalla lo leído por los proximos 10 segundos
    printf("Se va a leer los datos del pin 4 por los proximos 10 segundos\n");
    int value;
    time_t startTime = time(0);

    while ((time(0) - startTime) < 10) {
        value = digitalRead(4);
        printf("Valor leído: %d\n", value);
    }
    printf("Se leyeron los datos del pin 5 exitosamente\n");

    // Se deshabilitan los pines
    printf("Se van a deshabilitar los pines 2, 3 y 4\n");
    disablePin(2);
    disablePin(3);
    disablePin(4);
    printf("Se deshabilitaron los pines 2, 3 y 4 exitosamente\n");

    printf("Fin de Ejecucion\n");

    return 0;
}