/******************************************************************************
 * File: radix_sort.h
 * Author: Patrick Payne
 * Date Created: Sat Oct  4 16:56:27 EDT 2014
 * Purpose:
 * Copyright Sat Oct  4 16:56:27 EDT 2014 by Patrick Payne.
 *****************************************************************************/
#ifndef SNIPPET_C_RADIX_SORT_H_
#define SNIPPET_C_RADIX_SORT_H_

/*! A simple counting sort algorithm for digits of abitrary width.
 * @param list The list to sort.
 * @param size The number of elements in the list.
 * @param digit The digit to sort based on.
 * @param width The "size" of the digit, i.e. each digit is width bits wide.
 */
void CountingSort(int *list, int size, int digit, int width);


/* Sorts a list of integers using radix sort using digits of width bits. */
void RadixSort(int *list, int size, int width);

#endif /* SNIPPET_C_RADIX_SORT_H_ */
