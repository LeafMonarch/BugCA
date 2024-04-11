cmake_minimum_required(VERSION 3.27)
project(Classes)

set(CMAKE_CXX_STANDARD 17)

add_executable(Classes main.cpp
        Student.cpp
        Student.h
        DayType.cpp
        DayType.h
        ClockType.cpp
        ClockType.h
        ComplexNumber.h
        ComplexNumber.cpp
        BufferedReader.cpp
        BufferedReader.h)
