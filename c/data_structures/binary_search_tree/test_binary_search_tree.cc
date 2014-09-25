/******************************************************************************
 * File: test_binary_search_tree.cc
 * Author: Patrick Payne
 * Date Created: Sep 19, 2014
 * Purpose: Tests the BST implementation from binary_search_tree.c
 * Copyright 2014 by Patrick Payne.
 *****************************************************************************/
extern "C" {
#include "binary_search_tree.h"
}

#include "gtest/gtest.h"

/******************************************************************************
 * TEST BASIC LINKED LIST FUNCTIONALITY:
 *****************************************************************************/ 

TEST(BasicFunctionality, Create) {
  BST *new_bst = create_bst();
  ASSERT_NE((BST *) NULL, new_bst);
  ASSERT_EQ(0, new_bst->size);

  destroy_bst(new_bst);
}

TEST(BasicFunctionality, Insert) {
  BST *new_bst = create_bst();

  // Insert the first item.
  insert_into_bst(new_bst, 1);
  ASSERT_EQ(1, new_bst->size);
  ASSERT_TRUE(bst_contains(new_bst, 1));

  // Insert the second item.
  ASSERT_FALSE(bst_contains(new_bst, 2));
  insert_into_bst(new_bst, 2);
  ASSERT_EQ(2, new_bst->size);
  ASSERT_TRUE(bst_contains(new_bst, 2));

  // The BST should not allow duplicates.
  insert_into_bst(new_bst, 2);
  ASSERT_EQ(2, new_bst->size);

  // Insert a third value.
  insert_into_bst(new_bst, -1);
  ASSERT_EQ(3, new_bst->size);
  ASSERT_TRUE(bst_contains(new_bst, -1));
  ASSERT_TRUE(bst_contains(new_bst, 1));
  ASSERT_TRUE(bst_contains(new_bst, 2));

  destroy_bst(new_bst);
}

TEST(BasicFunctionality, Delete) {
  BST *new_bst = create_bst();
  insert_into_bst(new_bst, 0);
  insert_into_bst(new_bst, -3);
  insert_into_bst(new_bst, 2);
  insert_into_bst(new_bst, 3);
  insert_into_bst(new_bst, 1);
  insert_into_bst(new_bst, -1);
  insert_into_bst(new_bst, -2);

  ASSERT_TRUE(bst_contains(new_bst, -3));
  ASSERT_TRUE(bst_contains(new_bst, -2));
  ASSERT_TRUE(bst_contains(new_bst, -1));
  ASSERT_TRUE(bst_contains(new_bst, 0));
  ASSERT_TRUE(bst_contains(new_bst, 1));
  ASSERT_TRUE(bst_contains(new_bst, 2));
  ASSERT_TRUE(bst_contains(new_bst, 3));
  ASSERT_EQ(7, new_bst->size);

  remove_from_bst(new_bst, -2);
  ASSERT_EQ(6, new_bst->size);
  ASSERT_FALSE(bst_contains(new_bst, -2));
  ASSERT_TRUE(bst_contains(new_bst, 3));

  remove_from_bst(new_bst, -3);
  ASSERT_EQ(5, new_bst->size);
  ASSERT_FALSE(bst_contains(new_bst, -3));
  ASSERT_TRUE(bst_contains(new_bst, -1));

  remove_from_bst(new_bst, 0);
  ASSERT_EQ(4, new_bst->size);
  ASSERT_FALSE(bst_contains(new_bst, 0));
  ASSERT_TRUE(bst_contains(new_bst, -1));
  ASSERT_TRUE(bst_contains(new_bst, 2));
  ASSERT_TRUE(bst_contains(new_bst, 1));
  ASSERT_TRUE(bst_contains(new_bst, 3));

  remove_from_bst(new_bst, 3);
  ASSERT_EQ(3, new_bst->size);
  ASSERT_FALSE(bst_contains(new_bst, 3));

  destroy_bst(new_bst);
}
