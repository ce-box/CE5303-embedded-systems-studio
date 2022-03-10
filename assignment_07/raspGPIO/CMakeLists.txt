cmake_minimum_required(VERSION 3.8)
project(HardwareController VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(raspGPIO SHARED src/raspGPIO.c)

target_include_directories(${PROJECT_NAME} PRIVATE src include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
