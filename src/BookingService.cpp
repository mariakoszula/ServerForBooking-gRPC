#include "booking_service.grpc.pb.h"
#include <grpcpp/server_context.h>

using namespace bookingservice;
using grpc::ServerContext;
using grpc::Status;
class BookingServiceImpl final: public BookingService::Service {
    Status ListMovies(ServerContext* context, const ListMoviesRequest* request, ListMoviesResponse* response) override {
        [&](){return context;};
        [&](){return request;};
        [&](){return response;};
        // TODO: implement listing movies
        return grpc::Status::OK;
    }
};