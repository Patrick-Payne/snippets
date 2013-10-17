#!/usr/bin/env python3
'''
File: test_dijkstra.py
Author: Patrick Payne
Date Created: Oct 08, 2013
Description: Tests the dijkstra algorithm implemented in prim.py.
'''

import unittest
import pdb
from dijkstra import shortest_path

class TestMinSpanningTree(unittest.TestCase):
    """ A collection of test cases for the min_spanning_tree() function. """
    
    def test_binary_case(self):
        """ Tests case where there are only 2 vertices. """
        test_graph = {"A": [(10, "B")], "B": [(10, "A")]}

        self.assertEqual(shortest_path(test_graph, "A", "B"), (10, ["A", "B"]))
        self.assertEqual(shortest_path(test_graph, "B", "A"), (10, ["B", "A"]))

    def test_ternary_case(self):
        """ Tests a triangle. """
        test_graph = {"A": [(10, "B"), (20, "C")],
                      "B": [(10, "A"), (5, "C")],
                      "C": [(20, "A"), (5, "B")]}

        expected_path = (10, ["A", "B"])
        self.assertEqual(shortest_path(test_graph, "A", "B"), expected_path)

        expected_path = (5, ["B", "C"])
        self.assertEqual(shortest_path(test_graph, "B", "C"), expected_path)

        expected_path = (15, ["A", "B", "C"])
        self.assertEqual(shortest_path(test_graph, "A", "C"), expected_path)

    def test_five_nodes(self):
        """ Tests the algorithm on a graph with 5 nodes. """
        test_graph = {"A": [(10, "B"), (2, "C")],
                      "B": [(10, "A"), (5, "D")],
                      "C": [(2, "A"), (20, "D")],
                      "D": [(5, "B"), (20, "C"), (1, "E")],
                      "E": [(1, "D")]}

        expected_path = (12, ["B", "A", "C"])
        self.assertEqual(shortest_path(test_graph, "B", "C"), expected_path)

        expected_path = (16, ["A", "B", "D", "E"])
        self.assertEqual(shortest_path(test_graph, "A", "E"), expected_path)

        expected_path = (18, ["C", "A", "B", "D", "E"])
        self.assertEqual(shortest_path(test_graph, "C", "E"), expected_path)


    def test_large_graph(self):
        """
        Tests the algorithm on a larger graph from this source:
        http://www.cs.princeton.edu/courses/archive/fall11/cos226/
                                        exercises/43MinimumSpanningTrees.html
        """
        # Finish this later.
        #test_graph = {"A": [(22, "B"), (9, "C"), (12, "D")],
        #              "B": [(22, "A"), (35, "C"), (


if __name__ == '__main__':
    unittest.main(verbosity=2)
