# ServerForBooking-gRPC
Simple backend service for displaying movies in theaters and booking seats. 
Project is just for learning purpose of gRPC workflow.

### Assumptions:
- No timetable or dates are managed
- Theaters can have several auditoriums. 1 movie per auditorium.
- Theaters have by default maximum of 20 capacity


## API

## Libraries
- googletest
- gRPC

## Build and run

### Build:

```sh
mkdir build && cd build
```
Debug
```sh
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

Release
```sh
cmake .. -DCMAKE_BUILD_TYPE=Release
```
```sh
cmake --build .
```
### Run:
```sh
./src/ServerForBooking-gRPC_run
```
### Run tests:
```sh
./test/ServerForBooking-gRPC_test
```
