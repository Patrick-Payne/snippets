#!/usr/bin/env python3
'''
File: test_mergesort.py
Author: Patrick Payne
Date Created: Sep 15, 2013
Description: Unit tests for the mergesort algorithm.
'''
import unittest
from mergesort import merge_sort, merge


class TestMerge(unittest.TestCase):
    """
    Tests the merge function, which is used for merging two sublists sorted
    in increasing order into a bigger list also sorted in increasing order.
    """
    def test_both_lists_empty(self):
        """ Tests the case where both lists are empty."""
        self.assertEqual(merge([], []), [])

    def test_one_list_empty(self):
        """ Tests the case where one of the lists is empty."""
        self.assertEqual(merge([], [1]), [1])
        self.assertEqual(merge([2], []), [2])

    def test_singles(self):
        """ Tests the case where both lists have a single element."""
        self.assertEqual(merge([1], [1]), [1, 1])
        self.assertEqual(merge([1], [2]), [1, 2])
        self.assertEqual(merge([2], [1]), [1, 2])
        self.assertEqual(merge([-100], [1]), [-100, 1])
        self.assertEqual(merge([100], [1]), [1, 100])

    def test_both_multiple(self):
        """ Tests the case where both lists have multiple elements."""
        self.assertEqual(merge([1, 2], [3, 4]), [1, 2, 3, 4])
        self.assertEqual(merge([1, 4], [2, 3]), [1, 2, 3, 4])
        self.assertEqual(merge([-100, 1], [-1, 2]), [-100, -1, 1, 2])

        self.assertEqual(merge([1, 3, 5], [2, 4]), [1, 2, 3, 4, 5])

        self.assertEqual(merge([1, 2, 3], [1, 2, 3]), [1, 1, 2, 2, 3, 3])
        self.assertEqual(merge([1, 2, 3], [4, 5, 6]), [1, 2, 3, 4, 5, 6])
        self.assertEqual(merge([1, 3, 5], [2, 4, 6]), [1, 2, 3, 4, 5, 6])


class TestMergeSort(unittest.TestCase):
    """Tests the mergesort algorithm."""
    def test_empty_and_single_element(self):
        """Tests the trivial cases for empty and single element lists."""
        self.assertEqual(merge_sort([]), [])
        self.assertEqual(merge_sort([0]), [0])
        self.assertEqual(merge_sort(["Banana"]), ["Banana"])

    def test_two_elements(self):
        """Tests cases where the list has only 2 elements."""
        self.assertEqual(merge_sort([0, 0]), [0, 0])
        self.assertEqual(merge_sort([0, 1]), [0, 1])
        self.assertEqual(merge_sort([1, 0]), [0, 1])
        self.assertEqual(merge_sort([100, -100]), [-100, 100])

    def test_multiple_elements(self):
        """Tests cases where we have more than 2 elements."""
        # Even length lists
        self.assertEqual(merge_sort([-100, 100, -5, 4]), [-100, -5, 4, 100])
        self.assertEqual(merge_sort([100, 4, -5, -100]), [-100, -5, 4, 100])

        self.assertEqual(merge_sort([1, 2, 3, 4, 5, 6]), [1, 2, 3, 4, 5, 6])
        self.assertEqual(merge_sort([6, 5, 4, 3, 2, 1]), [1, 2, 3, 4, 5, 6])
        self.assertEqual(merge_sort([1, 5, 4, 6, 2, 3]), [1, 2, 3, 4, 5, 6])

        test_list = [1, 5, 2, 6, 3, 7, 4, 8, 5, 9]
        self.assertEqual(merge_sort(test_list), [1, 2, 3, 4, 5, 5, 6, 7, 8, 9])

        # Odd length list
        self.assertEqual(merge_sort([0, 10, 11, 15, 25]), [0, 10, 11, 15, 25])
        self.assertEqual(merge_sort([15, 10, 25, 0, 11]), [0, 10, 11, 15, 25])


if __name__ == '__main__':
    unittest.main(verbosity=3)
