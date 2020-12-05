cmake_minimum_required(VERSION 3.0.0)

project(Macierz)

include_directories(./include ./src)

add_executable(output ./src/main.cpp ./src/matrix.cpp)