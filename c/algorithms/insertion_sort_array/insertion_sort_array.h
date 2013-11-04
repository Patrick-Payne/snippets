/******************************************************************************
 * File: insertion_sort_array.h
 * Author: Patrick Payne
 * Date Created: Sep 13, 2013
 * Purpose: Defines the external interface to the array sorting function.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/ 
#ifndef SNIPPET_INSERTION_SORT_ARRAY_H_

#define SNIPPET_INSERTION_SORT_ARRAY_H_

/*! @brief: Sorts an array of ints in increasing order.
 *  @param: array The array of ints to be sorted.
 *  @param: numElements The number of elements in the array.
 *  @pre: All elements from 0, ..., numElements are valid, i.e. array is packed
 *        to the left with no empty places.
 */
void InsertionSort(int array[], int num_elements);


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
                      int (*greater_than)(void *, void *));


#endif /* SNIPPET_INSERTION_SORT_ARRAY_H_ */
