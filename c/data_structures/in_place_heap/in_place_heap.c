/******************************************************************************
 * File: in_place_heap.c
 * Author: Patrick Payne
 * Date Created: Sep 20, 2013
 * Purpose: Implements a heap using an array, allow one to turn an array into
 *    a heap in place, and vice versa.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/ 

#include "in_place_heap.h"

/******************************************************************************
 * Structs
 *****************************************************************************/ 

struct ArrayHeap {
  int (*array)[];
  int size;
  int capacity;
};


/******************************************************************************
 * Public Function Definitions
 *****************************************************************************/ 

/*! @brief Creates an empty ArrayHeap using the provided array.
 *  @param array The array that will be used to contain the heap.
 *  @param capacity The total capacity of the array.
 *  @return The empty ArrayHeap.
 *
 *  @note: The responsibility for allocating AND deallocating the memory for
 *    the array rests entirely on the caller.
 */
ArrayHeap CreateArrayHeap(int *array, int capacity) {
  ArrayHeap new_heap;
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
  return new_heap;
}


/*! @brief Finds the maximum element of the ArrayHeap, without removing it.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the maximum element in the ArrayHeap
 *
 *  @pre There must be at least 1 element in the heap.
 */
int FindMax(ArrayHeap *heap) {
  return 0;
}


/*! @brief Finds the minimum element of the ArrayHeap, without removing it.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the minimum element in the ArrayHeap
 *
 *  @pre There must be at least 1 element in the heap.
 */
int FindMin(ArrayHeap *heap) {
  return 0;
}


/*! @brief Deletes and returns the maximum element of the ArrayHeap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the maximum element in the heap.
 *
 *  @pre There must be at least 1 element in the heap.
 */
int PopMax(ArrayHeap *heap) {
  return 0;
}


/*! @brief Deletes and returns the minimum element of the ArrayHeap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the minimum element in the heap.
 *
 *  @pre There must be at least 1 element in the heap.
 */
int PopMin(ArrayHeap *heap) {
  return 0;
}


/*! @brief Inserts an integer into an existing ArrayHeap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @param new_item The new integer to add to the heap.
 *
 *  @pre The ArrayHeap must have the capacity for the additional item.
 */
void InsertItem(ArrayHeap *heap, int new_item) {
  return;
}


/******************************************************************************
 * Private Function Definitions
 *****************************************************************************/ 
