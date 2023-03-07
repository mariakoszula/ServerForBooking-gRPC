#include <string>

using namespace std;
using MovieStore = string;
using TheaterStore = string;
using SeatStore = int;
using BookingNo = uint32_t;

class Booking {
    static uint32_t booking_counter;
    public:
        Booking(MovieStore, TheaterStore, SeatStore);
        MovieStore getMovieStore() const;
    private:
        MovieStore movie;
        TheaterStore theater;
        SeatStore seat;
        BookingNo booking_no;
        bool isReserved;
};