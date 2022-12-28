#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_common_exceptions)

add_library(${LIBNAME} STATIC
    # HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/IMoturException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InitializationException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ItemNotRetrievedException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UnknownFailureException.hpp
	

    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/InitializationException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ItemNotRetrievedException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UnknownFailureException.cpp
)

target_include_directories(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
