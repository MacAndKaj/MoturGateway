#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_common_log)

add_library(${LIBNAME} STATIC
    # HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/ILogger.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MainLogger.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/MainLoggerImpl.hpp

    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/MainLogger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/MainLoggerImpl.cpp
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${LIBNAME} PUBLIC MOTUR_DEBUG)
endif()

target_link_libraries(${LIBNAME} 
    PUBLIC moturgateway_common_exceptions
    PUBLIC spdlog::spdlog
)
