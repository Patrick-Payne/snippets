/******************************************************************************
 * File: insertion_sort_array.c
 * Author: Patrick Payne
 * Date Created: Sep 13, 2013
 * Purpose: Implements basic in-place insertion sort algorithms for C arrays.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/ 

#include "insertion_sort_array.h"

#include <assert.h>


/*! @brief: Sorts an array of ints in increasing order.
 *  @param: array The array of ints to be sorted.
 *  @param: num_elements The number of elements in the array.
 *  @pre: All elements from 0, ..., numElements are valid, i.e. array is packed
 *        to the left with no empty places.
 */
void SortIntArray(int array[], int num_elements) {
  assert(num_elements >= 0);

  for (int i = 0; i < num_elements; i++) {
    // Get the leftmost unsorted element to insert into the sorted subarray.
    int leftmost_unsorted_int = array[i];

    // Shift all greater elements to the right to make room for the element.
    int ins_index = i;
    while ((leftmost_unsorted_int < array[ins_index - 1]) && ins_index > 0) {
      array[ins_index] = array[ins_index - 1];
      ins_index--;
    }

    // Put the element into its correct location.
    array[ins_index] = leftmost_unsorted_int;
  } /* for */
}


/*! @brief: Sorts an array of pointers in increasing order using a provided
 *          comparison function.
 *  @param: array The array of ints to be sorted.
 *  @param: num_elements The number of elements in the array.
 *  @param: greater_than A function returning true if its first input is
 *          greater than its second input.
 *  @pre: All elements from 0, ..., numElements are valid, i.e. array is packed
 *        to the left with no empty places.
 */
void SortPointerArray(void *array[], int num_elements,
                      int (*greater_than)(void *, void *)) {
  assert(num_elements >= 0);

  for (int i = 0; i < num_elements; i++) {
    // Get the leftmost unsorted element to insert into the sorted subarray.
    void *leftmost_unsorted_pointer = array[i];

    // Shift all greater elements to the right to make room for the element.
    int ins_index = i;
    while ((ins_index > 0) &&
           greater_than(array[ins_index - 1], leftmost_unsorted_pointer)) {
      array[ins_index] = array[ins_index - 1];
      ins_index--;
    }

    // Put the element into its correct location.
    array[ins_index] = leftmost_unsorted_pointer;
  } /* for */
}
