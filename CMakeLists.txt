cmake_minimum_required(VERSION 3.20)
project(arjan_observer_pattern)

set(CMAKE_CXX_STANDARD 20)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else ()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif ()

include_directories(
        lib
        api
        api2
)

add_library(slack INTERFACE lib/slack.h)

add_executable(plain plain.cpp)
target_link_libraries(plain ${CONAN_LIBS})

add_executable(event_driven event_driven.cpp)
target_link_libraries(event_driven ${CONAN_LIBS})