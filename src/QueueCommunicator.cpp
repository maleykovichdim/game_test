#include "QueueCommunicator.h"


QueueCommunicator::QueueCommunicator() {}

QueueCommunicator::~QueueCommunicator() {}

// Push a message into the communicator
void QueueCommunicator::Push(Role role, const std::string& message) {

    if (role == Role::INITIATOR) {
        std::lock_guard<std::mutex> lock(sendMutex_);
        sendQueue_.push(message);
        sendCV_.notify_one(); // Notify one waiting thread that a message is available
    }else {
        std::lock_guard<std::mutex> lock(receiveMutex_);
        receiveQueue_.push(message);
        receiveCV_.notify_one(); // Notify one waiting thread that a message is available        
    }
}

// Pop a message from the communicator
std::string QueueCommunicator::Pop(Role role) {

    if (role == Role::INITIATOR) {
        std::unique_lock<std::mutex> lock(receiveMutex_);
        receiveCV_.wait(lock, [this] { return !receiveQueue_.empty(); }); // Wait until there's a message

        std::string message = receiveQueue_.front();
        receiveQueue_.pop();
        return message; 
    }else {
        std::unique_lock<std::mutex> lock(sendMutex_);
        sendCV_.wait(lock, [this] { return !sendQueue_.empty(); }); // Wait until there's a message

        std::string message = sendQueue_.front();
        sendQueue_.pop();
        return message; 
    }
}

// Close the communicator (optional method here)
void QueueCommunicator::Close() {}
