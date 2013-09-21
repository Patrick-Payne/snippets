/******************************************************************************
 * File: in_place_heap.c
 * Author: Patrick Payne
 * Date Created: Sep 20, 2013
 * Purpose: Implements a heap using an array, allow one to turn an array into
 *    a heap in place, and vice versa.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/ 

#include "in_place_heap.h"

#include <stdio.h>
#include <assert.h>

/******************************************************************************
 * Macro Definitions
 *****************************************************************************/ 

/*! @brief Returns the index of the parent node for the item at index i. */
#define PARENT(i) (((i) - 1) / 2)

/*! @brief Returns the index of the left child of the node at index i. */
#define LEFT(i) ((2 * (i)) + 1)

/*! @brief Returns the index of the right child of the node at index i. */
#define RIGHT(i) (2 * ((i) + 1))

/******************************************************************************
 * Private Function Declarations
 *****************************************************************************/ 
/*! @brief Percolates the root item down the heap to restore the heap property.
 *  @param heap The ArrayHeap in question.
 */
static void PercolateDown(ArrayHeap *heap);


/*! @brief Percolates the last item up the heap to restore the heap property.
 *  @param heap The ArrayHeap in question.
 */
static void PercolateUp(ArrayHeap *heap);

/*! @brief Swaps the items at the given indices in the heap array.
 *  @param heap The ArrayHeap in question.
 *  @param index1 The index of the first item.
 *  @param index2 The index of hte second item.
 */
static void SwapNodes(ArrayHeap *heap, int index1, int index2);

/******************************************************************************
 * Public Function Definitions
 *****************************************************************************/ 

ArrayHeap CreateArrayHeap(int *array, int capacity) {
  ArrayHeap new_heap;
  new_heap.array = array;
  new_heap.capacity = capacity;
  new_heap.size = 0;

  return new_heap;
}


/*! @brief Creates a heap out of a given array of integer elements.
 *  @param array The array that will be used to contain the heap.
 *  @param capacity The total array capacity to be used for the heap.
 *  @param size The number of elements already in the array to consider as part
 *         of the heap.
 *  @return The new ArrayHeap.
 *
 *  @note: The responsibility for allocating AND deallocating the memory for
 *    the array rests entirely on the caller.
 */
ArrayHeap Heapify(int *array, int capacity, int size) {
  ArrayHeap new_heap;
  new_heap.array = array;
  new_heap.capacity = capacity;
  new_heap.size = 0;

  return new_heap;
}


/*! @brief Finds the maximum element of the ArrayHeap, without removing it.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the maximum element in the ArrayHeap
 *
 *  @pre There must be at least 1 element in the heap.
 */
int FindMax(ArrayHeap *heap) {
  assert(heap != NULL);
  assert(heap->size > 0);
  return heap->array[0];
}


/*! @brief Finds the minimum element of the ArrayHeap, without removing it.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the minimum element in the ArrayHeap
 *
 *  @pre There must be at least 1 element in the heap.
 */
int FindMin(ArrayHeap *heap) {
  assert(heap != NULL);
  assert(heap->size > 0);
  int *array = heap->array;
  int last_index = heap->size - 1;

  int minimum = array[last_index];
  int i = last_index;
  // We only have to search the leafs to find the minimum node; If a node has
  // a valid left child, it is not a leaf.
  while((i > 0) && (LEFT(i) > last_index)) {
    if (array[i] < minimum) {
      minimum = array[i];
    }

    // Move left along the leaves.
    i--;
  } /* WHILE */

  return minimum;
}


/*! @brief Deletes and returns the maximum element of the ArrayHeap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the maximum element in the heap.
 *
 *  @pre There must be at least 1 element in the heap.
 */
int PopMax(ArrayHeap *heap) {
  assert(heap != NULL);
  assert(heap->size > 0);

  int max = heap->array[0];

  // Put the last leaf in the heap into the root, and percolate it down to
  // restore the heap property.
  heap->array[0] = heap->array[heap->size - 1];
  heap->size--;
  PercolateDown(heap);

  return max;
}


