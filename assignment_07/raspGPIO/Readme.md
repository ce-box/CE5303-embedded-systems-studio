Please Install Arm Compiler:
```
    sudo apt-get install gcc-arm-linux-gnueabihf
```

ARM:
```
    cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/bin/arm-linux-gnueabihf-gcc-9 "-H/mnt/c/Users/gabab/Documents/Universidad/Sistemas Embebidos/Proyectos/Smart Home Control System/Server/HardwareController" "-B/mnt/c/Users/gabab/Documents/Universidad/Sistemas Embebidos/Proyectos/Smart Home Control System/Server/HardwareController/build" -G "Unix Makefiles"
    cmake --build "/mnt/c/Users/gabab/Documents/Universidad/Sistemas Embebidos/Proyectos/Smart Home Control System/Server/HardwareController/build" --config Debug --target all -j 10 --
```

x86:
```
    cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/bin/x86_64-linux-gnu-gcc-9 -DCMAKE_CXX_COMPILER:FILEPATH=/bin/x86_64-linux-gnu-g++-9 "-H/mnt/c/Users/gabab/Documents/Universidad/Sistemas Embebidos/Proyectos/Smart Home Control System/Server/HardwareController" "-B/mnt/c/Users/gabab/Documents/Universidad/Sistemas Embebidos/Proyectos/Smart Home Control System/Server/HardwareController/build" -G "Unix Makefiles"
    cmake --build "/mnt/c/Users/gabab/Documents/Universidad/Sistemas Embebidos/Proyectos/Smart Home Control System/Server/HardwareController/build" --config Debug --target all -j 10 --
```