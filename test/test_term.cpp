#include <gtest/gtest.h>
#include "add.h"

TEST(Thermpometr, CAN_WRITE_FILE) {
    Term termts;
    ASSERT_NO_THROW(termts.infile());
}

TEST(Thermpometr, CAN_USE_COPY) {   
    Term termts;
    Term rc(termts);
    EXPECT_EQ(termts, rc);
}

TEST(Thermpometr, CAN_USE_FIRSTDATA) {
    Term termts;
    ASSERT_ANY_THROW(termts.firstdata());
}

TEST(Thermpometr, CAN_USE_CONST1) {
    int* YMD = new int[4];
    YMD[0] = 0;
    YMD[1] = 0;
    YMD[2] = 0;
    YMD[3] = 0;
    int T = 0;
    Date t(YMD, T);
    Date t1;
    EXPECT_EQ(t, t1);
}

TEST(Thermpometr, CAN_USE_CONST2) {
    int* YMD = new int[4];
    YMD[0] = 0;
    YMD[1] = 0;
    YMD[2] = 0;
    YMD[3] = 0;
    int T = 0;
    Date t(YMD, T);
    Date t1;
    EXPECT_EQ(t1, t);
}

TEST(Thermpometr, CAN_USE_SREDMONTH_WITH_PLUST) {
    int* YMD = new int[4];
    YMD[0] = 29;
    YMD[1] = 10;
    YMD[2] = 2001;
    YMD[3] = 12;
    int T =  20;
    Term d(YMD, T);
    int res = d.sredm(10);
    EXPECT_EQ(res, 20);
}

TEST(Thermpometr, CAN_USE_SREDMONTH_WITH_MINUST) {
    int* YMD = new int[4];
    YMD[0] = 29;
    YMD[1] = 10;
    YMD[2] = 2001;
    YMD[3] = 12;
    int T = -20;
    Term d(YMD, T);
    int res = d.sredm(10);
    EXPECT_EQ(res, -20);
}



TEST(Thermpometr, CAN_USE_F_MOUNTHMORE1_WITH_MINUS) {
    int* YMDn = new int[4];
    YMDn[0] = 4;
    YMDn[1] = 1;
    YMDn[2] = 2008;
    YMDn[3] = 10;
    int Tn = -20;

    int* YMD = new int[4];
    YMD[0] = 7;
    YMD[1] = 1;
    YMD[2] = 2008;
    YMD[3] = 14;
    int T = -10;

    Term d(YMD, T);
    Term d1(YMDn, Tn);
    int res1 = d.sredm(1);
    int res2 = d1.sredm(1);
    int res3 = (res1 + res2) / 2;
    EXPECT_EQ(res3, -15);
}

TEST(Thermpometr, CAN_USE_FIND_MONTH) {
    int* YMD = new int[4];
    YMD[0] = 12;
    YMD[1] = 12;
    YMD[2] = 2012;
    YMD[3] = 10;
    int T = 240;

    Term d(YMD, T);

    int res = d.sredm(5);
    EXPECT_EQ(res, false);
}

TEST(Thermpometr, CAN_USE_F_MOUNTHMORE1_WITH_PLUS) {
    int* YMDn = new int[4];
    YMDn[0] = 4;
    YMDn[1] = 6;
    YMDn[2] = 2016;
    YMDn[3] = 10;
    int Tn = 20;

    int* YMD = new int[4];
    YMD[0] = 7;
    YMD[1] = 6;
    YMD[2] = 2008;
    YMD[3] = 14;
    int T = 10;

    Term d(YMD, T);
    Term d1(YMDn, Tn);
    int res1 = d.sredm(6);
    int res2 = d1.sredm(6);
    int res3 = (res1 + res2) / 2;
    EXPECT_EQ(res3, 15);
}

TEST(Thermpometr, CAN_USE_SREDALL) {
    int* YMD = new int[4];
    YMD[0] = 29;
    YMD[1] = 6;
    YMD[2] = 2001;
    YMD[3] = 1;
    int T = 30;
    Term d(YMD, T);
    int res = d.sredall(30);
    EXPECT_EQ(res, 30);
}

TEST(Thermpometr, CAN_USE_FIND_WR) {
    int* YMD = new int[4];
    YMD[0] = 12;
    YMD[1] = 12;
    YMD[2] = 2012;
    YMD[3] = 10;
    int T = 0;

    Term d(YMD, T);

    int res = d.sredall(0);
    EXPECT_EQ(res, false);
}
TEST(Thermpometr, CAN_USE_F_ALLMORE1_WITH_PLUS) {
    int* YMDn = new int[4];
    YMDn[0] = 4;
    YMDn[1] = 6;
    YMDn[2] = 2016;
    YMDn[3] = 10;
    int Tn = 20;

    int* YMD = new int[4];
    YMD[0] = 7;
    YMD[1] = 6;
    YMD[2] = 2008;
    YMD[3] = 14;
    int T = 10;

    Term d(YMD, T);
    Term d1(YMDn, Tn);
    int res1 = d.sredall(6);
    int res2 = d1.sredall(6);
    int res3 = (res1 + res2) / 2;
    EXPECT_EQ(res3, 15);
}
TEST(Thermpometr, CAN_USE_F_AllMORE1_WITH_MINUS) {
    int* YMDn = new int[4];
    YMDn[0] = 4;
    YMDn[1] = 1;
    YMDn[2] = 2008;
    YMDn[3] = 10;
    int Tn = -20;

    int* YMD = new int[4];
    YMD[0] = 7;
    YMD[1] = 1;
    YMD[2] = 2008;
    YMD[3] = 14;
    int T = -10;

    Term d(YMD, T);
    Term d1(YMDn, Tn);
    int res1 = d.sredall(1);
    int res2 = d1.sredall(1);
    int res3 = (res1 + res2) / 2;
    EXPECT_EQ(res3, -15);
}

