/******************************************************************************
 * File: quicksort.h
 * Author: Patrick Payne
 * Date Created: Nov 03, 2013
 * Purpose: Declares a basic in-place quicksort algorithm.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

#ifndef SNIPPET_C_QUICK_SORT_H_
#define SNIPPET_C_QUICK_SORT_H_

/*! @brief Sorts an array of integers using an in-place quicksort.
 *  @param list A pointer to the first item in the array.
 *  @param left The first valid index in the array.
 *  @param right The last valid index in the array.
 */
void QuickSort(int *list, int left, int right);

#endif /* SNIPPET_C_QUICK_SORT_H_ */
