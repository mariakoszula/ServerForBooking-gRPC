#include "BookingService.h"
#include <iostream>
BookingServiceImpl::BookingServiceImpl(IBookingDatabase &db) : db(db) {}
Status BookingServiceImpl::ListMovies([[maybe_unused]] ServerContext *context, [[maybe_unused]]  const google::protobuf::Empty *request, ListMoviesResponse *response)
{
    auto movies = db.listMovies();
    for (const auto &movie : movies)
    {
        auto movieResponse = response->add_movies();
        movieResponse->set_title(movie);
    }
    return grpc::Status::OK;
}
