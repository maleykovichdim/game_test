
## Sending/Receiving algorithm:

- method Run() of class Player (abstract class)

## Classes Overview

### Communicator
- Abstract base class that defines the interface for communication between players.
- Contains methods:
  - `Push(Role role, const std::string& message)`: Sends a message based on the role.
  - `Pop(Role role)`: Retrieves a message for the specified role.
  - `Close()`: Closes the communication channels.

### Player
- Abstract base class for players in the game.
- Contains methods:
  - `Send(const std::string& message)`: Sends a message through the communicator.
  - `Receive()`: Receives a message from the communicator.
  - `Run()`: Starts the player's operation (the implementation will depend on whether it's a thread or a process).

### ThreadPlayer
- Inherits from `Player` and represents a player that operates in a thread.
- Uses a `QueueCommunicator` to facilitate message passing.
- Implements asynchronous message handling in threads.

### ProcessPlayer
- Inherits from `Player` and represents a player that operates in a process.
- Uses a `PipeCommunicator` to facilitate communication through pipes.
- Handles sending and receiving messages using the process's communication methods.

### PipeCommunicator
- Implements the `Communicator` interface using pipes for inter-process communication.
- Provides mechanisms for pushing and popping messages between processes.

### QueueCommunicator
- Implements the `Communicator` interface using synchronized queues for thread-based communication.
- Provides mechanisms for pushing and popping messages between threads.

## Building and executing the Project

- game.sh
