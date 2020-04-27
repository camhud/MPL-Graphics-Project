cmake_minimum_required(VERSION 3.15)
project(BL_CH_CW_JS_Final_Project_Graphics)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(BL_CH_CW_JS_Final_Project_Graphics
        Album.cpp
        Album.h
        main.cpp
        Song.cpp
        Song.h)

add_executable(graphics graphics.cpp)
