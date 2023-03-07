#include <iostream>
#include <memory>
#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/security/server_credentials.h>
#include "BookingService.h"
#include "IBookingDatabase.h"
#include "DummyDataFiller.h"

using namespace std;

int main(int argc, char** argv){
   std::string server_address("127.0.0.1");
   std::string port("50051");
   if (argc == 2) {
      server_address = argv[1];
   }
   if (argc == 3){
      port = argv[2];
   }
   grpc::ServerBuilder builder;
   InMemoryDatabase db;
   addBookings(db);
   builder.AddListeningPort(server_address + ":" + port, grpc::InsecureServerCredentials());
   BookingServiceImpl service{db};
   builder.RegisterService(&service);
   std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
   cout << "Booking service is listening on port 50051" << std::endl;
   server->Wait();
   return 0; 
}