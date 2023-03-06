#ifndef BOOKING_SERVICE_H
#define BOOKING_SERVICE_H
#include "booking_service.grpc.pb.h"
#include <grpcpp/server_context.h>
#include "IBookingDatabase.h"

using namespace bookingservice;
using grpc::ServerContext;
using grpc::Status;


class BookingServiceImpl final: public BookingService::Service {
    public:
        explicit BookingServiceImpl(IDatabase& db);
        Status ListMovies(ServerContext* context, const google::protobuf::Empty* request, ListMoviesResponse* response) override;
    private:
        IDatabase &db;
};
#endif // BOOKING_SERVICE_H