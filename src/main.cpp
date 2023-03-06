#include <iostream>
#include <memory>
#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/security/server_credentials.h>
#include "BookingService.h"
#include "IBookingDatabase.h"

using namespace std;

int main(){
   grpc::ServerBuilder builder;
   InMemoryDatabase db;
   builder.AddListeningPort("localhost:50051", grpc::InsecureServerCredentials());
   BookingServiceImpl service{db};
   builder.RegisterService(&service);
   std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
   cout << "Booking service is listening on port 50051" << std::endl;
   server->Wait();
   return 0; 
}