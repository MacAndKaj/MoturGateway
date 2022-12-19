#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_connection_module)

add_subdirectory(defs)
add_subdirectory(hci)
add_subdirectory(utils)
add_subdirectory(workers)

set(FILES 
    ${LIBRARY_HEADERS_DIR}/connection/ConnectionModule.hpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionModule.cpp
)

add_library(${LIBNAME} STATIC ${FILES})

target_include_directories(${LIBNAME}
    PRIVATE ${BLUEZ_INCLUDE_DIRS}
    PRIVATE ${LIBRARY_HEADERS_DIR}
    PRIVATE ${COMMON_HEADERS_DIR}
)

target_link_libraries(${LIBNAME}
    PRIVATE moturgateway_connection_module_workers
)
