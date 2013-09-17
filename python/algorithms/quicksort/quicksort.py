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
    This version of quicksort is NOT in place, and is space inefficient. See
    in_place_quick_sort().
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


def in_place_quick_sort(in_list, left=0, right=None):
    """
    Sorts the subarray located at in_list[left:right + 1] in increasing order,
    in place. If no left and right arguments are provided, sort the whole list.
    """
    # Check whether right argument was omitted.
    if right is None:
        right = len(in_list) - 1

    # Check for the base case.
    if right - left <= 0:
        return

    # Select a pivot. We choose one roughly in the middle of the subarray.
    pivot_index = left + (right - left) // 2

    # Partition the array.
    partition_index = partition(in_list, left, right, pivot_index)

    # Sort the smaller and bigger subarrays.
    in_place_quick_sort(in_list, left, partition_index - 1)
    in_place_quick_sort(in_list, partition_index + 1, right)


def partition(in_list, left, right, pivot_index):
    """
    Partitions the elements in the subarray in_list[left:right+1] such that
    elements less than the pivot value at in_list[pivot_index] are to the left
    if it, and all greater or equal elements are placed to it's right. The
    final index of the pivot is returned.
    """
    # Copy the pivot to the end of the list.
    pivot = in_list[pivot_index]
    swap(in_list, pivot_index, right)

    # Iterate over all oter elements, putting smaller elements to the left.
    partition_index = left
    for index in range(left, right):
        if in_list[index] < pivot:
            swap(in_list, partition_index, index)
            partition_index += 1

    # Put the pivot value back into its place.
    swap(in_list, partition_index, right)
    return partition_index


def swap(in_list, index1, index2):
    """ Swaps the values stored at index1 and index2 of the list in_list."""
    temp = in_list[index1]
    in_list[index1] = in_list[index2]
    in_list[index2] = temp
