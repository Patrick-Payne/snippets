/******************************************************************************
 * File: test_bst.cc
 * Author: Patrick Payne
 * Date Created: Tue Oct  7 19:01:08 EDT 2014
 * Purpose: Tests the C++ implementation of a BST.
 * Copyright Tue Oct  7 19:01:08 EDT 2014 by Patrick Payne.
 *****************************************************************************/

#include "bst.h"
#include "gtest/gtest.h"

/******************************************************************************
 * Test Cases
 *****************************************************************************/ 

TEST(BST, BASIC_ADD_REMOVE) {
  BinaryTree<int> tree;

  ASSERT_EQ(0, tree.size());
  ASSERT_FALSE(tree.contains(0));
  
  tree.insert(0);
  ASSERT_EQ(1, tree.size());
  ASSERT_TRUE(tree.contains(0));
  ASSERT_FALSE(tree.contains(1));

  tree.insert(1);
  tree.insert(1);
  tree.insert(3);
  tree.insert(-3);
  tree.insert(-1);

  ASSERT_EQ(5, tree.size());
  ASSERT_TRUE(tree.contains(1));
  ASSERT_TRUE(tree.contains(3));
  ASSERT_TRUE(tree.contains(-3));
  ASSERT_TRUE(tree.contains(-1));

  ASSERT_FALSE(tree.remove(10));
  ASSERT_TRUE(tree.remove(0));
  ASSERT_TRUE(tree.remove(-3));
  ASSERT_TRUE(tree.remove(1));
  ASSERT_TRUE(tree.remove(-1));
  ASSERT_TRUE(tree.remove(3));
}

TEST(BST, EXHAUSTIVE_ADD_REMOVE) {
  BinaryTree<int> tree;

  for(int i = 1; i <= 1000; i++) {
    tree.insert(i);
    ASSERT_EQ(i, tree.size());
  }

  for(int i = 1; i <= 1000; i++) {
    ASSERT_TRUE(tree.contains(i));
  }

  for(int i = 1; i <= 1000; i++) {
    ASSERT_TRUE(tree.remove(i));
  }
}

TEST(BST, TEST_MIN_MAX) {
  BinaryTree<int> tree;
  tree.insert(1);
  tree.insert(1);
  tree.insert(3);
  tree.insert(-3);
  tree.insert(-1);

  int min, max, med;
  ASSERT_TRUE(tree.min(&min));
  ASSERT_TRUE(tree.max(&max));
  ASSERT_TRUE(tree.median(&med));

  ASSERT_EQ(-3, min);
  ASSERT_EQ(3, max);
  ASSERT_EQ(-1, med);
}

TEST(BST, GET_DEEPEST) {
  BinaryTree<int> tree;
  int deepest;
  ASSERT_FALSE(tree.deepest(&deepest));

  tree.insert(1);
  ASSERT_TRUE(tree.deepest(&deepest));
  ASSERT_EQ(1, deepest);
}
