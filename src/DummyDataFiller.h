#ifndef DUMMY_DATA_FILLER_H
#define DUMMY_DATA_FILLER_H
#include "IBookingDatabase.h"

void addBookings(InMemoryDatabase& db)
{
    db.addBooking(Booking{"The Matrix", "New Theater", 1});
    db.addBooking(Booking{"The Matrix", "Old Theater", 1});
    db.addBooking(Booking{"The Matrix Reloaded", "Old Theater", 2});
};

#endif // DUMMY_DATA_FILLER_H