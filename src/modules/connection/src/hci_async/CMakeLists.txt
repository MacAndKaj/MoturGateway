#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_connection_module_hci_async)

set(FILES
    # HEADERS
    ${LIBRARY_HEADERS_DIR}/connection/hci_async/HciEventsSocket.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci_async/ISubscriptionsStorage.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci_async/SubscriptionsStorage.hpp

    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/HciEventsSocket.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SubscriptionsStorage.cpp
)

add_library(${LIBNAME} STATIC ${FILES})

target_include_directories(${LIBNAME}
    PRIVATE ${BLUEZ_INCLUDE_DIRS}
    PRIVATE ${COMMON_HEADERS_DIR}
    PRIVATE ${LIBRARY_HEADERS_DIR}
)

target_link_libraries(${LIBNAME}
    PRIVATE ${BLUEZ_LIBRARIES}
    PRIVATE moturgateway_common_log
    PRIVATE moturgateway_common_exceptions
)
