cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS Graphics Audio REQUIRED)

add_executable(untitled main.cpp
        src/engine/Engine.cpp
        src/engine/Engine.h
)

target_link_libraries(untitled SFML::Graphics SFML::Audio)

