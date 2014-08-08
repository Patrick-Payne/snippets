/******************************************************************************
 * File: test_reverse_c_linked_list.cpp
 * Author: Patrick Payne
 * Date Created: Sep 25, 2013
 * Purpose: Tests the linked_list reversal function from reverse_c_linked_list.h
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/
extern "C" {
#include "reverse_c_linked_list.h"
}

#include "gtest/gtest.h"

#define NODE_NULL ((Node *) 0)

/******************************************************************************
 * Test Cases
 *****************************************************************************/ 

/* Test the cases where we have no elements, or 1 element. */
TEST(ReverseLinkedList, SimpleCases) {
  // Test case were we have no elements.
  Node *list = NODE_NULL;
  ReverseList(&list);
  EXPECT_EQ(list, NODE_NULL);

  // Test case where we have 1 element.
  list = (Node *) malloc(sizeof(Node));
  list->value = 10;
  list->next = NODE_NULL;
  ReverseList(&list);
  EXPECT_NE(list, NODE_NULL);
  EXPECT_EQ(list->value, 10);
  EXPECT_EQ(list->next, NODE_NULL);
  free(list);
}


/* Test the cases where we have 2-3 elements. */
TEST(ReverseLinkedList, MultipleElements) {
  // Test case were we have 2 elements.
  Node *list = NODE_NULL;
  list = (Node *) malloc(sizeof(Node));
  list->value = 10;
  list->next = (Node *) malloc(sizeof(Node));
  list->next->value = 12;
  list->next->next = NODE_NULL;

  ReverseList(&list);
  EXPECT_NE(list, NODE_NULL);
  EXPECT_EQ(list->value, 12);
  EXPECT_NE(list->next, NODE_NULL);
  EXPECT_EQ(list->next->value, 10);
  EXPECT_EQ(list->next->next, NODE_NULL);

  // Now add another element.
  Node *new_item = (Node *) malloc(sizeof(Node));
  new_item->value = 11;
  new_item->next = list;
  list = new_item;

  ReverseList(&list);
  EXPECT_NE(list, NODE_NULL);
  EXPECT_EQ(list->value, 10);
  EXPECT_NE(list->next, NODE_NULL);
  EXPECT_EQ(list->next->value, 12);
  EXPECT_NE(list->next->next, NODE_NULL);
  EXPECT_EQ(list->next->next->value, 11);
  EXPECT_EQ(list->next->next->next, NODE_NULL);
}
