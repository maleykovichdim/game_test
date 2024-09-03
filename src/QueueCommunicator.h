#pragma once

#include "Communicator.h"
#include <queue>
#include <mutex>
#include <condition_variable>

// Class to manage communication using synchronized queues
class QueueCommunicator : public Communicator {
public:
    QueueCommunicator(); 
    ~QueueCommunicator(); 

    void Push(Role role, const std::string& message) override; // Push a message into the communicator
    std::string Pop(Role role) override; // Pop a message from the communicator
    void Close() override; // Close the communicator

private:
    std::queue<std::string> sendQueue_; // Queue for sending messages
    std::queue<std::string> receiveQueue_; // Queue for receiving messages
    std::mutex sendMutex_; // Mutex for send queue
    std::mutex receiveMutex_; // Mutex for receive queue
    std::condition_variable sendCV_; // Condition variable for send queue
    std::condition_variable receiveCV_; // Condition variable for receive queue
};
