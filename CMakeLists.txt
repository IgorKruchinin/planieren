cmake_minimum_required(VERSION 3.23)
project(planieren)

set(CMAKE_CXX_STANDARD 14)

add_executable(planieren main.cpp libplanieren/PlanierenStorage.cpp libplanieren/PlanierenStorage.h)
