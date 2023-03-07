#ifndef IBOOKING_DATABASE_H
#define IBOOKING_DATABASE_H
#include <vector>
#include <set>
#include "Booking.h"
#include <iostream>
using namespace std;

class IBookingDatabase
{
public:
    virtual ~IBookingDatabase() = default;
    virtual set<MovieStore> listMovies() = 0;
};


class InMemoryDatabase : public IBookingDatabase
{
public:
    set<MovieStore> listMovies() override;
    void addBooking(Booking&& booking);
private:
    vector<Booking> bookings_;
};

#endif // IBOOKING_DATABASE_H