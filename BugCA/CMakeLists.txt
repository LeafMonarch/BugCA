cmake_minimum_required(VERSION 3.27)
project(BugCA)

set(CMAKE_CXX_STANDARD 17)

add_executable(BugCA main.cpp
        Bug.cpp
        Hopper.h
        Hopper.cpp
        Crawler.cpp
        Board.h
        Board.cpp
        Leaf_Hopper.h
        Leaf_Hopper.cpp
        Super_Bug.h
        Super_Bug.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6.1/include)
target_link_libraries(BugCA sfml-system sfml-window sfml-graphics sfml-audio)