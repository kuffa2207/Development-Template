#include <gtest/gtest.h>
#include "complex.h"

TEST(Addition, CanAddTwoPositiveNumbers) {
  Complex c1(5, 5), c2(5, 5);
  const Complex res = c1 + c2;
  const Complex trueRes(10, 10);
  EXPECT_EQ(res.re, trueRes.re);
  EXPECT_EQ(res.im, trueRes.im);
}

/*TEST(Addition, CanAddTwoNumbersWithDifferentSign) {
  Complex c1(-5, 5), c2(5, -5);
  Complex res = c1 + c2;
  Complex trueRes(0, 0);
  EXPECT_EQ(res, trueRes);
}

TEST(Addition, CanAddTwoNegativeNumbers) {
  Complex c1(-5, -5), c2(-5, -5);
  Complex res = c1 + c2;
  Complex trueRes(-10, -10);
  EXPECT_EQ(res, trueRes);
}*/
