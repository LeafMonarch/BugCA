cmake_minimum_required(VERSION 3.21)
project(SFML_Demo1)

set(CMAKE_CXX_STANDARD 11)

add_executable(SFML_Demo1 main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6.1/include)
target_link_libraries(SFML_Demo1 sfml-system sfml-window sfml-graphics sfml-audio)