#include "PipeCommunicator.h"

// Constructor that sets up the pipes
PipeCommunicator::PipeCommunicator() {
    pipe(pipes[0]); // Pipe for messages
    pipe(pipes[1]); // Pipe for responses
}

//
PipeCommunicator::~PipeCommunicator() {
    //Close(); //TODO: change design for other architect. 
}

// Method to send a message
void PipeCommunicator::Push(Role role, const std::string& message) {
    if (role == Role::INITIATOR) {
        write(pipes[0][1], message.c_str(), message.size() + 1); // Write to pipe for messages
    } else {
        write(pipes[1][1], message.c_str(), message.size() + 1); // Write to pipe for responses
    }
}

// Method to receive a message
std::string PipeCommunicator::Pop(Role role) {
    char buffer[128];
    if (role == Role::INITIATOR) {
        read(pipes[1][0], buffer, sizeof(buffer)); // Read from pipe for responses
    } else {
        read(pipes[0][0], buffer, sizeof(buffer)); // Read from pipe for messages
    }
    return std::string(buffer); // Return the received message
}

// Method to close the pipes
void PipeCommunicator::Close() {
    close(pipes[0][0]);
    close(pipes[0][1]);
    close(pipes[1][0]);
    close(pipes[1][1]);
}
