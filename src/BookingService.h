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
        explicit BookingServiceImpl(IBookingDatabase& db);
        Status ListMovies(ServerContext*, const google::protobuf::Empty*, ListMoviesResponse*) override;
    private:
        IBookingDatabase &db;
};
#endif // BOOKING_SERVICE_H