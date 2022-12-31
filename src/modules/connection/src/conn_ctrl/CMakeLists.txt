#
# Copyright (C) 2022 MacAndKaj - All Rights Reserved
#

set(LIBNAME moturgateway_connection_module_conn_ctrl)

set(FILES
    # HEADERS
    ${LIBRARY_HEADERS_DIR}/connection/conn_ctrl/hci_ev_handlers/ConnectionCompleteHandler.hpp
    ${LIBRARY_HEADERS_DIR}/connection/conn_ctrl/hci_ev_handlers/InquiryCompleteHandler.hpp

    ${LIBRARY_HEADERS_DIR}/connection/conn_ctrl/ConnectionControl.hpp
    ${LIBRARY_HEADERS_DIR}/connection/conn_ctrl/HandleRecipes.hpp
    ${LIBRARY_HEADERS_DIR}/connection/conn_ctrl/IProcessingQueue.hpp
    ${LIBRARY_HEADERS_DIR}/connection/conn_ctrl/Job.hpp
    ${LIBRARY_HEADERS_DIR}/connection/conn_ctrl/ProcessingQueue.hpp

    # SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/hci_ev_handlers/ConnectionCompleteHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hci_ev_handlers/InquiryCompleteHandler.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionControl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HandleRecipes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Job.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ProcessingQueue.cpp
)

add_library(${LIBNAME} STATIC ${FILES})

target_include_directories(${LIBNAME}
    PRIVATE ${COMMON_HEADERS_DIR}
    PRIVATE ${LIBRARY_HEADERS_DIR}
)

target_link_libraries(${LIBNAME}
    PRIVATE moturgateway_common_log
    PRIVATE moturgateway_common_exceptions
    PRIVATE moturgateway_connection_module_defs
)
