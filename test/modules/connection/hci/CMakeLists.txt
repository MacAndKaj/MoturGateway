#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(TEST_TARGET SubscriptionsStorageTests)
set(CONNECTION_ROOT ${CMAKE_SOURCE_DIR}/src/modules/connection/inc)
set(COMMON_HEADERS_DIR ${CMAKE_SOURCE_DIR}/src/modules/common)

set(TEST_BASE_DIR ${CMAKE_SOURCE_DIR}/test/base)
set(MOCKS_DIR ${CMAKE_SOURCE_DIR}/test/mocks)

add_executable(${TEST_TARGET}
    SubscriptionsStorageTests.cpp
)

target_include_directories(${TEST_TARGET}
    PUBLIC ${CONNECTION_ROOT}
    PUBLIC ${COMMON_HEADERS_DIR}
    PUBLIC ${TEST_BASE_DIR}
    PUBLIC ${MOCKS_DIR}
)

target_include_directories(${TEST_TARGET}
    PUBLIC ${GTEST_INCLUDE_DIRS}
    PUBLIC ${GMOCK_INCLUDE_DIRS}
)

target_link_libraries(${TEST_TARGET}
    PUBLIC moturgateway_connection_module_hci
    PUBLIC moturgateway_connection_module_utils
    PUBLIC moturgateway_common_log

    PUBLIC moturgateway_test_connection_base

    PUBLIC GTest::gtest
    PUBLIC GTest::gmock
    PUBLIC GTest::gtest_main
    PUBLIC pthread
)

add_test(Connection_HciAsync_${TEST_TARGET} ${TEST_TARGET})
