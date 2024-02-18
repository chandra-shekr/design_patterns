#include <gtest/gtest.h>
#include "intro.hpp"

struct Intro : public ::testing::Test
{

    Foo *earth;
    virtual void SetUp() override
    {

        earth = new Foo;
    }

    virtual void TearDown() override
    {
        std::cout << "Intro: running teardown" << std::endl;
        delete earth;
    }
};

TEST_F(Intro, life_universe_everything)
{
    int got = earth->bar(43);
    EXPECT_EQ(42, got) << "where expected = " << 42 << " got = " << got;
}

int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}