#include <gtest/gtest.h>
#include "app.h"

TEST(BullAndCow1, CAN_USE_SIMILARNUM) {
    BullAndCow a;
    bool test;
    char me[] = { '1','2' };
    test = a.similarNum(me, 2);
    EXPECT_EQ(test, false);
}
TEST(BullAndCow2, CAN_USE_SIMILARNUM2) {
    BullAndCow a;
    bool test;
    char me[4] = { '1','2','3','4' };
    test = a.similarNum(me, 4);
    EXPECT_EQ(test,false);
}
TEST(BullAndCow3, CAN_USE_MASSNUM) {
    BullAndCow a;
    char me[4] = { '1','2','3' };
    bool test = 672;
    a.MassNum(test, me, 3);
    EXPECT_EQ(test, true);
}
