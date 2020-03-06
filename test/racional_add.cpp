#include <gtest/gtest.h>
#include "racional.h"
#include <iostream>
#include <fstream>
#include <clocale>     
#include <math.h>

using namespace std;

TEST(number, CanAddTwoRacionalNumbers) {
    number c1(1,3), c2(1, 2);
    number c3(5, 6);
    number res = c1 + c2;
  EXPECT_EQ(res,c3);
}

TEST(number, CanMultiplyTwoRacionalNumbers) {
    number c4(1, 2), c5(4, 5);
    number c6(4, 10);
    number res = c4 * c5;
  EXPECT_EQ(res,c6);
}
TEST(number, CanMinusTwoRacionalNumbers) {
    number c7(2, 5), c8(1, 3);
    number c9(1, 15);
    number res = c7 - c8;
    EXPECT_EQ(res, c9);
}
TEST(number, CanSravTwoRacinaolNumber) {
    number c10(2, 5), c11(2, 5);
    number c12(1,1);
    number res = c10 == c11;
    EXPECT_EQ(res, c12);
}
TEST(number, CanDivisionTwoRacinaolNumber) {
    number c13(2, 5), c14(2, 5);
    number c15(19, 4);
    number res = c13 / c14;
    EXPECT_EQ(res, c15);
}
TEST(number, CanPrisvainTwoRacinaolNumber) {
    number c16(2, 5), c17(2, 7);
    number c18(2, 7);
    number res = c16 = c17;
    EXPECT_EQ(res, c18);
}