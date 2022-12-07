#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(TEST_TARGET HciAsyncTests)
set(CONNECTION_ROOT ${CMAKE_SOURCE_DIR}/src/modules/connection/inc)

add_executable(${TEST_TARGET}
    SubscriptionsStorageTests.cpp
)

target_include_directories(${TEST_TARGET} PUBLIC ${CONNECTION_ROOT})
target_include_directories(${TEST_TARGET} PUBLIC ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

target_link_libraries(${TEST_TARGET}
    PRIVATE moturgateway_connection_module_hci_async
    PRIVATE gtest
    PRIVATE gmock
    PRIVATE gtest_main
    PRIVATE pthread
)
