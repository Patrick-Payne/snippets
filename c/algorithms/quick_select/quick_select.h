/******************************************************************************
 * File: quick_select.c
 * Author: Patrick Payne
 * Date Created: Oct 21, 2013
 * Purpose: Declares functions implementing a basic quick select algorithm,
 *    which determines the kth largest element in an array.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/


/*! @brief Given an array of integers, determine the kth smallest.
 *     element.
 *  @param list A pointer to the first element in the array.
 *  @param size The number of valid elements in the array.
 *  @param k One more than the number of elements smaller than
 *     the number returned.
 *  @return The kth smallest integer in list.
 */
int QuickSelect(int *list, int size, int k); 


/*! @brief Partitions an array of ints into elements smaller than the
 *    pivot element and elements larger than the pivot, in place.
 *  @param list A pointer to the first element in the array.
 *  @param left The starting index of the subarray.
 *  @param right The ending index of the subarray.
 *  @param pivot The index of the pivot element.
 *  @return The new index of the pivot.
 */
int Partition(int *list, int left, int right, int pivot); 


/*! @brief Swaps two elements in an array of integers. */
void Swap(int *list, int index1, int index2); 
