#include "ThreadPlayer.h"
#include "ProcessPlayer.h"
#include "PipeCommunicator.h"
#include "QueueCommunicator.h"
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <future>

// Function to run players in threads using a QueueCommunicator
void runThreadPlayers() {
    QueueCommunicator communicator; // Use QueueCommunicator for thread mode

    ThreadPlayer player1(Role::INITIATOR, &communicator); // Initiator player
    ThreadPlayer player2(Role::RECEIVER, &communicator); // Receiver player

    // Start both players asynchronously
    auto future1 = std::async(&ThreadPlayer::Run, &player1); // Start the initiator in a new thread
    auto future2 = std::async(&ThreadPlayer::Run, &player2); // Start the receiver in a new thread

    // Wait for both players to finish
    future1.get(); // Wait for the initiator to finish
    future2.get(); // Wait for the receiver to finish
}

// Function to run players in processes using a PipeCommunicator
void runProcessPlayers() {
    PipeCommunicator communicator; // Use PipeCommunicator for process mode
    pid_t pid = fork(); // Create a new process

    if (pid == 0) { // Child process (Initiator)
        ProcessPlayer initiator(Role::INITIATOR, &communicator);
        initiator.Run();
        exit(0);
    } else if (pid > 0) { // Parent process (Receiver)
        ProcessPlayer receiver(Role::RECEIVER, &communicator);
        receiver.Run();
        wait(nullptr); // Wait for child process to finish
        communicator.Close();
    } else {
        std::cerr << "Fork failed!" << std::endl; // Handle fork failure
        communicator.Close();
        return;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <(thread/process)>" << std::endl;
        return 1;
    }

    if (std::string(argv[1]) == "thread") {
        runThreadPlayers(); // Run thread mode
    } else if (std::string(argv[1]) == "process") {
        runProcessPlayers(); // Run process mode
    } else {
        std::cerr << "Invalid mode. Use 'thread' or 'process' param." << std::endl;
        return 1;
    }
    return 0;
}