cmake_minimum_required(VERSION 3.15)
project(pr12)

set(CMAKE_CXX_STANDARD 14)

add_executable(pr12 src/main.cpp src/Monedero/Monedero.cpp src/Monedero/Monedero.h
        src/UnidadMonetaria/UnidadMonetaria.cpp src/UnidadMonetaria/UnidadMonetaria.h)