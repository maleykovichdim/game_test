#include "ThreadPlayer.h"

// Constructor initializing the role and communicator
ThreadPlayer::ThreadPlayer(Role role, Communicator* communicator)
    : Player(role, communicator) {}

// Method to send a message
void ThreadPlayer::Send(const std::string& message) {
    communicator_->Push(role_, message); // Use the communicator to send the message
}

// Method to receive a message
std::string ThreadPlayer::Receive() {
    std::string res = communicator_->Pop(role_);
    return res; // Use the communicator to receive the message
}



