cmake_minimum_required(VERSION 3.29)
project(Shell_v2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Shell_v2
        comandos.c
        comandos.h
        signals.c
        signals.h
        customCom.c
        customCom.h
        favoritos.h
        favoritos.c
        main.c)
