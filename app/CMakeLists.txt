#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(CONNECTION_MODULE_HEADERS_DIR ${CMAKE_SOURCE_DIR}/src/modules/connection/inc)

add_executable(App${PROJECT_NAME} main.cpp)

target_include_directories(App${PROJECT_NAME}
    PRIVATE ${CONNECTION_MODULE_HEADERS_DIR}
)

target_link_libraries(App${PROJECT_NAME}
    ${PROJECT_NAME}_connection_module
)
