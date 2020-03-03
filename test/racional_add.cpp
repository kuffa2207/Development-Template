#include <gtest/gtest.h>
#include "racional.h"
#include <iostream>
#include <fstream>
#include <clocale>     
#include <math.h>

using namespace std;

TEST(number, CanAddTwoPositiveNumbers) {
    number c1(1,3), c2(1, 2);
    number c3(5, 6);
    number res = c1 + c2;
  EXPECT_EQ(res,c3);
}
//
//TEST(number, CanAddTwoNumbersDifferentSign) {
//  EXPECT_EQ(add(-5, 5), 0);
//}
//
//TEST(raci, CanAddTwoNegativeNumbers) {
//  EXPECT_EQ(add(-5, -5), -10);
//}
