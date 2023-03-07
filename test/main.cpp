#include "gtest/gtest.h"
#include "gmock/gmock.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::GMOCK_FLAG(catch_leaked_mocks)=true;
    ::testing::GMOCK_FLAG(verbose)="info";
    return RUN_ALL_TESTS();
}