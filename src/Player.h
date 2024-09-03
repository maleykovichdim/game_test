#pragma once

#include <string>
#include <iostream>
#include "Communicator.h"
#include <atomic>

// Base class for players in the game
class Player {
public:
    // Constructor accepting a role and a communicator for message passing
    Player(Role role, Communicator* communicator) : role_(role), communicator_(communicator), mesCounter(0) {}
    virtual ~Player() = default;

    // Method for sending a message
    void Send(const std::string& message) {
        communicator_->Push(role_, message); // Use the communicator to send the message
    }
    // Method for receiving a message
    std::string Receive() {
        return communicator_->Pop(role_); // Use the communicator to receive the message
    }

    // Function to process 10 messages in a loop, "Main" business logic
    void Run() {
    if (role_ == Role::INITIATOR) {
        for (int i = 0; i < 10; ++i) {
            std::string message = "Message " + std::to_string(i + 1);
            Send(message);
            std::string response = Receive(); 
            std::cout << "Player Initiator received: " << response << std::endl;
        }
    } else {
        for (int i = 0; i < 10; ++i) {
            std::string message = Receive(); 
            std::cout << "Player Receiver received: " << message << std::endl;
            mesCounter++;
            std::string response = message + ". We have: " + std::to_string(mesCounter) + " messages";
            Send(response);
        }
    }
}

protected:
    Role role_; // The role of the player (initiator or receiver)
    Communicator* communicator_; // The communicator used for message passing
    std::atomic<int> mesCounter; //counter of received messages  ( ! atomic is OVERHEAD here, but ....)
};