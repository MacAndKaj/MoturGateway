#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_connection_module_hci)

set(FILES
    # HEADERS
    ${LIBRARY_HEADERS_DIR}/connection/hci/HciObjectsBuilder.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/HciPoller.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/HciSocket.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/IHciObjectsBuilder.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/IHciSocket.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/IRequestsExecutionQueue.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/ISubscriptionsStorage.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/HciRequestExecutor.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/RequestsExecutionQueue.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/SubscriptionGuard.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/SubscriptionsStorage.hpp

    ${LIBRARY_HEADERS_DIR}/connection/hci/handlers/IReqHandler.hpp
    ${LIBRARY_HEADERS_DIR}/connection/hci/handlers/ReadBDAddrHandler.hpp



    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/HciObjectsBuilder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HciPoller.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HciRequestExecutor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HciSocket.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RequestsExecutionQueue.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SubscriptionGuard.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SubscriptionsStorage.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/handlers/ReadBDAddrHandler.cpp
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
    PRIVATE moturgateway_connection_module_defs
)
