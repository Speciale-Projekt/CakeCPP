cmake_minimum_required(VERSION 3.0)
project(Cake)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cake main.cpp Communication/FromOT/DirMonitor.cpp Communication/FromOT/DirMonitor.h Communication/ToOT/TalkToOT.h Communication/OTProtocolMessage.h)
