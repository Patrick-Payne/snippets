/******************************************************************************
 * File: quick_select.c
 * Author: Patrick Payne
 * Date Created: Oct 21, 2013
 * Purpose: Implements a basic array quick select algorithm.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

#include "quick_select.h"

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

/*! @brief Given an array of integers, determine the kth smallest.
 *     element.
 *  @param list A pointer to the first element in the array.
 *  @param size The number of valid elements in the array.
 *  @param k One more than the number of elements smaller than
 *     the number returned.
 *  @return The kth smallest integer in list.
 */
int QuickSelect(int *list, int size, int k) {
    // Check that the inputs are valid
    assert(list != NULL);
    assert(size > 0);
    assert(k > 0);
    assert(size >= k);

     int left = 0;
    int right = size - 1;

     while (true) {
        // Choose a pivot, and partition the array.
        int pivot = left;
        pivot = Partition(list, left, right, pivot);

        // Determine how many elements are smaller or equal to
        // the pivot element.
        int pivot_position = pivot + 1;
        if (pivot_position > k) {
            // There are more than k-1 smaller elements.
            right = pivot - 1;
        } else if (pivot_position < k) {
            // There are fewer than k-1 smaller elements.
            left = pivot + 1;
         } else {
            // We have found the kth item.
            return list[pivot];
        }
    }
}


/*! @brief Partitions an array of ints into elements smaller than the
 *    pivot element and elements larger than the pivot, in place.
 *  @param list A pointer to the first element in the array.
 *  @param left The starting index of the subarray.
 *  @param right The ending index of the subarray.
 *  @param pivot The index of the pivot element.
 *  @return The new index of the pivot.
 */
int Partition(int *list, int left, int right, int pivot) {
    int pivot_value = list[pivot];
    Swap(list, pivot, right);

    // Keep all elements smaller than the pivot to the left, and all
    // larger and equal items to the right.
    int store_index = left;
    for (int i = left; i < right; i++) {
        if (list[i] < pivot_value) {
            Swap(list, store_index, i);
            store_index++;
        }
    }

    // Move the pivot back to its proper location, and return it.
    // if ((store_index != left)) {
      Swap(list, right, store_index);
    // }
    return store_index;
}


/*! @brief Swaps two elements in an array of integers. */
void Swap(int *list, int index1, int index2) {
    int temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}

