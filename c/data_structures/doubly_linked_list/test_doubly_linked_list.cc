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

TEST(BasicFunctionality, CreateAndDestroy) {
  List *test_list = CreateList();
  EXPECT_EQ(0, test_list->size);
  EXPECT_EQ(NULL, test_list->dummy_first.prev);
  EXPECT_EQ(NULL, test_list->dummy_last.next);
  EXPECT_EQ(&(test_list->dummy_first), test_list->dummy_last.prev);
  EXPECT_EQ(&(test_list->dummy_last), test_list->dummy_first.next);
}
