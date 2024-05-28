cmake_minimum_required(VERSION 3.27)
project(POO_PROIECT)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(POO_PROIECT
        main.cpp
        clase.hpp
        include/nlohmann/json.hpp)
