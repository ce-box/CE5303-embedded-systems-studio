# CE5303-embedded-systems-studio
Repository with the works, practices and lectures of the embedded systems (CE5303) course 🤖

## Teoría 📋

_¿Qué pasos debe seguir antes de escribir o leer de un puerto de entrada/salida general
(GPIO)?_

1. Exportar el pin.
2. Establecer la dirección del pin (entrada o salida).
3. Si es un pin de salida, establecer el nivel en bajo o alto.
4. Si es un pin de entrada, leer el nivel del pin (bajo o alto).
5. Al finbalizar, retirar el pin.

_¿Qué comando podría utilizar, bajo Linux, para escribir a un GPIO específico?_

Es importante mencionar que debe realizarse la configuración de los puntos anteriores para llegar a utilizar este comando.

```
echo 1 > /sys/class/gpio/gpio24/value
```

## Autores ✒️

- **Olman Castro** [2016003615]
- **Esteban Alvarado** [2018109336]
- **Gabriel Abarca** [2017110442]
- **María Ávila** [2014089607]
