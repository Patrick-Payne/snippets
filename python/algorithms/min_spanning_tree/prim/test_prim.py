#!/usr/bin/env python3
'''
File: test_prim.py
Author: Patrick Payne
Date Created: Oct 08, 2013
Description: Tests the prim algorithm implemented in prim.py.
'''

import unittest
import pdb
from prim import min_spanning_tree

class TestMinSpanningTree(unittest.TestCase):
    """ A collection of test cases for the min_spanning_tree() function. """
    
    def test_binary_case(self):
        """ Tests case where there are only 2 vertices. """
        test_graph = {"A": [(10, "B")], "B": [(10, "A")]}
        expected_tree = {"A": [(10, "B")]}
        self.assertEqual(expected_tree, min_spanning_tree(test_graph, "A"))
        expected_tree = {"B": [(10, "A")]}
        self.assertEqual(expected_tree, min_spanning_tree(test_graph, "B"))

    def test_ternary_case(self):
        """ Tests a triangle. """
        test_graph = {"A": [(10, "B"), (20, "C")],
                      "B": [(10, "A"), (5, "C")],
                      "C": [(20, "A"), (5, "B")]}
        expected_tree = {"A": [(10, "B")],
                         "B": [(5, "C")]}
        self.assertEqual(expected_tree, min_spanning_tree(test_graph, "A"))
        expected_tree = {"B": [(5, "C"), (10, "A")]}
        self.assertEqual(expected_tree, min_spanning_tree(test_graph, "B"))

    def test_five_nodes(self):
        """ Tests the algorithm on a graph with 5 nodes. """
        test_graph = {"A": [(10, "B"), (2, "C")],
                      "B": [(10, "A"), (5, "D")],
                      "C": [(2, "A"), (20, "D")],
                      "D": [(5, "B"), (20, "C"), (1, "E")],
                      "E": [(1, "D")]}

        expected_tree = {"A": [(2, "C"), (10, "B")],
                         "B": [(5, "D")],
                         "D": [(1, "E")]}
        self.assertEqual(expected_tree, min_spanning_tree(test_graph, "A"))

        expected_tree = {"A": [(2, "C")],
                         "B": [(10, "A")],
                         "D": [(1, "E"), (5, "B")]}
        self.assertEqual(expected_tree, min_spanning_tree(test_graph, "D"))



if __name__ == '__main__':
    unittest.main(verbosity=2)
