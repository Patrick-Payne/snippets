#!/usr/bin/env python3
import random
import unittest


def insertion_sort(in_list):
    '''Implements a basic insertion sort algorithm. '''
    new_list = in_list[:]
    length = len(new_list)
	
    for index in range(length):
            # loop invariant: new_list[0:index] is sorted.
            temp = new_list[index]

            # shift all of the larger elements in new_list[0:index] to the
            # right to make space.
            new_location = index
            while (new_location > 0) and (new_list[new_location-1] > temp):
                new_list[new_location] = new_list[new_location - 1]
                new_location -= 1

            # Insert the new element in its correct location.
            new_list[new_location] = temp

    return new_list

class TestSort(unittest.TestCase):
    def setUp(self):
        self.algorithm = insertion_sort

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
