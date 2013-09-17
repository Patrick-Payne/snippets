#!/usr/bin/env python3
'''
File: test_quicksort.py
Author: Patrick Payne
Date Created: Sep 15, 2013
Description: Unit tests for the quicksort algorithm.
'''
import unittest
from quicksort import quick_sort, in_place_quick_sort


class TestQuickSort(unittest.TestCase):
    """Tests the quicksort algorithm."""
    def test_empty_and_single_element(self):
        """Tests the trivial cases for empty and single element lists."""
        self.assertEqual(quick_sort([]), [])
        self.assertEqual(quick_sort([0]), [0])
        self.assertEqual(quick_sort(["Banana"]), ["Banana"])

    def test_two_elements(self):
        """Tests cases where the list has only 2 elements."""
        self.assertEqual(quick_sort([0, 0]), [0, 0])
        self.assertEqual(quick_sort([0, 1]), [0, 1])
        self.assertEqual(quick_sort([1, 0]), [0, 1])
        self.assertEqual(quick_sort([100, -100]), [-100, 100])

    def test_multiple_elements(self):
        """Tests cases where we have more than 2 elements."""
        # Even length lists
        self.assertEqual(quick_sort([-100, 100, -5, 4]), [-100, -5, 4, 100])
        self.assertEqual(quick_sort([100, 4, -5, -100]), [-100, -5, 4, 100])

        self.assertEqual(quick_sort([1, 2, 3, 4, 5, 6]), [1, 2, 3, 4, 5, 6])
        self.assertEqual(quick_sort([6, 5, 4, 3, 2, 1]), [1, 2, 3, 4, 5, 6])
        self.assertEqual(quick_sort([1, 5, 4, 6, 2, 3]), [1, 2, 3, 4, 5, 6])

        test_list = [1, 5, 2, 6, 3, 7, 4, 8, 5, 9]
        self.assertEqual(quick_sort(test_list), [1, 2, 3, 4, 5, 5, 6, 7, 8, 9])

        test_list = test_list[::-1]  # Reverse the list order.
        self.assertEqual(quick_sort(test_list), [1, 2, 3, 4, 5, 5, 6, 7, 8, 9])

        # Odd length list
        self.assertEqual(quick_sort([0, 10, 11, 15, 25]), [0, 10, 11, 15, 25])
        self.assertEqual(quick_sort([15, 10, 25, 0, 11]), [0, 10, 11, 15, 25])


class TestInPlaceQuickSort(unittest.TestCase):
    """Tests the in-place version of the quicksort algorithm."""
    def test_two_elements(self):
        """Tests cases where the list has only 2 elements."""
        test_list = [0, 0]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [0, 0])

        test_list = [0, 1]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [0, 1])

        test_list = [1, 0]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [0, 1])

    def test_multiple_elements(self):
        """Tests cases where we have more than 2 elements."""
        # Even length lists
        test_list = [-100, 100, -5, 4]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [-100, -5, 4, 100])

        test_list = [1, 2, 3, 4, 5, 6]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [1, 2, 3, 4, 5, 6])

        test_list = [6, 5, 4, 3, 2, 1]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [1, 2, 3, 4, 5, 6])

        test_list = [1, 5, 2, 6, 3, 7, 4, 8, 5, 9]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [1, 2, 3, 4, 5, 5, 6, 7, 8, 9])

        test_list = [9, 8, 7, 6, 5, 4, 3, 2, 1]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [1, 2, 3, 4, 5, 6, 7, 8, 9])

        # Odd length list
        test_list = [9, 8, 7, 6, 5, 4, 3, 2]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [2, 3, 4, 5, 6, 7, 8, 9])

        test_list = [15, 10, 25, 0, 11]
        in_place_quick_sort(test_list)
        self.assertEqual(test_list, [0, 10, 11, 15, 25])


if __name__ == '__main__':
    unittest.main(verbosity=3)
