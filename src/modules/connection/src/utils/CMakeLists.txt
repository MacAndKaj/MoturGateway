#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_connection_module_utils)

set(FILES
    # HEADERS
    ${LIBRARY_HEADERS_DIR}/connection/utils/IConnectionContext.hpp
    ${LIBRARY_HEADERS_DIR}/connection/utils/ConnectionContext.hpp

    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionContext.cpp
)

add_library(${LIBNAME} STATIC ${FILES})

target_include_directories(${LIBNAME}
    PRIVATE ${LIBRARY_HEADERS_DIR}
    ${COMMON_HEADERS_DIR}
)

target_link_libraries(${LIBNAME}
    PRIVATE moturgateway_common_log
)
