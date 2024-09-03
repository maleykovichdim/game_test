cmake_minimum_required(VERSION 3.10)
project(PlayerComm)

set(CMAKE_CXX_STANDARD 17)

# Add the source files located in the src directory
add_executable(PlayerComm
    src/main.cpp
    src/Communicator.h
    src/Player.h
    src/PipeCommunicator.h
    src/PipeCommunicator.cpp
    src/QueueCommunicator.h
    src/QueueCommunicator.cpp
)
