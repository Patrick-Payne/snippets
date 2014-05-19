extern "C" {
#include "rod_cutting.h"
#include <stdlib.h>
}

#include "gtest/gtest.h"

/******************************************************************************
 * BASIC CASES:
 *****************************************************************************/ 

// Empty lists should return INVALID_INDEX for any search term.
TEST(BasicCases, FavourSingle) {
  int prices[3] = {10, 1, 1};
  int *solution = NULL;
  int num_cuts;
  int total_profit = RodCutting(prices, 3, 1, &solution, &num_cuts);
  ASSERT_NE(total_profit, -1);
  ASSERT_EQ(num_cuts, 1);
  EXPECT_EQ(total_profit, 10); 
  EXPECT_EQ(solution[0], 1); 
  free(solution);

  total_profit = RodCutting(prices, 3, 2, &solution, &num_cuts);
  ASSERT_NE(total_profit, -1);
  ASSERT_EQ(num_cuts, 2);
  EXPECT_EQ(total_profit, 20); 
  EXPECT_EQ(solution[0], 1); 
  EXPECT_EQ(solution[1], 1); 
  free(solution);

  total_profit = RodCutting(prices, 3, 3, &solution, &num_cuts);
  ASSERT_NE(total_profit, -1);
  ASSERT_EQ(num_cuts, 3);
  EXPECT_EQ(total_profit, 30); 
  EXPECT_EQ(solution[0], 1); 
  EXPECT_EQ(solution[1], 1); 
  EXPECT_EQ(solution[2], 1); 
  free(solution);
}

// Test some examples from the internet.
TEST(BasicCases, FromOnlineExamples) {
  int prices[8] = {1, 5, 8, 9, 10, 17, 17, 20};
  int *solution = NULL;
  int num_cuts;
  int total_profit = RodCutting(prices, 8, 8, &solution, &num_cuts);
  ASSERT_NE(total_profit, -1);
  ASSERT_EQ(num_cuts, 2);
  EXPECT_EQ(total_profit, 22); 
  EXPECT_EQ(solution[0], 2); 
  EXPECT_EQ(solution[1], 6); 
  free(solution);
}
