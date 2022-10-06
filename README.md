# Toy Robot

This project aims to solve and provide a demo application for [Toy Robot Code Challenge](ToyRobot.md)

## Project Structure

This project is structured using an opinionated approach of implementing a C++ application using the [Hexagonal Architecture](https://en.wikipedia.org/wiki/Hexagonal_architecture_(software)) (or Ports and Adapters pattern)

* [Source](src/)  
  * [GameServer](src/GameServer)  
    * [Core](src/GameServer/Core)  
    Contains the implementation of the core application's use cases
    * [Domain](src/GameServer/Domain)  
    Contains the domain entities that the use cases works on
    * [Adapters](src/GameServer/Adapters)  
    Contains adapters implementation that interacts with or used by the core
  * [Demo Application](DemoApplication.md)  
  Wires the components together and provide a basic CLI to demonstrate

* [Test Implementation](test/)  
  * [Integration Test](test/README.md)
  * [Unit Test](test/README.md#unit-test)

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
- [ ] Implement ci/cd scripts 

Future Plans
- [ ] Implement incoming adapters for admin controls
- [ ] Implement network/messaging capabilities for the game server's incoming port
- [ ] Implement a game client that can communicate with the server
