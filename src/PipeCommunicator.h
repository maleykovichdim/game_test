#pragma once

#include "Communicator.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>

class PipeCommunicator : public Communicator {
public:
    PipeCommunicator(); // Constructor that sets up pipes
    ~PipeCommunicator(); // Destructor to clean up pipes

    void Push(Role role, const std::string& message) override; // Method to send a message
    std::string Pop(Role role) override; // Method to receive a message
    void Close() override; // Method to close the pipes

private:
    int pipes[2][2]; // Two pipes for communication

};

