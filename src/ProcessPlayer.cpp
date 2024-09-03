#include "ProcessPlayer.h"

// Constructor initializing the role and communicator
ProcessPlayer::ProcessPlayer(Role role, Communicator* communicator)
    : Player(role, communicator) { }

// Method to send a message
void ProcessPlayer::Send(const std::string& message) {
    communicator_->Push(role_, message); // Use the communicator to send the message
}

// Method to receive a message
std::string ProcessPlayer::Receive() {
    return communicator_->Pop(role_); // Use the communicator to receive the message
}

