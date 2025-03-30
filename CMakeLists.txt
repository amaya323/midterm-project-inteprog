cmake_minimum_required(VERSION 3.29)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Library_Management_System main.cpp
        Class/Book.cpp
        Class/Book.h
        Class/Library.cpp
        Class/Library.h
        Function.cpp
        Function.h
        Class/NonFictionBook.cpp
        Class/NonFictionBook.h
        Class/FictionBook.cpp
        Class/FictionBook.h)
