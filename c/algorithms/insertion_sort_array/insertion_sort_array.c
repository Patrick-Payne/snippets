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
 *  @param: numElements The number of elements in the array.
 *  @pre: All elements from 0, ..., numElements are valid, i.e. array is packed
 *        to the left with no empty places.
 */
void sortIntArray(int array[], int numElements) {
  assert(numElements >= 0);

  for (int i = 0; i < numElements; i++) {
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

