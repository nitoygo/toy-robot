## How to Use

### Pre-requisites

C++ compiler and runtime environment are available.  

### Building and Running the Demo Application

In the `src` directory, run the `make` command:
```
$ cd src
$ make
```

The output executable is in `build/` directory and can be run as follows:
```
$ ./build/ToyRobotDemo
PLACE 1,2,EAST
MOVE
MOVE
LEFT
MOVE
REPORT
Output: 3,3,NORTH
```  
To exit the application, an additional command `QUIT` is provided.

### Checking for static code errors and warnings

An additional package named `cppcheck` is required to run static code tests.  
Static code check is also done in `src` directory:
```
$ cd src
$ make static-check
```  
Reports can be checked in the top directory, under `reports/static`

### Running Unit Tests

An additional package named `cpputest` is required to run the unit tests.  
The unit tests are run in `test` directory:
```
$ cd test
$ make test
```  
Please see information about running unit tests and generating reports [here](test/README.md)  
