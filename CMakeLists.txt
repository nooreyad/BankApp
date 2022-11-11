cmake_minimum_required(VERSION 3.23)
project(OOP_Assignment_2_BankApp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_Assignment_2_BigReal
        BankSystem.cpp
        BankSystem.h
        main.cpp)
