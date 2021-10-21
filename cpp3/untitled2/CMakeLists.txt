cmake_minimum_required(VERSION 3.17)
project(Almost_v2)

set(CMAKE_CXX_STANDARD 14)

include_directories(../../Downloads/Almost_v2)

add_executable(Almost_v2
        assignment2.cpp
        Client.cpp
        Client.h
        MatchMakingAgency.cpp
        MatchMakingAgency.h
        Menu.cpp
        Menu.h
        String.cpp
        String.h)
