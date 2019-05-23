cmake_minimum_required(VERSION 3.14)
project(LibraryManagement)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManagement main.cpp Book.cpp Book.h BookList.cpp BookList.h utils.cpp utils.h opearation.h Operation.cpp Operation.h)