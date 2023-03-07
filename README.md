# ServerForBooking-gRPC
[![CodeFactor](https://www.codefactor.io/repository/github/mariakoszula/serverforbooking-grpc/badge)](https://www.codefactor.io/repository/github/mariakoszula/serverforbooking-grpc)

Simple backend service for displaying movies in theaters and booking seats. 
Project is just for learning purpose of gRPC workflow.

### Assumptions:
- No timetable or dates are managed
- Theaters can have several auditoriums. 1 movie per auditorium.
- Theaters have by default maximum of 20 capacity


## API
Supported messages are in booking_service.proto file.

## Libraries
- googletest
- gRPC
- protobuf

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
./src/ServerForBooking-gRPC_run <IP> <Port>
```
IP: default is 127.0.0.1
Port default is 50051
### Run tests:
```sh
./test/ServerForBooking-gRPC_test
```
### Postman Workspace for testing:
```sh
https://www.postman.com/grey-sunset-995258/workspace/serverforbooking-grpc
```