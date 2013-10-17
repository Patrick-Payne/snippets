extern "C" {
#include "binary_search.h"
}

#include "gtest/gtest.h"

/******************************************************************************
 * BASIC CASES:
 *****************************************************************************/ 

// Empty lists should return INVALID_INDEX for any search term.
TEST(BasicCases, EmptyList) {
  int list[30] = {};
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 0, 0));
}
  
// Test singleton lists.
TEST(BasicCases, Singletons) {
  int list[30] = {1};
  EXPECT_EQ(0, BinarySearch(list, 1, 1));
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 1, 0));
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 1, -500));

  list[0] = -500;
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 1, 1));
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 1, 0));
  EXPECT_EQ(0, BinarySearch(list, 1, -500));
}

// Test lists with 2 items.
TEST(BasicCases, Doubles) {
  int list[30] = {-1, 1};
  EXPECT_EQ(1, BinarySearch(list, 2, 1));
  EXPECT_EQ(0, BinarySearch(list, 2, -1));
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 2, 0));
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 2, -500));
}


// Test a list with 3 items.
TEST(BasicCases, Triples) {
  int list[30] = {-1, 0, 1};
  EXPECT_EQ(0, BinarySearch(list, 3, -1));
  EXPECT_EQ(1, BinarySearch(list, 3, 0));
  EXPECT_EQ(2, BinarySearch(list, 3, 1));
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 3, -500));
}


// Test lists with more items.
TEST(BasicCases, Multiple) {
  int list[30] = {-53,-10, 21, 70};
  EXPECT_EQ(0, BinarySearch(list, 4, -53));
  EXPECT_EQ(1, BinarySearch(list, 4, -10));
  EXPECT_EQ(2, BinarySearch(list, 4, 21));
  EXPECT_EQ(3, BinarySearch(list, 4, 70));
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 4, -500));
  EXPECT_EQ(INVALID_INDEX, BinarySearch(list, 4, 0));
}

/******************************************************************************
 * STRESS TESTING:
 *****************************************************************************/ 

// Test the case where we simply have a long list of sequential integers.
TEST(StressTesting, Count) {
  int test_sizes[5] = {100, 1000, 1111, 10000, 23427};
  for (int i = 0; i < 5; i++) {
    int *list = new int[test_sizes[i]];

    for (int j = 0; j < test_sizes[i]; j++) {
      list[j] = j;
    }

    // Now test that searching for each item returns correct results.
    for (int j = 0; j < test_sizes[i]; j++) {
      EXPECT_EQ(j, BinarySearch(list, test_sizes[i], j));
    }

    delete [] list;
  }
}
