#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_common_exceptions)

add_library(${LIBNAME} STATIC
    # HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/IMoturException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InitializationException.hpp
	

    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/InitializationException.cpp
)

target_include_directories(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
