#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(TEST_TARGET MainLoggerTests)
set(LOG_ROOT ${CMAKE_SOURCE_DIR}/src/modules/common/log)

add_executable(${TEST_TARGET}
    MainLoggerTests.cpp
)

target_include_directories(${TEST_TARGET} PUBLIC ${LOG_ROOT})
target_include_directories(${TEST_TARGET} PUBLIC ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

target_link_libraries(${TEST_TARGET} 
    PUBLIC moturgateway_common_log
    PUBLIC GTest::gtest
    PUBLIC GTest::gmock
    PUBLIC gtest_main
    PUBLIC pthread
)

add_test(Common_Log_${TEST_TARGET} ${TEST_TARGET})
