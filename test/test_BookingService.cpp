#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IBookingDatabase.h"
#include "BookingService.h"

using namespace ::testing;
TEST(BookingService, listMovies)
{
    InMemoryDatabase bookings;
    bookings.addBooking(Booking{"The Matrix", "Theater", 1});
    bookings.addBooking(Booking{"The Matrix", "Theater2", 1});
    bookings.addBooking(Booking{"The Matrix Reloaded", "Theater2", 2});
    EXPECT_THAT(bookings.listMovies(), ElementsAre("The Matrix", "The Matrix Reloaded"));
};
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}