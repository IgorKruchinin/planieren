cmake_minimum_required(VERSION 3.23)
project(planieren)

set(CMAKE_CXX_STANDARD 17)

add_executable(planieren main.cpp libplanieren/PlanierenStorage.cpp libplanieren/PlanierenStorage.h libplanieren/USM/USM.cpp libplanieren/USM/macro_config.h libplanieren/USM/Section.cpp libplanieren/USM/Section.h libplanieren/USM/config.h libplanieren/USM/USM.h)
