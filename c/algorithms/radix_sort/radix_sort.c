/******************************************************************************
 * File: radix_sort.c
 * Author: Patrick Payne
 * Date Created: Sat Oct  4 16:56:27 EDT 2014
 * Purpose:
 * Copyright Sat Oct  4 16:56:27 EDT 2014 by Patrick Payne.
 *****************************************************************************/
#include <string.h>
#include <stdlib.h>

#include "radix_sort.h"
#define MASK(width) ((1u << (width)) - 1)

void CountingSort(int *list, int size, int digit, int width) {
	int max_digit_value = (1 << width) - 1;

	// Create a list counting the number of keys with a certain value.
	int *count = calloc(sizeof(int), max_digit_value + 1);
	for (int i = 0; i < size; i++) {
		int digit_value = list[i] >> (digit * width);
		digit_value &= MASK(width);
		count[digit_value] += 1;
	}
		
  // Transform this into a list containing the number of keys LESS than  a
  // certain value.
	for (int i =1; i <= max_digit_value; i++) {
		count[i] += count[i - 1];
	}

	// Insert the items into a new list in the sorted order.
	int current_index = size - 1;
  int *old_list = calloc(sizeof(int), size);
  memcpy((void *) old_list, (void *) list, size * sizeof(int));

	while (current_index >= 0) {
		int digit_value = (old_list[current_index] >> (digit * width)) & MASK(width);
		list[count[digit_value] - 1] = old_list[current_index];
		count[digit_value]--;
		current_index--;
	}

	free(count);
  free(old_list);
}


void RadixSort(int *list, int size, int width) {
	int num_digits = (sizeof(int) * 8) / width;
	int *result_list = list;
	for (int i =0; i < num_digits; i++) {
		CountingSort(result_list, size, i, width);
	}
}
