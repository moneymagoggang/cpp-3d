cmake_minimum_required(VERSION 3.31)
project(cpp-3d)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS Graphics Audio REQUIRED)

add_executable(cpp-3d main.cpp
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/World.cpp
        src/World.h
)

target_link_libraries(cpp-3d SFML::Graphics SFML::Audio)

