/******************************************************************************
 * File: quicksort.c
 * Author: Patrick Payne
 * Date Created: Nov 03, 2013
 * Purpose: Defines a basic in-place quicksort algorithm.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

/******************************************************************************
 * PRIVATE FUNCTION DECLARATIONS:
 *****************************************************************************/ 

static int Partition(int *list, int left, int right, int pivot_index);

static void Swap(int *list, int index1, int index2);


/******************************************************************************
 * PUBLIC FUNCTION DECLARATIONS:
 *****************************************************************************/ 

/*! @brief Sorts an array of integers using an in-place quicksort.
 *  @param list A pointer to the first item in the array.
 *  @param left The first valid index in the array.
 *  @param right The last valid index in the array.
 */
void QuickSort(int *list, int left, int right) {
  // Handle the base case where there are no items in the list.
  if (left >= right) {
    return;
  }

  // Select a pivot. For simplicity, just pick the middle item.
  int pivot_index = left + (right - left) / 2;

  // Partition the list into items smaller and bigger than the pivot.
  pivot_index = Partition(list, left, right, pivot_index);

  // Recursively sort the lower and upper partitions.
  QuickSort(list, left, pivot_index - 1);
  QuickSort(list, pivot_index + 1, right);
}


/******************************************************************************
 * PRIVATE FUNCTION DEFINITIONS:
 *****************************************************************************/ 

/*! @brief Partitions a sublist into elements smaller than the pivot and 
 *      elements larger than the pivot. The smaller elements are placed
 *      to the left of the pivot, and larger/equal elements are placed
 *      to the right.
 *  @param list A pointer to the first item in the array.
 *  @param left The first valid index in the array.
 *  @param right The last valid index in the array.
 *  @param pivot_index The starting index of the pivot.
 *  @return The new index of the pivot.
 */
static int Partition(int *list, int left, int right, int pivot_index) {
  // Move the pivot to the end of the list temporarily.
  int pivot_value = list[pivot_index];
  Swap(list, pivot_index, right);

  // Move all lesser items to the left, larger ones to the right.
  int new_pivot_index = left;
  for (int i = left; i < right; i++) {
    if (list[i] < pivot_value) {
      Swap(list, i, new_pivot_index);
      new_pivot_index++;
    }
  }

  // Put the pivot back in its correct location.
  Swap(list, new_pivot_index, right);
  return new_pivot_index;
}


/*! @brief swaps two elements in an array.
 *  @param list A pointer to the first item in the array.
 *  @param index1 The index of the first element to swap.
 *  @param index2 The index of the second element to swap.
 */
static void Swap(int *list, int index1, int index2) {
  int temp = list[index1];
  list[index1] = list[index2];
  list[index2] = temp;
}
