#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(COMMON_HEADERS_DIR ${CMAKE_SOURCE_DIR}/src/common)
set(CONNECTION_MODULE_HEADERS_DIR ${CMAKE_SOURCE_DIR}/src/modules/connection/inc)

add_executable(App${PROJECT_NAME} main.cpp)

target_include_directories(App${PROJECT_NAME}
    PRIVATE ${CONNECTION_MODULE_HEADERS_DIR}
    PRIVATE ${COMMON_HEADERS_DIR}
)

target_link_libraries(App${PROJECT_NAME}
    PRIVATE moturgateway_connection_module
    PRIVATE moturgateway_common_log
)
