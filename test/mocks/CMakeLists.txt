#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

add_library(moturgateway_test_mocks STATIC
    IConnectionContextMock.hpp
)

target_include_directories(moturgateway_test_mocks
    PUBLIC ${COMMON_HEADERS_DIR}
)

target_include_directories(moturgateway_test_mocks
    PUBLIC ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(moturgateway_test_mocks
    PUBLIC moturgateway_common_log
    PUBLIC GTest::gtest
    PUBLIC GTest::gmock
)
