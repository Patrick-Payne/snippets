/******************************************************************************
 * File: test_insertion_sort_array.cc
 * Author: Patrick Payne
 * Date Created: Sep 13, 2013
 * Purpose: To test the in-place insertion sort algorithms for arrays.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/
extern "C" {
#include "insertion_sort_array.h"
}

#include "gtest/gtest.h"

/******************************************************************************
 * Test sort_int_array()
 *****************************************************************************/ 
// Test case where list is already sorted.
TEST(SortIntArrayTest, Sorted) {
  int test_array[] = {0, 1, 2, 3, 4, 5};
  SortIntArray(test_array, 6);

  EXPECT_EQ(test_array[0], 0);
  EXPECT_EQ(test_array[1], 1);
  EXPECT_EQ(test_array[2], 2);
  EXPECT_EQ(test_array[3], 3);
  EXPECT_EQ(test_array[4], 4);
  EXPECT_EQ(test_array[5], 5);
}

// Test case where there is only one mismatch.
TEST(SortIntArrayTest, OneMismatch) {
  int test_array[] = {0, 1, 3, 2, 4, 5};
  SortIntArray(test_array, 6);

  EXPECT_EQ(test_array[0], 0);
  EXPECT_EQ(test_array[1], 1);
  EXPECT_EQ(test_array[2], 2);
  EXPECT_EQ(test_array[3], 3);
  EXPECT_EQ(test_array[4], 4);
  EXPECT_EQ(test_array[5], 5);
}

// Test case where we have reverse order
TEST(SortIntArrayTest, ReverseSort) {
  int test_array[] = {5, 4, 3, 2, 1, 0};
  SortIntArray(test_array, 6);

  EXPECT_EQ(test_array[0], 0);
  EXPECT_EQ(test_array[1], 1);
  EXPECT_EQ(test_array[2], 2);
  EXPECT_EQ(test_array[3], 3);
  EXPECT_EQ(test_array[4], 4);
  EXPECT_EQ(test_array[5], 5);
}
