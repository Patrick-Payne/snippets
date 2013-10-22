extern "C" {
#include "quick_select.h"
}

#include "gtest/gtest.h"


/******************************************************************************
 * BASIC FUNCTIONALITY TESTING:
 *****************************************************************************/ 

// Test on a list with only 1 element.
TEST(Basic, OneElement) {
  int test_list[1] = {1};
  EXPECT_EQ(1, QuickSelect(test_list, 1, 1)); 

  test_list[0] = -10;
  EXPECT_EQ(-10, QuickSelect(test_list, 1, 1)); 
}

// Test on a list with 2 elements.
TEST(Basic, TwoElements) {
  int test_list[2] = {-1, 1};

  EXPECT_EQ(-1, QuickSelect(test_list, 2, 1)); 
  EXPECT_EQ(1, QuickSelect(test_list, 2, 2)); 

  // Test when the items are not in sorted order.
  test_list[0] = 123;
  test_list[1] = -653;
  EXPECT_EQ(-653, QuickSelect(test_list, 2, 1)); 
  EXPECT_EQ(123, QuickSelect(test_list, 2, 2)); 
}

// Test on a list with 3 elements.
TEST(Basic, ThreeElements) {
  int test_list[3] = {-1, 0, 1};
  EXPECT_EQ(-1, QuickSelect(test_list, 3, 1)); 
  EXPECT_EQ(0, QuickSelect(test_list, 3, 2)); 
  EXPECT_EQ(1, QuickSelect(test_list, 3, 3)); 

  test_list[0] = 100;
  test_list[1] = -200;
  test_list[2] = 150;
  EXPECT_EQ(-200, QuickSelect(test_list, 3, 1)); 
  EXPECT_EQ(100, QuickSelect(test_list, 3, 2)); 
  EXPECT_EQ(150, QuickSelect(test_list, 3, 3)); 
}

// Test on lists with many elements.
TEST(Basic, MultipleElements) {
  int test_list[30] = {4, 1, 3, 2};
  EXPECT_EQ(1, QuickSelect(test_list, 4, 1)); 
  EXPECT_EQ(2, QuickSelect(test_list, 4, 2)); 
  EXPECT_EQ(3, QuickSelect(test_list, 4, 3)); 
  EXPECT_EQ(4, QuickSelect(test_list, 4, 4)); 

  test_list[0] = -123;
  test_list[1] = 1000;
  test_list[2] = 20;
  test_list[3] = 0;
  test_list[4] = -10;
  EXPECT_EQ(-123, QuickSelect(test_list, 5, 1)); 
  EXPECT_EQ(-10, QuickSelect(test_list, 5, 2)); 
  EXPECT_EQ(0, QuickSelect(test_list, 5, 3)); 
  EXPECT_EQ(20, QuickSelect(test_list, 5, 4)); 
  EXPECT_EQ(1000, QuickSelect(test_list, 5, 5)); 
}