/*! @brief Deletes and returns the minimum element of the ArrayHeap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the minimum element in the heap.
 *
 *  @pre There must be at least 1 element in the heap.
 */
int PopMin(ArrayHeap *heap) {
  assert(heap != NULL);
  return 0;
}


/*! @brief Inserts an integer into an existing ArrayHeap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @param new_item The new integer to add to the heap.
 *
 *  @pre The ArrayHeap must have the capacity for the additional item.
 */
void InsertItem(ArrayHeap *heap, int new_item) {
  assert(heap != NULL);
  assert(heap->capacity > heap->size);

  // The current last item is at (size - 1), so put the new item after that.
  heap->array[heap->size] = new_item;
  heap->size++;

  // Percolate the node up to restore the heap property.
  PercolateUp(heap);

  return;
}


/*! @brief Returns the size of a heap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The number of elements in the heap.
 */
int GetSize(ArrayHeap *heap) {
  assert(heap != NULL);
  return heap->size;
}


/*! @brief Returns the maximum capacity of the heap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The maximum capacity of the heap.
 */
int GetCapacity(ArrayHeap *heap) {
  assert(heap != NULL);
  return heap->capacity;
}


/*! @brief Prints out the values in the heap array.
 *  @param heap A pointer to the ArrayHeap in question.
 */
void PrintHeap(ArrayHeap *heap)
{
  assert(heap != NULL);

  if (heap->size == 0) {
    printf("[]\n");
  }

  printf("[");
  for(int i = 0; i < (heap->size - 2); i++) {
    printf("%d, ", heap->array[i]);
  }
  printf("%d]\n", heap->array[heap->size - 1]);
}


/******************************************************************************
 * Private Function Definitions
 *****************************************************************************/ 

/*! @brief Percolates the root item down the heap to restore the heap property.
 *  @param heap The ArrayHeap in question.
 */
static void PercolateDown(ArrayHeap *heap) {
  assert(heap != NULL);

  // The root of this heap implementation is at index zero.
  int i = 0;
  int *array = heap->array;
  int last_index = heap->size - 1;

  // Keep percolating down until the heap property is satisfied. We make sure
  // to check if the node even has a left or right child before comparing.
  while ((LEFT(i) <= last_index && array[i] < array[LEFT(i)]) ||
         (RIGHT(i) <= last_index && array[i] < array[RIGHT(i)])) {
    if (RIGHT(i) <= last_index && array[RIGHT(i)] > array[LEFT(i)]) {
      // The right child is greater than both the left child and parent nodes.
      SwapNodes(heap, i, RIGHT(i));
      i = RIGHT(i);
    } else {
      // The left child is greater than both the right child and parent nodes.
      SwapNodes(heap, i, LEFT(i));
      i = LEFT(i);
    }
  } /* WHILE */
}


/*! @brief Percolates the last item up the heap to restore the heap property.
 *  @param heap The ArrayHeap in question.
 */
static void PercolateUp(ArrayHeap *heap) {
  assert(heap != NULL);
  assert(heap->size > 0);

  // The last leaf in the heap is at index (size - 1)
  int i = heap->size - 1;
  int *array = heap->array;

  // Keep percolating up until the heap property is satisfied.
  while ((i > 0) && (array[i] > array[PARENT(i)])) {
    SwapNodes(heap, i, PARENT(i));
    i = PARENT(i);
  }
}


/*! @brief Swaps the items at the given indices in the heap array.
 *  @param heap The ArrayHeap in question.
 *  @param index1 The index of the first item.
 *  @param index2 The index of hte second item.
 */
static void SwapNodes(ArrayHeap *heap, int index1, int index2)
{
  assert(heap != NULL);
  assert(index1 >= 0 && index2 >= 0);
  assert(index1 < heap->size && index2 < heap->size);

  int temp = heap->array[index1];
  heap->array[index1] =  heap->array[index2];
  heap->array[index2] =  temp;
}
