/******************************************************************************
 * File: test_insertion_sort_linked_list.cc
 * Author: Patrick Payne
 * Date Created: Sun Sep 28 15:41:06 EDT 2014
 * Purpose:
 * Copyright Sun Sep 28 15:41:06 EDT 2014 by Patrick Payne.
 *****************************************************************************/
extern "C" {
#include "insertion_sort_linked_list.h"
}

#include "gtest/gtest.h"

/******************************************************************************
 * Test Cases
 *****************************************************************************/ 

TEST(TEST_SORT, SINGLETON) {
  int input_list[1] = {1};
  int expected_list[1] = {1};

  ASSERT_TRUE(test_sort(&input_list[0], &expected_list[0], 1));
}

TEST(TEST_SORT, DOUBLETON) {
  int input_list[2] = {1, 2};
  int expected_list[2] = {1, 2};

  ASSERT_TRUE(test_sort(&input_list[0], &expected_list[0], 2));

  input_list[0] = 2;
  input_list[1] = 1;
  ASSERT_TRUE(test_sort(&input_list[0], &expected_list[0], 2));
}


TEST(TEST_SORT, TRIPLETON) {
  int input_list[3] = {3, 2, 1};
  int expected_list[3] = {1, 2, 3};

  ASSERT_TRUE(test_sort(&input_list[0], &expected_list[0], 3));
}


TEST(TEST_SORT, TEST_LARGE) {
  int size = 10000;
  int list1[10000];
  int list2[10000];

  for (int i = 0; i < size; i++) {
    list1[i] = size - i;
    list2[i] = i + 1;
  }

  ASSERT_TRUE(test_sort(&list1[0], &list2[0], size));
}
