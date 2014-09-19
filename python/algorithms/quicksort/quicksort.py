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


def recursive_quicksort(in_list, start, end):
    if start >= end:
        return

    pivot_index = random.randint(start, end)
    partition_index = partition(in_list, start, end, pivot_index)

    # Now do the recursive step of sorting each partition.
    recursive_quicksort(in_list, start, partition_index - 1)
    recursive_quicksort(in_list, partition_index + 1, end)


def quicksort(in_list):
    recursive_quicksort(in_list, 0, len(in_list) - 1)
    return


def debug_sort(in_list):
    '''Returns the result of quicksorting a list.'''
    new_list = in_list[:]
    quicksort(new_list)
    return new_list


class TestQuickSort(unittest.TestCase):
    ''' Tests the recursive implementation of quicksort. '''
    def test_singleton(self):
        self.assertEqual([1], debug_sort([1]))

    def test_doubleton(self):
        self.assertEqual([1, 2], debug_sort([1, 2]))
        self.assertEqual([1, 2], debug_sort([2, 1]))
        self.assertEqual([2, 2], debug_sort([2, 2]))

    def test_tripleton(self):
        self.assertEqual([1, 2, 3], debug_sort([1, 2, 3]))
        self.assertEqual([1, 2, 3], debug_sort([1, 3, 2]))
        self.assertEqual([1, 2, 3], debug_sort([2, 1, 3]))
        self.assertEqual([1, 2, 3], debug_sort([2, 3, 1]))
        self.assertEqual([1, 2, 3], debug_sort([3, 2, 1]))
        self.assertEqual([1, 2, 3], debug_sort([3, 1, 2]))

    def test_large(self):
        self.assertEqual([1, 2, 3, 4], debug_sort([4, 1, 3, 2]))
        self.assertEqual(list(range(0, 10)),
                         debug_sort(list(range(9, -1, -1))))


if __name__ == '__main__':
    unittest.main()
