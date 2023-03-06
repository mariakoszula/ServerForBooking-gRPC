#ifndef IBOOKING_DATABASE_H
#define IBOOKING_DATABASE_H
#include <vector>
#include <set>
#include "Booking.h"

using namespace std;

class IDatabase
{
public:
    virtual ~IDatabase() = default;
    virtual set<MovieStore> listMovies() = 0;
};


class InMemoryDatabase : public IDatabase
{
public:
    set<MovieStore> listMovies() override;
    void addBooking(Booking&& booking);
private:
    vector<Booking> bookings_;
};

#endif // IBOOKING_DATABASE_H