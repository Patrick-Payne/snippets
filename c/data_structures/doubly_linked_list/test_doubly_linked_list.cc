/******************************************************************************
 * File: test_doubly_linked_list.cpp
 * Author: Patrick Payne
 * Date Created: Sep 30, 2013
 * Purpose: Test the doubly-linked list implementation in doubly_linked_list.c
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/extern "C" {
#include "doubly_linked_list.h"
}

#include "gtest/gtest.h"

/******************************************************************************
 * TEST BASIC LINKED LIST FUNCTIONALITY:
 *****************************************************************************/ 

TEST(BasicFunctionality, Create) {
  List *test_list = CreateList();
  EXPECT_EQ(0, test_list->size);
  EXPECT_EQ(NULL, test_list->dummy_first.prev);
  EXPECT_EQ(NULL, test_list->dummy_last.next);
  EXPECT_EQ(&(test_list->dummy_first), test_list->dummy_last.prev);
  EXPECT_EQ(&(test_list->dummy_last), test_list->dummy_first.next);

  DeleteList(test_list);
}

TEST(BasicFunctionality, Insert) {
  List *test_list = CreateList();

  // Test that we can add items to the beginning.
  AddItemToBeginning(test_list, 0);
  int check_item;
  EXPECT_TRUE(GetItem(test_list, 0, &(check_item)));
  EXPECT_EQ(0, check_item);
  EXPECT_FALSE(GetItem(test_list, 1, &(check_item)));

  AddItemToBeginning(test_list, 1);
  EXPECT_TRUE(GetItem(test_list, 0, &(check_item)));
  EXPECT_EQ(1, check_item);
  EXPECT_TRUE(GetItem(test_list, 1, &(check_item)));
  EXPECT_EQ(0, check_item);
  EXPECT_FALSE(GetItem(test_list, 2, &(check_item)));

  AddItemToBeginning(test_list, 10);
  EXPECT_TRUE(GetItem(test_list, 0, &(check_item)));
  EXPECT_EQ(10, check_item);
  EXPECT_TRUE(GetItem(test_list, 1, &(check_item)));
  EXPECT_EQ(1, check_item);
  EXPECT_TRUE(GetItem(test_list, 2, &(check_item)));
  EXPECT_EQ(0, check_item);
  EXPECT_FALSE(GetItem(test_list, 3, &(check_item)));

  // Now test that we can correctly add items to the end.
  AddItemToEnd(test_list, -22);
  EXPECT_TRUE(GetItem(test_list, 0, &(check_item)));
  EXPECT_EQ(10, check_item);
  EXPECT_TRUE(GetItem(test_list, 1, &(check_item)));
  EXPECT_EQ(1, check_item);
  EXPECT_TRUE(GetItem(test_list, 2, &(check_item)));
  EXPECT_EQ(0, check_item);
  EXPECT_TRUE(GetItem(test_list, 3, &(check_item)));
  EXPECT_EQ(-22, check_item);
  EXPECT_FALSE(GetItem(test_list, 4, &(check_item)));

  // Now test that we can correctly add items to the end.
  AddItemToEnd(test_list, 100);
  EXPECT_TRUE(GetItem(test_list, 0, &(check_item)));
  EXPECT_EQ(10, check_item);
  EXPECT_TRUE(GetItem(test_list, 1, &(check_item)));
  EXPECT_EQ(1, check_item);
  EXPECT_TRUE(GetItem(test_list, 2, &(check_item)));
  EXPECT_EQ(0, check_item);
  EXPECT_TRUE(GetItem(test_list, 3, &(check_item)));
  EXPECT_EQ(-22, check_item);
  EXPECT_TRUE(GetItem(test_list, 4, &(check_item)));
  EXPECT_EQ(100, check_item);
  EXPECT_FALSE(GetItem(test_list, 5, &(check_item)));

  DeleteList(test_list);
}


TEST(BasicFunctionality, Delete) {
  List *test_list = CreateList();
  int check_item;

  // Test that deletion doesn't do anything for an empty list.
  EXPECT_FALSE(PopFirstItem(test_list, &check_item));
  EXPECT_FALSE(PopLastItem(test_list, &check_item));
  
  // Test that deletion works on a list with only one element.
  AddItemToBeginning(test_list, 0);
  EXPECT_TRUE(PopLastItem(test_list, &check_item));
  EXPECT_EQ(0, check_item);
  EXPECT_EQ(0, test_list->size);

  AddItemToBeginning(test_list, 1);
  EXPECT_TRUE(PopFirstItem(test_list, &check_item));
  EXPECT_EQ(1, check_item);
  EXPECT_EQ(0, test_list->size);

  // Now add a large number of integers to the list.
  for (int i = 0; i < 100; i++) {
    AddItemToBeginning(test_list, i);
  }
  
  // Test deletion from the end.
  for (int i = 0; i < 100; i++) {
    EXPECT_TRUE(PopLastItem(test_list, &check_item));
    EXPECT_EQ(i, check_item);
  }

  EXPECT_EQ(0, test_list->size);

  // Now add a large number of integers to the list.
  for (int i = 0; i < 100; i++) {
    AddItemToEnd(test_list, i);
  }
  
  // Test deletion from the beginning.
  for (int i = 0; i < 100; i++) {
    EXPECT_TRUE(PopFirstItem(test_list, &check_item));
    EXPECT_EQ(i, check_item);
  }

  EXPECT_EQ(0, test_list->size);

  DeleteList(test_list);
}
