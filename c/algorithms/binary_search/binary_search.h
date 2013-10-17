/******************************************************************************
 * File: binary_search.h
 * Author: Patrick Payne
 * Date Created: Oct 16, 2013
 * Purpose: Implements a basic iterative binary search algorithm.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

#ifndef SNIPPET_C_BINARY_SEARCH_H_
#define SNIPPET_C_BINARY_SEARCH_H_

#define INVALID_INDEX (-1)

/*! @brief Searches for an integer within an array of integers.
 *  @param list The pointer to the beginning of the integer array.
 *  @param size The number of elements within the list.
 *  @param item The integer to search for.
 *  @return The index of the item in the list if it is found, otherwise return
 *      INVALID_INDEX.
 */
int BinarySearch(int *list, int size, int item);

#endif /* SNIPPET_C_BINARY_SEARCH_H_ */
