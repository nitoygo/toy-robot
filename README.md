# Toy Robot

This project aims to solve and provide a demo application for [Toy Robot Code Challenge](ToyRobot.md).  

## Project Structure

This project is structured using an opinionated approach of implementing a C++ application using the [Hexagonal Architecture](https://en.wikipedia.org/wiki/Hexagonal_architecture_(software)) (or Ports and Adapters pattern)

[Source](src/)  
* [GameServer](src/GameServer)  
  * [Core](src/GameServer/Core)  
    * [Domain](src/GameServer/Core/Domain)  
    Contains the domain entities such as `Robot` and `Table`  
    which are accessed by the use cases.  
    * [Services](src/GameServer/Core/Services)  
    Contains the implementation of the core application's use cases  
    such as moving the `Robot` in the `Table`.  
    * [Ports](src/GameServer/Core/Ports)  
    Contains definition of ports that allow communication between the core and adapters.  
  * [Adapters](src/GameServer/Adapters)  
  Contains implementation of adapters that interacts with or used by the core.  
* [DemoApplication](DemoApplication.md)  
Wires the components together to run a game server instance  
and provides a console application to simulate how a client might interact with the server.  

[Test](test/)  
Contains the test code to verify the application works as expected

## How to Use

### Building and Running the Demo Application

In the `src` directory, run the `make` command:
```
$ cd src
$ make
```

The output executable is in `build/` directory and can be run as follows:
```
$ ./build/ToyRobotDemo
```

## Roadmap

- [x] Implement core features
- [x] Implement incoming and outgoing adapters for demo app
- [ ] Implement tests
- [x] Implement ci/cd scripts 

Future Plans
- [ ] Implement incoming adapters for admin controls
- [ ] Implement network/messaging capabilities for the game server's incoming port
- [ ] Implement a game client that can communicate with the server
