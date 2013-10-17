/******************************************************************************
 * File: binary_search.c
 * Author: Patrick Payne
 * Date Created: Oct 16, 2013
 * Purpose: Implements a basic iterative binary search algorithm.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

#include "binary_search.h"

/*! @brief Searches for an integer within an array of integers.
 *  @param list The pointer to the beginning of the integer array.
 *  @param size The number of elements within the list.
 *  @param item The integer to search for.
 *  @return The index of the item in the list if it is found, otherwise return
 *      INVALID_INDEX.
 */
int BinarySearch(int *list, int size, int item) {
  // We start with the entire list to search from.
  int left = 0;
  int right = size - 1;

  // We keep searching until it is clear that the item is not in the list.
  while (right >= left) {
    int mid = (left + right) / 2;

    if (list[mid] > item) {
      right = mid - 1;
    } else if (list[mid] < item) {
      left = mid + 1;
    } else {
      return mid;
    }
  }

  // If we arrive here, the item is not in the list.
  return INVALID_INDEX;
}
