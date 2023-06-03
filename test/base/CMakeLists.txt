#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#
set(CONNECTION_ROOT ${CMAKE_SOURCE_DIR}/src/modules/connection/inc)
set(LOG_ROOT ${CMAKE_SOURCE_DIR}/src/common)
set(COMMON_HEADERS_DIR ${CMAKE_SOURCE_DIR}/src/modules/common)
set(MOCKS_DIR ${CMAKE_SOURCE_DIR}/test/mocks)

add_library(moturgateway_test_connection_base STATIC
    ConnectionTestBase.hpp
    TestLogger.hpp

    ConnectionTestBase.cpp
    TestLogger.cpp
)

target_include_directories(moturgateway_test_connection_base
    PUBLIC ${CONNECTION_ROOT}
    PUBLIC ${LOG_ROOT}
    PUBLIC ${COMMON_HEADERS_DIR}
    PUBLIC ${MOCKS_DIR}
)

target_include_directories(moturgateway_test_connection_base
    PUBLIC ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(moturgateway_test_connection_base
    PUBLIC moturgateway_common_log
    PUBLIC moturgateway_connection_module_utils
    PUBLIC GTest::gtest
    PUBLIC GTest::gmock
)
