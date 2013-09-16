#!/usr/bin/env python3
'''
File: mergesort.py
Author: Patrick Payne
Date Created: Sep 15, 2013
Description: A basic recursive mergesort algorithm for python lists.
'''


def merge_sort(in_list, key=None):
    """
    Sorts a list recursively in increasing order using the mergesort algorithm.
    key, if provided, is a function that generates a key from the list objects
    for the purpose of comparison.
    """
    if len(in_list) <= 1:
        # An empty list or a list with one element is already sorted.
        return in_list

    else:
        # Divide the input list into two sublists of roughly equal length.
        middle = len(in_list) // 2
        left = in_list[:middle]
        right = in_list[middle:]

        # Sort the two sublists.
        left = merge_sort(left, key)
        right = merge_sort(right, key)

        # Now merge the two lists and return the result.
        return merge(left, right, key)


def merge(left, right, key=None):
    """
    Given two lists sorted in increasing order, merges the two lists into
    one larger list in increasing order. Key, if provided, is the function
    called on the list elements to produce the keys which are compared.
    """
    # We track indices instead of popping elements off each sublist, since
    # accessing is O(1), but deletion is O(n) for python lists.
    left_index = 0
    right_index = 0
    merged_list = []

    while (left_index < len(left)) or (right_index < len(right)):
        if (left_index < len(left)) and (right_index < len(right)):
            # Create the keys for comparison. Items are compared directly
            # if no key function is provided.
            left_key = left[left_index]
            right_key = right[right_index]
            if key is not None:
                left_key = key(left_key)
                right_key = key(right_key)

            # If the left and right elements are equal, prefer the left one.
            if left_key <= right_key:
                merged_list.append(left[left_index])
                left_index += 1
            else:
                merged_list.append(right[right_index])
                right_index += 1

        # If only one list has elements remaining, append them all in their
        # current order.
        elif left_index < len(left):
            merged_list += left[left_index:]
            left_index = len(left)
        else:
            merged_list += right[right_index:]
            right_index = len(right)

    return merged_list
