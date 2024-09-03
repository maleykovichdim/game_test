#pragma once

#include <string>

// Enum to define the role of players
enum class Role {
    INITIATOR, // The player who initiates communication
    RECEIVER   // The player who receives communication
};

// Base class for communication between players
class Communicator {
public:
    virtual ~Communicator() {}

    // Push a message into the communicator from a player with a specific role
    virtual void Push(Role role, const std::string& message) = 0;
    
    // Pop a message from the communicator for a player with a specific role
    virtual std::string Pop(Role role) = 0;
    
    // Close the communication channels
    virtual void Close() = 0;
};
