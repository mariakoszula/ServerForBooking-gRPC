#include "IBookingDatabase.h"
set<MovieStore> InMemoryDatabase::listMovies()
{
    set<MovieStore> movies;
    for (const auto& booking : bookings_)
    {
        movies.insert(booking.getMovieStore());
    }
    return movies;
}

void InMemoryDatabase::addBooking(Booking&& booking){
    bookings_.emplace_back(std::move(booking));
}