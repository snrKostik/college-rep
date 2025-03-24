cmake_minimum_required(VERSION 3.30)
project(inter_clion)

set(CMAKE_CXX_STANDARD 23)

add_executable(inter_clion main.cpp
        src/consonant.cpp
        src/interface.cpp
        src/vovel.cpp
        include/consonant.hpp
        include/interface.hpp
        include/vovel.hpp
        ../../.mylibs/lifeEasier.hpp

)
