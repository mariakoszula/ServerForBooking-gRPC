#include "BookingService.h"

BookingServiceImpl::BookingServiceImpl(IDatabase &db) : db(db) {}
Status BookingServiceImpl::ListMovies(ServerContext *context, const google::protobuf::Empty *request, ListMoviesResponse *response)
{
    [&]()
    { return context; };
    [&]()
    { return request; };
    [&]()
    { return response; };
    // TODO: implement listing movies
    return grpc::Status::OK;
}
