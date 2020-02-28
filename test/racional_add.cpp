#include <gtest/gtest.h>
#include "racional.h"

TEST(Addition, CanAddTwoPositiveNumbers) {
  EXPECT_EQ(add(5, 5), 10);
}

TEST(Addition, CanAddTwoNumbersDifferentSign) {
  EXPECT_EQ(add(-5, 5), 0);
}

TEST(Addition, CanAddTwoNegativeNumbers) {
  EXPECT_EQ(add(-5, -5), -10);
}
