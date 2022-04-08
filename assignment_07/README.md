# Taller 7

## Raspberry PI GPIO Library

**Estudiantes:** Gabriel Abarca, Esteban Alvarado, María Ávila, Olman Castro
**Carnés:** 2017110442, 2018109336, 2014089607, 2016003615
***

### Investigación 📋

**4.1.** **¿Qué pasos debe seguir antes de escribir o leer de un puerto de entrada/salida general (GPIO)?**

Los pasos necesarios a seguir son [1]:

1. Exportar el pin.
2. Establecer la dirección del pin (entrada o salida).
3. Si es un pin de salida, establecer el nivel en bajo o alto.
4. Si es un pin de entrada, leer el nivel del pin (bajo o alto).
5. Al finalizar, retirar el pin.

**4.2.** **¿Qué comando podría utilizar, bajo Linux, para escribir a un GPIO específico?**

Es importante mencionar que debe realizarse la configuración de los puntos anteriores para llegar a utilizar este comando. El comando necesario para escribir en Linux es [2]:

```bash
echo 1 > /sys/class/gpio/gpio24/value
```

### ¿Cómo construir la aplicación? 🗃

1. Descomprima el archivo `libraspgpio-1.0.tar.gz`

2. Ingrese al directorio `libraspgpio-1.0` con el comando: `cd libraspgpio-1.0`

3. Cree un directorio `build` y dentro de este otro directorio llamado `usr`.

4. Configure las variables de entorno para la compilación cruzada: `. /opt/poky/3.1.2/environment-setup-cortexa7t2hf-neon-vfpv4-poky-linux-gnueabi`

5. Pruebe el entorno de compilación con el comando `echo $CC`, la salida debe ser similar a la siguiente:

```text
La salida :3
```

6. Cambie el valor de `CC` en el archivo de configuración de compilación cruzada por `arm-poky-linux-gnueabi`.

7. Ejecute el comando para configurar el compilador cruzado: `../configure --prefix=$(pwd)/usr/ --host=arm-poky-linux-gnueabi`

8. Construya e instale la aplicación:

```sh
make
make install
```

9. Para ejecutar el programa en la tarjeta **RaspberryPi**, copie el directorio `usr` en la *raiz del sistema de archivos* del sistema operativo de la placa y para ejecutar la aplicación dentro de la RaspberryPi, corra el ejecutable `gpio_test` que se encuentra en el directorio `usr/bin`.

### Referencias 📑

>[1] Compuhoy, "¿Cómo accedo a Gpio en Linux?", 2022. [Online]. https://www.compuhoy.com/como-accedo-a-gpio-en-linux/ [Accessed: April 07, 2022].

>[2] ICS (J. Tranter), "GPIO Programming: Using the sysfs Interface", 2019. [Online]. https://www.ics.com/blog/gpio-programming-using-sysfs-interface [Accessed: April 07, 2022].

***

<p align="center">
<img src="https://static.platzi.com/media/achievements/badge-programacion-microcontroladores-pic-c-d3093418-a0e3-4b95-a6c2-77cf06af37f9.png" width="75"/>
</p>