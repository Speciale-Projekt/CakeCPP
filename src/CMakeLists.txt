cmake_minimum_required(VERSION 3.0)
project(Cake)

set(CMAKE_CXX_STANDARD 20)

include_directories(../include)
add_executable(Cake main.cpp mle/mle.cpp mle/mle.h mle/tlv.cpp mle/tlv.h)