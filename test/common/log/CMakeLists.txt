#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(TEST_TARGET LogTests)
set(LOG_ROOT ${CMAKE_SOURCE_DIR}/src/modules/common/log)

add_executable(${TEST_TARGET}
    MainLoggerTests.cpp
)

target_include_directories(${TEST_TARGET} PUBLIC ${LOG_ROOT})
target_include_directories(${TEST_TARGET} PUBLIC ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

target_link_libraries(${TEST_TARGET} 
    PRIVATE moturgateway_common_log
    PRIVATE gtest
    PRIVATE gmock
    PRIVATE gtest_main
    PRIVATE pthread
)
