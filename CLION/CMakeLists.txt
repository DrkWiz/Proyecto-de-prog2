cmake_minimum_required(VERSION 3.24)
project(CLION)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(librerias)

add_executable(CLION
        librerias/librerias.txt
        clion.txt
        main.cpp librerias/tablero.h librerias/tablero.cpp librerias/coordenada.h librerias/coordenada.cpp librerias/casilla.h librerias/casilla.cpp librerias/barco.cpp librerias/barco.h)
