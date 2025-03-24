cmake_minimum_required(VERSION 3.30)
project(nasledstvo_clion)

set(CMAKE_CXX_STANDARD 23)

add_executable(nasledstvo_clion main.cpp
        src/Building.cpp
        head/Building.h
        src/Apartment.cpp
        head/Apartment.h
        src/Garage.cpp
        head/Garage.h
        src/House.cpp
        head/House.h
        ../../.mylibs/lifeEasier.hpp
        src/Menu.cpp
        head/Menu.h
        head/Menu.h
)
