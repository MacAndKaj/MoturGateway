#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#
cmake_minimum_required(VERSION 3.5)

project(MoturGateway LANGUAGES CXX)

set(APP_NAME MoturGw)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake-modules)

set(PROJECT_HEADERS_DIR ${CMAKE_SOURCE_DIR}/inc)

find_package(Boost 1.79 REQUIRED system)
if (NOT Boost_FOUND)
    message(ERROR "Boost not found")
endif()

find_package(Bluez REQUIRED)
if (NOT Bluez_FOUND)
    message(ERROR "Boost not found")
endif()

find_package(spdlog REQUIRED)
if (NOT spdlog_FOUND)
    message(ERROR "spdlog not found")
endif()

add_subdirectory(src)

add_executable(MoturGateway app/main.cpp)

