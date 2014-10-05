/******************************************************************************
 * File: mergesort.h
 * Author: Patrick Payne
 * Date Created: Sat Oct  4 21:10:23 EDT 2014
 * Purpose:
 * Copyright Sat Oct  4 21:10:23 EDT 2014 by Patrick Payne.
 *****************************************************************************/
#ifndef SNIPPET_C_MERGESORT_H_
#define SNIPPET_C_MERGESORT_H_

#include<cstdlib>
#include<cstring>

template <class T>
void InsertionSort(T *list, int size) {
	for (int i = 1; i < size; i++) {
		int temp = list[i];
		// Shift all larger elements to the right.
    int j = i;
		while(j > 0) {
			if (list[j - 1] <= temp) {
				break;
			}
			list[j] = list[j - 1];
      j--;
		}

		list[j] = temp;
	}
}


template <class T>
void MergeSort(T *in_list, int size, int threshold) {
	// Check for base case.
	if (size <= 1) {
    return;
	} else if (size < threshold) {
		InsertionSort(in_list, size);
		return;
	}

	//Divide into two lists.
	int middle_index = (size - 1) / 2;
	int lower_size = middle_index + 1;
	int upper_size = size - middle_index - 1;

	T *lower = (T *) calloc(sizeof(T), lower_size);
	T *upper = (T *) calloc(sizeof(T), upper_size);
	memcpy((void *) lower, (void *) in_list, sizeof(T) * lower_size);
	memcpy((void *) upper, (void *) &(in_list[middle_index + 1]), sizeof(T) * upper_size);

	// Perform recursive calls.
	MergeSort(lower, lower_size, threshold);
	MergeSort(upper, upper_size, threshold);

	// Now do the merging:
	int main_index = 0;
	int lower_index = 0;
	int upper_index = 0;
	while ((lower_index < lower_size) || (upper_index < upper_size)) {
		if (lower_index == lower_size) {
			in_list[main_index] = upper[upper_index];
			upper_index++;
		} else if (upper_index == upper_size) {
			in_list[main_index] = lower[lower_index];
			lower_index++;
		} else if (lower[lower_index] < upper[upper_index]) {
      in_list[main_index] = lower[lower_index];
      lower_index++;
    } else {
      in_list[main_index] = upper[upper_index];
      upper_index++;
    }
    main_index++;
	}

	// Free the memory for the two sublists.
	free(lower);
	free(upper);
}

#endif /* SNIPPET_C_MERGESORT_H_ */
