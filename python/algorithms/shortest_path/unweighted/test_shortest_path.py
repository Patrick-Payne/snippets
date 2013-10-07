#!/usr/bin/env python3
'''
File: test_shortest_path.py
Author: Patrick Payne
Date Created: Oct 07, 2013
Description: tests the get_shortest_path() function from shortest_path.py
'''

import unittest
from shortest_path import get_shortest_path


class TestGetShortestPath(unittest.TestCase):
    """ Tests the get_shortest_path() function from shortest_path.py."""

    def test_invalid_inputs(self):
        """ Test the case where the graph is empty. """
        # If the graph is empty, the vertices are invalid.
        with self.assertRaises(AssertionError):
            get_shortest_path({}, "a", "b")

        # If we have a singleton, it is still invalid.
        with self.assertRaises(AssertionError):
            get_shortest_path({"A": []}, "A", "B")

        # If we have a graph with multiple nodes, but the vertices are invalid.
        with self.assertRaises(AssertionError):
            get_shortest_path({"A": [], "B": []}, "A", "Z")

    def test_k3(self):
        """ Tests the function for the complete graph with 3 vertices. """
        k3 = {"A": ["B", "C"], "B": ["A", "C"], "C": ["A", "B"]}

        # The shortest path from a node to itself should be just that node.
        self.assertEqual(get_shortest_path(k3, "A", "A"), ["A"])
        self.assertEqual(get_shortest_path(k3, "B", "B"), ["B"])
        self.assertEqual(get_shortest_path(k3, "C", "C"), ["C"])

        # All nodes are connected to each other by a path of length 0.
        self.assertEqual(get_shortest_path(k3, "A", "B"), ["A", "B"])
        self.assertEqual(get_shortest_path(k3, "B", "A"), ["B", "A"])

        self.assertEqual(get_shortest_path(k3, "A", "C"), ["A", "C"])
        self.assertEqual(get_shortest_path(k3, "C", "A"), ["C", "A"])

        self.assertEqual(get_shortest_path(k3, "B", "C"), ["B", "C"])
        self.assertEqual(get_shortest_path(k3, "C", "B"), ["C", "B"])

    def test_medium_1(self):
        """ Tests the function with a slightly larger graph from wikipedia. """
        # This graph is from: http://en.wikipedia.org/wiki/File:6n-graf.svg
        graph = {1: [5, 2],
                 2: [1, 3, 5],
                 3: [2, 4],
                 4: [3, 5, 6],
                 5: [1, 2, 4],
                 6: [4]}

        # Test some paths of length 0.
        self.assertEqual(get_shortest_path(graph, 1, 1), [1])
        self.assertEqual(get_shortest_path(graph, 5, 5), [5])

        # Test some paths of length 1.
        self.assertEqual(get_shortest_path(graph, 1, 2), [1, 2])
        self.assertEqual(get_shortest_path(graph, 5, 1), [5, 1])
        self.assertEqual(get_shortest_path(graph, 6, 4), [6, 4])

        # Test some paths of length 2.
        self.assertEqual(get_shortest_path(graph, 1, 4), [1, 5, 4])
        self.assertEqual(get_shortest_path(graph, 3, 6), [3, 4, 6])
        self.assertIn(get_shortest_path(graph, 5, 3), [[5, 2, 3], [5, 4, 3]])
        self.assertIn(get_shortest_path(graph, 4, 2), [[4, 5, 2], [4, 3, 2]])

        # Test some paths of length 3.
        self.assertEqual(get_shortest_path(graph, 1, 6), [1, 5, 4, 6])
        self.assertEqual(get_shortest_path(graph, 6, 1), [6, 4, 5, 1])

        self.assertIn(get_shortest_path(graph, 6, 2),
                      [[6, 4, 3, 2], [6, 4, 5, 2]])


if __name__ == '__main__':
    unittest.main(verbosity=3)
