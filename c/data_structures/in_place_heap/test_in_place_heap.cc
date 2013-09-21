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
 * Internals Test Suite
 *****************************************************************************/ 


/******************************************************************************
 * Basic Functionality Test Suite
 *****************************************************************************/ 

TEST(BasicFunctionality, CreateEmptyHeap) {
  int array[20];
  ArrayHeap empty_heap;
  empty_heap = CreateArrayHeap(array, 20);

  // Check that the capacity and size are set correctly upon heap creation.
  EXPECT_EQ(0, GetSize(&empty_heap));
  EXPECT_EQ(20, GetCapacity(&empty_heap));
}


/******************************************************************************
 * Heapify Test Suite
 *****************************************************************************/ 
