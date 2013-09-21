/******************************************************************************
 * File: test_in_place_heap.cc
 * Author: Patrick Payne
 * Date Created: Sep 20, 2013
 * Purpose: To test the in-place heap defined by in_place_heap.h
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/
extern "C" {
#include "in_place_heap.h"
}

#include "gtest/gtest.h"

/******************************************************************************
 * Macro Definitions
 *****************************************************************************/ 

/*! @brief Returns the index of the parent node for the item at index i. */
#define PARENT(i) (((i) - 1) / 2)

/*! @brief Returns the index of the left child of the node at index i. */
#define LEFT_CHILD(i) ((2 * (i)) + 1)

/*! @brief Returns the index of the right child of the node at index i. */
#define RIGHT_CHILD(i) (2 * ((i) + 1))


/******************************************************************************
 * Basic Functionality Test Suite
 *****************************************************************************/ 

TEST(BasicFunctionality, CreateEmptyHeap) {
  int array[20];
  ArrayHeap empty_heap = CreateArrayHeap(array, 20);

  // Check that the capacity and size are set correctly upon heap creation.
  EXPECT_EQ(0, GetSize(&empty_heap));
  EXPECT_EQ(20, GetCapacity(&empty_heap));
}

TEST(BasicFunctionality, InsertItem) {
  int array[20];
  ArrayHeap heap = CreateArrayHeap(array, 20);

  // Check that the first element added is placed at the root.
  InsertItem(&heap, 1);
  EXPECT_EQ(1, FindMax(&heap));
  EXPECT_EQ(1, FindMin(&heap));
  EXPECT_EQ(1, GetSize(&heap));

  // Insert a smaller item.
  InsertItem(&heap, -1);
  EXPECT_EQ(1, FindMax(&heap));
  EXPECT_EQ(-1, FindMin(&heap));
  EXPECT_EQ(2, GetSize(&heap));

  InsertItem(&heap, -2);
  EXPECT_EQ(1, FindMax(&heap));
  EXPECT_EQ(-2, FindMin(&heap));
  EXPECT_EQ(3, GetSize(&heap));

  // Insert larger items.
  InsertItem(&heap, 10);
  EXPECT_EQ(10, FindMax(&heap));
  EXPECT_EQ(-2, FindMin(&heap));
  EXPECT_EQ(4, GetSize(&heap));

  InsertItem(&heap, 15);
  EXPECT_EQ(15, FindMax(&heap));
  EXPECT_EQ(-2, FindMin(&heap));
  EXPECT_EQ(5, GetSize(&heap));

  // Insert a middle item.
  InsertItem(&heap, 13);
  EXPECT_EQ(15, FindMax(&heap));
  EXPECT_EQ(-2, FindMin(&heap));
  EXPECT_EQ(6, GetSize(&heap));
}


TEST(BasicFunctionality, PopMax) {
  // Create the heap
  int array[20];
  ArrayHeap heap = CreateArrayHeap(array, 20);
  InsertItem(&heap, 1);
  InsertItem(&heap, 2);
  InsertItem(&heap, 3);
  InsertItem(&heap, 4);
  InsertItem(&heap, 5);
  InsertItem(&heap, 6);
  InsertItem(&heap, 7);
  InsertItem(&heap, 8);

  // Now pop each max element one by one.
  EXPECT_EQ(8, PopMax(&heap));
  EXPECT_EQ(7, PopMax(&heap));
  EXPECT_EQ(6, PopMax(&heap));
  EXPECT_EQ(5, PopMax(&heap));
  EXPECT_EQ(4, PopMax(&heap));
  EXPECT_EQ(3, PopMax(&heap));
  EXPECT_EQ(2, PopMax(&heap));
  EXPECT_EQ(1, PopMax(&heap));
}
