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


def quickselect(in_list, order):
    """Return the order-th order statistic of in_list.
    Note: This function modifies in_list.
    """
    assert 1 <= order <= len(in_list)

    begin = 0
    end = len(in_list) - 1

    while begin <= end:
        pivot_index = random.randint(begin, end)
        partition_index = partition(in_list, begin, end, pivot_index)

        if partition_index > order - 1:
            # The number we want is smaller than the pivot.
            end = partition_index - 1

        elif partition_index < order - 1:
            # The number we want is larger than the pivot.
            start = partition_index + 1

        else:
            # partition_index == order -1, meaning we found the number we want.
            return in_list[partition_index]


class TestQuickSort(unittest.TestCase):
    def test_singleton(self):
        self.assertEqual(1, quickselect([1], 1))

    def test_doubleton(self):
        self.assertEqual(1, quickselect([1, 2], 1))
        self.assertEqual(2, quickselect([1, 2], 2))

    def test_tripleton(self):
        self.assertEqual(-100.5, quickselect([2, -100.5, 12], 1))
        self.assertEqual(2, quickselect([2, -100.5, 12], 2))
        self.assertEqual(12, quickselect([2, -100.5, 12], 3))

    def test_large_list(self):
        for index in range(1, 100):
            self.assertEqual(index, quickselect(list(range(99, 0, -1)), index))

if __name__ == '__main__':
    unittest.main()
