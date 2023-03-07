#include "gtest/gtest.h"
// #include "BookingDatabaseMock.h"
#include "BookingService.h"
#include <iostream>
#include "IBookingDatabase.h"
#include "gmock/gmock.h"
#include <google/protobuf/util/message_differencer.h>

using namespace ::testing;
using namespace google::protobuf::util;
class BookingDatabaseMock : public IBookingDatabase
{
    public:
        MOCK_METHOD(set<MovieStore>, listMovies, (), (override));
};

TEST(BookingService, listMovies)
{
    BookingDatabaseMock db;
    BookingServiceImpl service(db);
    ServerContext context;
    google::protobuf::Empty request;
    ListMoviesResponse response;
    std::set<MovieStore> expected_movies = {"MovieTitle"};
    ON_CALL(db, listMovies()).WillByDefault(Return(expected_movies));
    EXPECT_TRUE(service.ListMovies(&context, &request, &response).ok());
    ListMoviesResponse expectedResp;
    expectedResp.add_movies()->set_title("MovieTitle");
    EXPECT_TRUE(MessageDifferencer::Equals(expectedResp, response));
};
