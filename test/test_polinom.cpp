#include <gtest/gtest.h>
#include "polinom.h"

TEST(Polynom, Can_Assignment_Two_Polynoms) {
    Polynom c1(2), c2(3);
    Polynom c3(3);
    Polynom res = c1 = c2;
    EXPECT_EQ(res, c3); 
}
TEST(Polynom, Can_Use_Default_Constructor) {
    Polynom Polynom;
    EXPECT_EQ(0, Polynom);
}

TEST(Polynom, Can_Use_Copy_Constructor) {
    int an = 20;
    Polynom Polynom(an);
    EXPECT_EQ(an, Polynom);
}
TEST(Polynom, Can_Add_Two_Polynoms) {
    Polynom c1(4), c2(2);
    Polynom c3(6);
    Polynom res = c1 + c2;
    EXPECT_EQ(res, c3);
}
TEST(Polynom, Can_Subtract_Two_Polynoms) {
    Polynom c1(21), c2(10);
    Polynom c3(11);
    Polynom res = c1 - c2;
    EXPECT_EQ(res, c3);
}
TEST(Polynom, Can_Multiply_Two_Polynoms) {
    Polynom c1(5), c2(6);
    Polynom c3(30);
    Polynom res = c1 * c2;
    EXPECT_EQ(res, c3);
}
TEST(Polynom, Can_Comparison_Two_Polynoms) {
    Polynom c1(53), c2(53);
    Polynom c3(1);
    Polynom res = c1 == c2;
    EXPECT_EQ(res, c3);
}
TEST(Polynom, Can_Sub_Two_Same_Polynoms) {
    Polynom c1(6), c2(6);
    Polynom c3(0);
    Polynom res = c1 - c2;
    EXPECT_EQ(res, c3);
}

