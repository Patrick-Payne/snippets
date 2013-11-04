/******************************************************************************
 * File: test_quicksort.cc
 * Author: Patrick Payne
 * Date Created: Sep 13, 2013
 * Purpose: To test the in-place insertion sort algorithms for arrays.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/
extern "C" {
#include "quicksort.h"
}

#include "gtest/gtest.h"

/******************************************************************************
 * BASIC FUNCTIONALITY
 *****************************************************************************/ 
// Test edge case where the list contains a single element.
TEST(QuickSortTest, Singleton) {
  int test_array[] = {0};
  QuickSort(test_array, 0, 0);
  EXPECT_EQ(0, test_array[0]);
}


// Test edge case where the list contains a single element.
TEST(QuickSortTest, Doubleton) {
  int test_array[] = {0, 1};
  QuickSort(test_array, 1, 0);
  EXPECT_EQ(0, test_array[0]);
  EXPECT_EQ(1, test_array[1]);
}


// Test case where list is already sorted.
TEST(QuickSortTest, Sorted) {
  int test_array[] = {0, 1, 2, 3, 4, 5};
  QuickSort(test_array, 0, 5);

  EXPECT_EQ(0, test_array[0]);
  EXPECT_EQ(1, test_array[1]);
  EXPECT_EQ(2, test_array[2]);
  EXPECT_EQ(3, test_array[3]);
  EXPECT_EQ(4, test_array[4]);
  EXPECT_EQ(5, test_array[5]);
}


// Test case where there is only one mismatch.
TEST(QuickSortTest, OneMismatch) {
  int test_array[] = {0, 1, 3, 2, 4, 5};
  QuickSort(test_array, 0, 5);

  EXPECT_EQ(0, test_array[0]);
  EXPECT_EQ(1, test_array[1]);
  EXPECT_EQ(2, test_array[2]);
  EXPECT_EQ(3, test_array[3]);
  EXPECT_EQ(4, test_array[4]);
  EXPECT_EQ(5, test_array[5]);
}


// Test case where we have reverse order
TEST(QuickSortTest, ReverseSort) {
  int test_array[] = {5, 4, 3, 2, 1, 0};
  QuickSort(test_array, 0, 5);

  EXPECT_EQ(0, test_array[0]);
  EXPECT_EQ(1, test_array[1]);
  EXPECT_EQ(2, test_array[2]);
  EXPECT_EQ(3, test_array[3]);
  EXPECT_EQ(4, test_array[4]);
  EXPECT_EQ(5, test_array[5]);
}


/******************************************************************************
 * STRESS TESTING:
 *****************************************************************************/ 

// Test large, reverse sorted list.
TEST(QuickSortTest, LargeList) {
  int test_array[20301];
  int test_size = 20301;

  for (int i = 0; i < test_size; i++) {
    test_array[i] = (test_size - 1) - i;
  }
  QuickSort(test_array, 0, test_size - 1);

  for (int i = 0; i < test_size; i++) {
    EXPECT_EQ(i, test_array[i]);
  }
}
