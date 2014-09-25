#!/usr/bin/env python3
import random
import unittest


def swap(in_list, index1, index2):
    '''Given a list in_list, swap elements at index1 and index2.'''
    temp = in_list[index1]
    in_list[index1] = in_list[index2]
    in_list[index2] = temp


def partition(in_list, start, end, pivot_index):
    '''Partition in_list[start:end+1] around the item at pivot_index, in place.

    Returns: The final index of the pivot.
    '''
    assert start <= pivot_index <= end

    # Stick the pivot at the end to make partitioning easier.
    pivot = in_list[pivot_index]
    swap(in_list, pivot_index, end)

    # Keep all smaller items to the left, larger items of partition_index.
    partition_index = start
    for index in range(start, end):
        if in_list[index] <= pivot:
            swap(in_list, partition_index, index)
            partition_index += 1

    # Put the pivot back at the partition where it belongs.
    swap(in_list, partition_index, end)
    return partition_index


def two_side_partition(in_list, start, end, pivot_index):
    '''Uses the two sided partition strategy from Programming Pearls. '''
    assert start <= pivot_index <= end

    # Stick the pivot at the end to make partitioning easier.
    pivot = in_list[pivot_index]
    swap(in_list, pivot_index, end)

    lower_index = start
    upper_index = end - 1
    while lower_index <= upper_index:
        # Loop invariant: in_list[start:lower_index] contains elements less
        # than pivot, in_list[upper_index + 1:end] contains elements greater
        # than pivot, and in between is unknown.
        while (in_list[lower_index] < pivot) and (lower_index < end - 1):
            lower_index += 1

        while (in_list[upper_index] >= pivot) and (upper_index >= start):
            upper_index -= 1

        if lower_index > upper_index:
            break

        # upper_index is at a smaller element, lower_index is at a bigger
        # element, so if we swap the two we can continue.
        swap(in_list, lower_index, upper_index)
        lower_index += 1
        upper_index -= 1

    # Put the pivot in the correct location.
    swap(in_list, lower_index, end)
    return lower_index


def recursive_quicksort1(in_list, start, end):
    if start >= end:
        return

    pivot_index = random.randint(start, end)
    partition_index = partition(in_list, start, end, pivot_index)

    # Now do the recursive step of sorting each partition.
    recursive_quicksort1(in_list, start, partition_index - 1)
    recursive_quicksort1(in_list, partition_index + 1, end)


def recursive_quicksort2(in_list, start, end):
    ''' This version uses the two-way partitioning scheme. '''
    if start >= end:
        return

    pivot_index = random.randint(start, end)
    partition_index = two_side_partition(in_list, start, end, pivot_index)

    # Now do the recursive step of sorting each partition.
    recursive_quicksort2(in_list, start, partition_index - 1)
    recursive_quicksort2(in_list, partition_index + 1, end)


def quicksort(in_list):
    recursive_quicksort1(in_list, 0, len(in_list) - 1)
    return


def debug_sort1(in_list):
    '''Returns the result of quicksorting a list.'''
    new_list = in_list[:]
    recursive_quicksort1(new_list, 0, len(new_list) - 1)
    return new_list


def debug_sort2(in_list):
    '''Returns the result of quicksorting a list.'''
    new_list = in_list[:]
    recursive_quicksort2(new_list, 0, len(new_list) - 1)
    return new_list


class TestQuickSort(unittest.TestCase):
    def setUp(self):
        self.algorithm = debug_sort2

    ''' Tests the recursive implementation of quicksort. '''
    def test_singleton(self):
        self.assertEqual([1], self.algorithm([1]))

    def test_doubleton(self):
        self.assertEqual([1, 2], self.algorithm([1, 2]))
        self.assertEqual([1, 2], self.algorithm([2, 1]))
        self.assertEqual([2, 2], self.algorithm([2, 2]))

    def test_tripleton(self):
        self.assertEqual([1, 2, 3], self.algorithm([1, 2, 3]))
        self.assertEqual([1, 2, 3], self.algorithm([1, 3, 2]))
        self.assertEqual([1, 2, 3], self.algorithm([2, 1, 3]))
        self.assertEqual([1, 2, 3], self.algorithm([2, 3, 1]))
        self.assertEqual([1, 2, 3], self.algorithm([3, 2, 1]))
        self.assertEqual([1, 2, 3], self.algorithm([3, 1, 2]))

    def test_large(self):
        self.assertEqual([1, 2, 3, 4], self.algorithm([4, 1, 3, 2]))
        self.assertEqual(list(range(0, 10)),
                         self.algorithm(list(range(9, -1, -1))))


if __name__ == '__main__':
    unittest.main()
