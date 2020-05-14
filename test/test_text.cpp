#include <gtest/gtest.h>
#include "add.h"

TEST(Textred, CAN_USE_CONST_OF_INIT) {
    ASSERT_NO_THROW(Textred init(10, 10));
}

TEST(Textred, CAN_USE_CONST_OF_DEFF) {
    ASSERT_NO_THROW(Textred init());
}

TEST(Textred, CAN_USE_TEXT) {
    Textred hv;
    ASSERT_ANY_THROW(hv.text("testiki", 20));
}

TEST(Textred, CAN_USE_CONSTRS) {
    Textred a(1, 1), b;
    EXPECT_EQ(a, b);
}

TEST(Textred, CAN_USE_CONSTRS2) {
    Textred a, b(1, 1);
    EXPECT_EQ(a, b);
}
