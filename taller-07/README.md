Kevin Cordero Zúñiga - 2018088034

Respuestas a las Preguntas:

1. ¿Por qué no debería verse ’Hello World!’? ¿Qué quiere decir la salida de la aplicación?
- Porque el programa se compiló utilizando compilación cruzada. Esto quiere decir, que la aplicación está destinada a ser ejecutada en
arquitecturas ARM como la Raspberry Pi 2. Al intentar ejecutarse el programa, sale el siguiente mensaje:
"cannot execute binary file", esto sucede porque se está intentando ejecutar la aplicación en una arquitectura x86.

2. ¿Cuál es la salida del programa al ejecutar en la Raspberry Pi? ¿Qué quiere decir?
- La salida del programa es Hello World, esto quiere decir que el programa se ejecutó correctamente, ya que se ejecutó en una
arquitectura ARM.

3. ¿Qué pasos debe seguir antes de escribir o leer de un puerto de entrada/salida general (GPIO)?
- Antes de escribir o leer de un puerto de entrada/salida general, es necesario habilitar los puertos a utilizar y designar la operación específica de cada puerto (una entrada
o una salida), una vez hecho esto, es posible leer o escribir en este.

4. ¿Qué comando podría utilizar, bajo Linux, para escribir a un GPIO específico?
- Se puede utilizar el comando gpio, que se encuentra incluido con la biblioteca WiringPi.

- Información tomada de: http://wiringpi.com/the-gpio-utility/ y https://jnjsite.com/raspberry-pi-el-manejo-basico-del-gpio-con-sysfs/

¿Cómo se debe construir la aplicación?

1. Descomprimir el archivo libgpio-1.0.tar.gz con el siguiente comando: tar -xvf libgpio-1.0.tar.gz
2. Ingresar al directorio de libgpio-1.0 con el comando: cd libgpio-1.0
3. Crear un directorio llamado build e ingresar a este: mkdir build && cd build
4. Crear un directorio llamado usr: mkdir usr
5. Ejecute el siguiente comando para inicializar las variables de entorno para la compilación cruzada: . /opt/poky/3.1.2/environment-setup-cortexa7t2hf-neon-vfpv4-poky-linux-gnueabi
6. Ejecute el comando echo $CC para comprobar que las variables de ambiente son correctas
7. Ejecute el siguiente comando para acceder al archivo de configuración de compilación cruzada: gedit /opt/poky/3.1.2/environment-setup-cortexa7t2hf-neon-vfpv4-poky-linux-gnueabi
8. Busque la linea que inicia con export CC y copie la variable arm-poky-linux-gnueabi (puede variar dependiendo el caso)
9. Ejecute el siguiente comando: ../configure --prefix=/home/usuario/libgpio-1.0/build/usr/ --host=arm-poky-linux-gnueabi
10. Ejecute el comando make
11. Ejecute el comando make install
12. Para ejecutar el programa en la Raspberry Pi, copie la carpeta usr y ejecute el programa main dentro de la carpeta bin