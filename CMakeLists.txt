cmake_minimum_required(VERSION 3.31)
project(cpp-3d)

set(CMAKE_CXX_STANDARD 20)
set(SFML_STATIC_LIBRARIES OFF)

find_package(SFML COMPONENTS Graphics Audio REQUIRED)

# Fetch ImGui
include(FetchContent)
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.91.5
)
FetchContent_MakeAvailable(imgui)

# Fetch ImGui-SFML
set(IMGUI_DIR ${imgui_SOURCE_DIR})
set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_Declare(
    imgui-sfml
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
    GIT_TAG master
)
FetchContent_MakeAvailable(imgui-sfml)
target_link_libraries(ImGui-SFML PUBLIC SFML::Graphics)

add_executable(cpp-3d main.cpp
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/engine/Debug.cpp
        src/engine/Debug.h
        src/Player.cpp
        src/Player.h
        src/World.cpp
        src/World.h
)

target_link_libraries(cpp-3d SFML::Graphics SFML::Audio ImGui-SFML::ImGui-SFML)

