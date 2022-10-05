# Toy Robot

This project aims to solve and provide a demo application for [Toy Robot Code Challenge](ToyRobot.md)

## Project Structure

* [Source](src/)  
  * [GameServer](src/GameServer)  
  Contains the modules that comprises the game server
    * [Core](src/GameServer/Core)  
    Contains the implementation of the core application's use cases
    * [Domain](src/GameServier/Domain)  
    Contains the domain entities that the use cases works on
    * [Adapters](src/GameServer/Adapters)  
    Contains the adapters that interacts with or used by the core
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
