cmake_minimum_required(VERSION 3.0)
project(Cake)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cake main.cpp DirMonitor.cpp DirMonitor.h)
