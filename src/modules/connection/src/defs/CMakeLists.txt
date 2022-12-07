#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_connection_module_defs)

set(FILES
    # HEADERS
    ${LIBRARY_HEADERS_DIR}/connection/defs/BtDeviceAddress.hpp
    ${LIBRARY_HEADERS_DIR}/connection/defs/HciTypes.hpp

    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/BtDeviceAddress.cpp
)

add_library(${LIBNAME} STATIC ${FILES})

target_include_directories(${LIBNAME}
    PRIVATE ${BLUEZ_INCLUDE_DIRS}
    PRIVATE ${LIBRARY_HEADERS_DIR}
    PRIVATE ${COMMON_HEADERS_DIR}
)

target_link_libraries(${LIBNAME}
    PRIVATE ${BLUEZ_LIBRARIES}
)
