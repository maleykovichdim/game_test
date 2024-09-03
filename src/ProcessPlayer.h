#pragma once

#include "Player.h"
#include <unistd.h>
#include <iostream>
#include <string>

// Derived class for players operating in processes
class ProcessPlayer : public Player {
public:
    // Constructor accepting role and communicator
    ProcessPlayer(Role role, Communicator* communicator);
    
    // Overrides the Send method to send messages
    void Send(const std::string& message) override;
    
    // Overrides the Receive method to receive messages
    std::string Receive() override;
};
