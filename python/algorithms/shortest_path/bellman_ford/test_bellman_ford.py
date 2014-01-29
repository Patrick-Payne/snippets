#!/usr/bin/env python3
"""
File: test_bellman_ford.py
Author: Patrick Payne
Date Created: Jan 26, 2014
Description: Tests the results of the Bellman-ford implementation in
    bellman_ford.py.
"""

import pdb
import unittest
import networkx as nx
from bellman_ford import get_shortest_path


class TestShortestPaths(unittest.TestCase):
    """ Tests the get_shortest_path() function from shortest_path.py."""

    def test_invalid_inputs(self):
        """ Test the case where the graph is empty. """
        # If the graph is empty, the vertices are invalid.
        graph = nx.DiGraph()
        with self.assertRaises(AssertionError):
            get_shortest_path(graph, "a", "b")

        # If we have a singleton, it is still invalid.
        graph.add_node("A")
        with self.assertRaises(AssertionError):
            get_shortest_path({"A": []}, "A", "B")

        # If we have a graph with multiple nodes, but the vertices are invalid.
        graph.add_node("B")
        with self.assertRaises(AssertionError):
            get_shortest_path({"A": [], "B": []}, "A", "Z")

    def test_k3(self):
        """ Test with an unweighted complete graph with 3 nodes. """
        k3 = nx.DiGraph({"A": ["B", "C"],
                         "B": ["A", "C"],
                         "C": ["A", "B"]})
        for start, end in k3.edges():
            k3[start][end]['weight'] = 1

        # The shortest path from a node to itself should be just that node.
        self.assertEqual(get_shortest_path(k3, "A", "A"), (0, ["A"]))
        self.assertEqual(get_shortest_path(k3, "B", "B"), (0, ["B"]))
        self.assertEqual(get_shortest_path(k3, "C", "C"), (0, ["C"]))

        # All nodes are connected to each other by a path of length 1.
        self.assertEqual(get_shortest_path(k3, "A", "B"), (1, ["A", "B"]))
        self.assertEqual(get_shortest_path(k3, "B", "A"), (1, ["B", "A"]))

        self.assertEqual(get_shortest_path(k3, "A", "C"), (1, ["A", "C"]))
        self.assertEqual(get_shortest_path(k3, "C", "A"), (1, ["C", "A"]))

        self.assertEqual(get_shortest_path(k3, "B", "C"), (1, ["B", "C"]))
        self.assertEqual(get_shortest_path(k3, "C", "B"), (1, ["C", "B"]))

    def test_medium_1(self):
        """ Test a basic weighted graph. """
        pass


if __name__ == '__main__':
    unittest.main(verbosity=3)
