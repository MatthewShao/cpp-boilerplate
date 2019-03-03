#include "gtest/gtest.h"
#include "../src/Example.h"

TEST(ExampleTest, shouldReturnSum) {
   EXPECT_EQ(Example::toTest(1, 2), 3);
}