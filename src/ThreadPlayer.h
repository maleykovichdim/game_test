#pragma once

#include "Player.h"
#include <atomic>
#include <thread>
#include <chrono>
#include <iostream>

// Derived class for players operating in threads
class ThreadPlayer : public Player {
public:
    // Constructor accepting role and communicator
    ThreadPlayer(Role role, Communicator* communicator);
    
    // Overrides the Send method to send messages
    void Send(const std::string& message) override;
    
    // Overrides the Receive method to receive messages
    std::string Receive() override;

};
