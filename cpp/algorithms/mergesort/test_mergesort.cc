/******************************************************************************
 * File: test_mergesort.cc
 * Author: Patrick Payne
 * Date Created: Sat Oct  4 21:10:23 EDT 2014
 * Purpose:
 * Copyright Sat Oct  4 21:10:23 EDT 2014 by Patrick Payne.
 *****************************************************************************/

#include "mergesort.h"
#include "gtest/gtest.h"

/*! A template for checking if two arrays are equal. */
template <class T>
bool test_sort(T *original_list, T *expected_output, int size, int threshold) {
  MergeSort(original_list, size, threshold);

  for (int i = 0; i < size; i++) {
    if (original_list[i] != expected_output[i]) {
      return false;
    }
  }
  return true;
}

/******************************************************************************
 * Test Cases
 *****************************************************************************/ 

TEST(INT_MERGESORT, SINGLETON) {
  int in_list[1] = {1};
  int expected_list[1] = {1};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 1, 0));

  expected_list[0] = 100;
  ASSERT_FALSE(test_sort(&(in_list[0]), &(expected_list[0]), 1, 0));
}


TEST(INT_MERGESORT, DOUBLETON) {
  int in_list[2] = {1, 2};
  int expected_list[2] = {1, 2};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 2, 0));

  int in_list2[2] = {2, 1};
  ASSERT_TRUE(test_sort(&(in_list2[0]), &(expected_list[0]), 2, 0));
}


TEST(INT_MERGESORT, TRIPLETON) {
  int in_list[3] = {3, 2, 1};
  int expected_list[3] = {1, 2, 3};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 3, 0));

  int in_list2[3] = {1, 3, 2};
  ASSERT_TRUE(test_sort(&(in_list2[0]), &(expected_list[0]), 3, 0));
}


TEST(INT_MERGESORT, FIVELTON) {
  int in_list[5] = {0, -1, 3, 8, 1};
  int expected_list[5] = {-1, 0, 1, 3, 8};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 5, 0));
}


TEST(INT_MERGESORT, LARGE_LIST) {
  int size = 10000;
  int in_list[10000];
  int expected_list[10000];

  for (int i = 0; i < size; i++) {
    in_list[i] = size - i;
    expected_list[i] = i + 1;
  }

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), size, 0));
}


TEST(INT_MERGESORT, NONZERO_THRESHOLD) {
    int size = 10000;
    int max_threshold = 100;

    for (int threshold = 0; threshold < max_threshold; threshold++) {
      int in_list[10000];
      int expected_list[10000];
      for (int i = 0; i < size; i++) {
        in_list[i] = size - i;
        expected_list[i] = i + 1;
      }

      ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), size, threshold));
    }
}


TEST(OTHER_TYPE_MERGESORT, FLOATS) {
  double in_list[5] = {3.11, 3.54, 3.55, 10.001, -4.8};
  double expected_list[5] = {-4.8, 3.11, 3.54, 3.55, 10.001};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 5, 0));
}

