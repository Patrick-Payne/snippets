/******************************************************************************
 * File: in_place_heap.h
 * Author: Patrick Payne
 * Date Created: Sep 20, 2013
 * Purpose: Implements a max-heap using an array, allow one to turn an array
 *   into a heap in place, and vice versa.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/ 

#ifndef SNIPPET_C_IN_PLACE_HEAP_H_
#define SNIPPET_C_IN_PLACE_HEAP_H_

/******************************************************************************
 * Type Declarations
 *****************************************************************************/ 

/* @brief the structure used to contain the ArrayHeap.
 * @details This implementation is slightly different from the conventional
 *    one in that the root node is placed at index 0, rather than index 1.
 *    This is less efficient, but makes it much easier to use this
 *    implementation for an in-place heapsort. The left child of a node at
 *    index i is given by 2i + 1, The right child by 2i + 2 = 2(i + 1).
 *    The parent of a node at index i is given by (i - 1) / 2.
 *
 * @note This is declared here both to facilitate testing and due to
 *    limitations when forward-declaring in C++ (which is used for the test
 *    scripts);
 */
typedef struct ArrayHeap {
  int *array;
  int size;
  int capacity;
} ArrayHeap;


/******************************************************************************
 * Public Function Declarations
 *****************************************************************************/ 

/*! @brief Creates an empty ArrayHeap using the provided array.
 *  @param array The array that will be used to contain the heap.
 *  @param capacity The total capacity of the array.
 *  @return The empty ArrayHeap.
 *
 *  @note: The responsibility for allocating AND deallocating the memory for
 *    the array rests entirely on the caller.
 */
ArrayHeap CreateArrayHeap(int *array, int capacity);


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
ArrayHeap Heapify(int *array, int capacity, int size);


/*! @brief Finds the maximum element of the ArrayHeap, without removing it.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the maximum element in the ArrayHeap
 *
 *  @pre There must be at least 1 element in the heap.
 */
int FindMax(ArrayHeap *heap);


/*! @brief Finds the minimum element of the ArrayHeap, without removing it.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the minimum element in the ArrayHeap
 *
 *  @pre There must be at least 1 element in the heap.
 */
int FindMin(ArrayHeap *heap);


/*! @brief Deletes and returns the maximum element of the ArrayHeap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the maximum element in the heap.
 *
 *  @pre There must be at least 1 element in the heap.
 */
int PopMax(ArrayHeap *heap);


/*! @brief Deletes and returns the minimum element of the ArrayHeap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The integer value of the minimum element in the heap.
 *
 *  @pre There must be at least 1 element in the heap.
 */
int PopMin(ArrayHeap *heap);


/*! @brief Inserts an integer into an existing ArrayHeap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @param new_item The new integer to add to the heap.
 *
 *  @pre The ArrayHeap must have the capacity for the additional item.
 */
void InsertItem(ArrayHeap *heap, int new_item);


/*! @brief Returns the size of a heap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The number of elements in the heap.
 */
int GetSize(ArrayHeap *heap);


/*! @brief Returns the maximum capacity of the heap.
 *  @param heap A pointer to the ArrayHeap in question.
 *  @return The maximum capacity of the heap.
 */
int GetCapacity(ArrayHeap *heap);

/*! @brief Prints out the values in the heap array.
 *  @param heap A pointer to the ArrayHeap in question.
 */
void PrintHeap(ArrayHeap *heap);
#endif /* SNIPPET_C_IN_PLACE_HEAP_H_ */
