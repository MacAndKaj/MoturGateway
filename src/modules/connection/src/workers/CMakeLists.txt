#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_connection_module_workers)

set(FILES 
    # HEADERS
    ${LIBRARY_HEADERS_DIR}/connection/workers/ConnectionManager.hpp
    ${LIBRARY_HEADERS_DIR}/connection/workers/HciAsyncEventsDispatcher.hpp
    ${LIBRARY_HEADERS_DIR}/connection/workers/HciMessenger.hpp
    ${LIBRARY_HEADERS_DIR}/connection/workers/IWorker.hpp

    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HciAsyncEventsDispatcher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HciMessenger.cpp
)

add_library(${LIBNAME} STATIC ${FILES})

target_include_directories(${LIBNAME}
    PRIVATE ${LIBRARY_HEADERS_DIR}
)

target_link_libraries(${LIBNAME}
    PRIVATE moturgateway_connection_module_hci_async
)
