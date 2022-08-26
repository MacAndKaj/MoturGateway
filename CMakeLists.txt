cmake_minimum_required(VERSION 3.5)

project(MoturGateway LANGUAGES CXX)

set(APP_NAME MoturGw)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.79 REQUIRED system)

add_subdirectory(src)

add_executable(MoturGateway app/main.cpp)

