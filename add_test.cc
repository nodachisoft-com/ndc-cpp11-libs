#include <gtest/gtest.h>
#include "add.h"

TEST(add_test, answer_1_plus_2){
    EXPECT_EQ(3, add(1,2));
}
