cmake_minimum_required(VERSION 3.22)
project(shareVideo)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/headers)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/libraries)

set(JSON_LIB_DIR ${LIB_DIR}/nlohmann)

set(SOURCE_FILES main.cpp
        ${SOURCES_DIR}/server/TCPServer.cpp)

set(HEADER_FILES ${HEADERS_DIR}/server/TCPServer.hpp ${JSON_LIB_DIR}/json.hpp)

include_directories(${PROJECT_NAME} ${JSON_LIB_DIR})

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
