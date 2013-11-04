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
 * Test Function Definitions
 *****************************************************************************/ 
int IntGreaterThan(void *a, void *b) {
  return *static_cast<int *>(a) > *static_cast<int *>(b);
}
/******************************************************************************
 * Test sort_int_array()
 *****************************************************************************/ 
// Test case where list is already sorted.
TEST(InsertionSortTest, Sorted) {
  int test_array[] = {0, 1, 2, 3, 4, 5};
  InsertionSort(test_array, 6);

  EXPECT_EQ(test_array[0], 0);
  EXPECT_EQ(test_array[1], 1);
  EXPECT_EQ(test_array[2], 2);
  EXPECT_EQ(test_array[3], 3);
  EXPECT_EQ(test_array[4], 4);
  EXPECT_EQ(test_array[5], 5);
}

// Test case where there is only one mismatch.
TEST(InsertionSortTest, OneMismatch) {
  int test_array[] = {0, 1, 3, 2, 4, 5};
  InsertionSort(test_array, 6);

  EXPECT_EQ(test_array[0], 0);
  EXPECT_EQ(test_array[1], 1);
  EXPECT_EQ(test_array[2], 2);
  EXPECT_EQ(test_array[3], 3);
  EXPECT_EQ(test_array[4], 4);
  EXPECT_EQ(test_array[5], 5);
}

// Test case where we have reverse order
TEST(InsertionSortTest, ReverseSort) {
  int test_array[] = {5, 4, 3, 2, 1, 0};
  InsertionSort(test_array, 6);

  EXPECT_EQ(test_array[0], 0);
  EXPECT_EQ(test_array[1], 1);
  EXPECT_EQ(test_array[2], 2);
  EXPECT_EQ(test_array[3], 3);
  EXPECT_EQ(test_array[4], 4);
  EXPECT_EQ(test_array[5], 5);
}


/******************************************************************************
 * Test sort_int_array()
 *****************************************************************************/ 
// Test case where list is already sorted.
TEST(SortPointerArrayTest, Sorted) {
  int test_int_array[] = {0, 1, 2, 3, 4, 5};
  void *test_pointer_array[6];
  for (int i = 0; i < 6; i++) {
    test_pointer_array[i] = static_cast<void *>(&test_int_array[i]);
  }

  SortPointerArray(test_pointer_array, 6, IntGreaterThan);

  EXPECT_EQ(*static_cast<int *>(test_pointer_array[0]), 0);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[1]), 1);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[2]), 2);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[3]), 3);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[4]), 4);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[5]), 5);
}


// Test case where there is one inversion.
TEST(SortPointerArrayTest, OneInversion) {
  int test_int_array[] = {0, 1, 3, 2, 4, 5};
  void *test_pointer_array[6];
  for (int i = 0; i < 6; i++) {
    test_pointer_array[i] = static_cast<void *>(&test_int_array[i]);
  }

  SortPointerArray(test_pointer_array, 6, IntGreaterThan);

  EXPECT_EQ(*static_cast<int *>(test_pointer_array[0]), 0);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[1]), 1);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[2]), 2);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[3]), 3);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[4]), 4);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[5]), 5);
}


// Test case where the list is in reverse order.
TEST(SortPointerArrayTest, ReverseOrder) {
  int test_int_array[] = {5, 4, 3, 2, 1, 0};
  void *test_pointer_array[6];
  for (int i = 0; i < 6; i++) {
    test_pointer_array[i] = static_cast<void *>(&test_int_array[i]);
  }

  SortPointerArray(test_pointer_array, 6, IntGreaterThan);

  EXPECT_EQ(*static_cast<int *>(test_pointer_array[0]), 0);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[1]), 1);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[2]), 2);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[3]), 3);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[4]), 4);
  EXPECT_EQ(*static_cast<int *>(test_pointer_array[5]), 5);
}
