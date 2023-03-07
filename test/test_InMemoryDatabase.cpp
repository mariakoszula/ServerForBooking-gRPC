
#include "gmock/gmock.h"
#include "IBookingDatabase.h"

using namespace ::testing;
TEST(InMemoryDatabase, listMovies)
{
    InMemoryDatabase bookings;
    bookings.addBooking(Booking{"The Matrix", "Theater", 1});
    bookings.addBooking(Booking{"The Matrix", "Theater2", 1});
    bookings.addBooking(Booking{"The Matrix Reloaded", "Theater2", 2});
    EXPECT_THAT(bookings.listMovies(), ElementsAre("The Matrix", "The Matrix Reloaded"));
};
