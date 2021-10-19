cmake_minimum_required(VERSION 3.20)
project(arjan_observer_pattern)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        lib
        api
)

add_library(slack INTERFACE lib/slack.h)
add_library(log INTERFACE lib/log.h)
add_library(user INTERFACE lib/user.h)
add_library(database INTERFACE lib/database.h)
add_library(email INTERFACE lib/email.h)

add_library(user_management INTERFACE api/user_management.h)

add_executable(plain main.cpp)
