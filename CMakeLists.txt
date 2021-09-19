cmake_minimum_required(VERSION 3.20)
project(battleShip)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(battleShip
        .idea/.gitignore
        .idea/battleShip.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        documentation/meetings.txt
        documentation/work-hours.txt
        documentation/works-cited.txt
        Executive.cpp
        Executive.h
        Game.cpp
        Game.h
        Grid.cpp
        Grid.h
        main.cpp
        Makefile
        Notes_And_Classes.txt
        README.md)
