#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME ${PROJECT_NAME}_bt)

set(FILES
    # HEADERS
    ${PROJECT_HEADERS_DIR}/bt/impl/BluezWrapper.hpp
    ${PROJECT_HEADERS_DIR}/bt/impl/defs.hpp

    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/BluezWrapper.cpp
)


add_library(${LIBNAME} STATIC ${FILES})

target_include_directories(${LIBNAME} PRIVATE
    ${BLUEZ_INCLUDE_DIRS}
    ${PROJECT_HEADERS_DIR}
)

target_link_libraries(${LIBNAME} ${BLUEZ_LIBRARIES})
