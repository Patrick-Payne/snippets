/******************************************************************************
 * File: test_quicksort.cc
 * Author: Patrick Payne
 * Date Created: Wed Oct  1 22:39:37 EDT 2014
 * Purpose:
 * Copyright Wed Oct  1 22:39:37 EDT 2014 by Patrick Payne.
 *****************************************************************************/
#include "quicksort.h"
#include "gtest/gtest.h"

/******************************************************************************
 * Test Cases
 *****************************************************************************/ 

TEST(INT_QUICKSORT, SINGLETON) {
  int in_list[1] = {1};
  int expected_list[1] = {1};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 1));

  expected_list[0] = 100;
  ASSERT_FALSE(test_sort(&(in_list[0]), &(expected_list[0]), 1));
}


TEST(INT_QUICKSORT, DOUBLETON) {
  int in_list[2] = {1, 2};
  int expected_list[2] = {1, 2};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 2));

  int in_list2[2] = {2, 1};
  ASSERT_TRUE(test_sort(&(in_list2[0]), &(expected_list[0]), 2));
}


TEST(INT_QUICKSORT, TRIPLETON) {
  int in_list[3] = {3, 2, 1};
  int expected_list[3] = {1, 2, 3};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 3));

  int in_list2[3] = {1, 3, 2};
  ASSERT_TRUE(test_sort(&(in_list2[0]), &(expected_list[0]), 3));
}


TEST(INT_QUICKSORT, FIVELTON) {
  int in_list[5] = {0, -1, 3, 8, 1};
  int expected_list[5] = {-1, 0, 1, 3, 8};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 5));
}


TEST(INT_QUICKSORT, LARGE_LIST) {
  int size = 10000;
  int in_list[10000];
  int expected_list[10000];

  for (int i = 0; i < size; i++) {
    in_list[i] = size - i;
    expected_list[i] = i + 1;
  }

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), size));
}

TEST(OTHER_TYPE_QUICKSORT, FLOATS) {
  double in_list[5] = {3.11, 3.54, 3.55, 10.001, -4.8};
  double expected_list[5] = {-4.8, 3.11, 3.54, 3.55, 10.001};

  ASSERT_TRUE(test_sort(&(in_list[0]), &(expected_list[0]), 5));
}
