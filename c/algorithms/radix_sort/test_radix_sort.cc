/******************************************************************************
 * File: test_radix_sort.cc
 * Author: Patrick Payne
 * Date Created: Sat Oct  4 16:56:27 EDT 2014
 * Purpose:
 * Copyright Sat Oct  4 16:56:27 EDT 2014 by Patrick Payne.
 *****************************************************************************/

extern "C" {
#include "radix_sort.h"
}

#include "gtest/gtest.h"

/*!Returns true if two lists are equal. */
template <class T>
bool AreListsEqual(T *list1, T*list2, int size) {
  for (int i = 0; i < size; i++) {
    if (list1[i] != list2[i]) {
      return false;
    }
  }

  return true;
}

/******************************************************************************
 * Test Cases
 *****************************************************************************/ 

TEST(TEST_COUNTING_SORT, SINGLETON) {
  int in_list[1] = {1};
  int expected[1] = {1};
  CountingSort(in_list, 1, 0, 1);
  ASSERT_TRUE(AreListsEqual(in_list, expected, 1));
}


TEST(TEST_COUNTING_SORT, DOUBLETON) {
  int in_list[2] = {2, 1};
  int expected[2] = {2, 1};
  
  // 2 comes before 1 when sorting by bit 0.
  CountingSort(in_list, 2, 0, 1);
  ASSERT_TRUE(AreListsEqual(in_list, expected, 2));

  // Using a digit width of 2 bits, sorting is done correctly.
  expected[0] = 1;
  expected[1] = 2;
  CountingSort(in_list, 2, 0, 2);
  ASSERT_TRUE(AreListsEqual(in_list, expected, 2));
}


TEST(TEST_COUNTING_SORT, LARGE_LIST) {
  int in_list[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int expected[12] = {4, 8, 12, 1, 5, 9, 2, 6, 10, 3, 7, 11};
  
  // We are sorting by the value of the lower two bits only.
  CountingSort(in_list, 12, 0, 2);
  ASSERT_TRUE(AreListsEqual(in_list, expected, 12));
}


TEST(TEST_RADIX_SORT, SINGLETON) {
  int in_list[1] = {1};
  int expected[1] = {1};
  RadixSort(in_list, 1, 2);
  ASSERT_TRUE(AreListsEqual(in_list, expected, 1));
}


TEST(TEST_RADIX_SORT, SORT_LARGE_LIST) {
  int in_list[10000];
  int expected[10000];
  for (int i = 0; i < 10000; i++) {
    in_list[i] = 9999 - i;
    expected[i] = i;
  }
  RadixSort(in_list, 10000, 2);
  ASSERT_TRUE(AreListsEqual(in_list, expected, 10000));
}
