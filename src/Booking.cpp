#include "Booking.h"

uint32_t Booking::booking_counter = 0;

Booking::Booking(MovieStore movie, TheaterStore theater, SeatStore seat)
    : movie{movie}, theater{theater}, seat{seat}, booking_no{++booking_counter}, isReserved{false}
{
}

MovieStore Booking::getMovie() const
{
    return movie;
}