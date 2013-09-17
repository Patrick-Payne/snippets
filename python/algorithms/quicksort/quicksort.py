#!/usr/bin/env python3
'''
File: quicksort.py
Author: Patrick Payne
Date Created: Sep 15, 2013
Description: A basic recursive quicksort algorithm for python lists.
'''


def quick_sort(in_list):
    """
    Sorts a list recursively in increasing order using the quicksort algorithm.
    """
    # Check for the base case.
    if len(in_list) <= 1:
        return in_list

    # Choose a pivot.
    pivot_index = len(in_list) // 2
    pivot = in_list[pivot_index]

    # Partition the rest of the elements.
    smaller = []
    bigger = []

    for element in in_list[:pivot_index] + in_list[pivot_index + 1:]:
        if element < pivot:
            smaller.append(element)
        else:
            bigger.append(element)

    # Concatenate the sorted sublists.
    return quick_sort(smaller) + [pivot] + quick_sort(bigger)
