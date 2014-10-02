/******************************************************************************
 * File: quicksort.h
 * Author: Patrick Payne
 * Date Created: Wed Oct  1 22:39:37 EDT 2014
 * Purpose:
 * Copyright Wed Oct  1 22:39:37 EDT 2014 by Patrick Payne.
 *****************************************************************************/
#ifndef SNIPPET_C_QUICKSORT_H_
#define SNIPPET_C_QUICKSORT_H_

#include <cassert>
#include <cstdlib>

/*! Implements a general swap algorithm. */
template <class T>
void swap(T *list, int index1, int index2) {
  T temp;
  temp = list[index1];
  list[index1] = list[index2];
  list[index2] = temp;
}


/*! Implements a basic partitioning scheme for general arrays.
 * @param list The list of objects to partition.
 * @param begin The first index in the sublist to partition.
 * @param end The last index in the sublist to partition.
 * @param pivot_index The index of the pivot to partition around.
 * @return The final index of the partition.
 */
template <class T>
int partition(T *list, int begin, int end, int pivot_index) {
  assert(begin <= end);
  assert(begin <= pivot_index && pivot_index <= end);

  // Extract the pivot, and throw it to the end of the sublist.
  T pivot = list[pivot_index];
  swap(list, pivot_index, end);

  // Iterate from left to right, keeping all smaller elements to the left.
  int partition_index = begin;
  for (int i = begin; i < end; i++) {
    if (list[i] <= pivot) {
      swap(list, partition_index, i);
      partition_index++;
    }
  }

  // Put the pivot back in the middle.
  swap(list, partition_index, end);

  return partition_index;
}

/*! Implements an in-place quicksort algorithm for general arrays. */
template <class T>
void quicksort(T *list, int begin, int end) {
  if (begin < end) {
    int pivot_index = (rand() % (end - begin + 1)) + begin;
    pivot_index = partition(list, begin, end, pivot_index);

    quicksort(list, begin, pivot_index - 1);
    quicksort(list, pivot_index + 1, end);
  }
}


/*! A template for checking if two arrays are equal. */
template <class T>
bool test_sort(T *original_list, T *expected_output, int size) {
  quicksort(original_list, 0, size - 1);

  for (int i = 0; i < size; i++) {
    if (original_list[i] != expected_output[i]) {
      return false;
    }
  }
  return true;
}

#endif /* SNIPPET_C_QUICKSORT_H_ */
