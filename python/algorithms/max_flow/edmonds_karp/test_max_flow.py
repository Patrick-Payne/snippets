#!/usr/bin/env python3
"""
File: test_max_flow.py
Author: Patrick Payne
Date Created: Feb 21, 2014
Description: Tests the functions in max_flow.py.
"""

import pdb
import unittest
import networkx as nx
import matplotlib.pyplot as plt
from max_flow import *


class TestAntiparallel(unittest.TestCase):
    """Test the functions used to remove and restore antiparallel edges. """

    def test_no_antiparallel(self):
        """Test the case where there are no antiparallel edges to remove. """
        graph = nx.DiGraph({"A": ["B"],
                             "B": ["C"],
                             "C": ["D"]})

        fake_set = remove_antiparallel(graph)
        self.assertEqual(len(fake_set), 0)
        self.assertSetEqual(set(graph.edges()),
                            set([("A", "B"), ("B", "C"), ("C", "D")]))


    def test_k3(self):
        """Test on the degree 3 complete graph. """
        k3 = nx.DiGraph({"A": ["B", "C"],
                         "B": ["A", "C"],
                         "C": ["A", "B"]})
        for start, end in k3.edges():
            k3[start][end]['capacity'] = 1

        fake_set = remove_antiparallel(k3)
        self.assertEqual(len(fake_set), 3)
        self.assertEqual(len(k3), 6)
        self.assertEqual(len(k3.edges()), 9)
        for u, v in k3.edges_iter():
            self.assertTrue((v, u) not in k3)

        restore_antiparallel(k3, fake_set)

class TestResidualFlow(unittest.TestCase):
    """Test the residual_flow() function."""

    def setUp(self):
        self.k3 = nx.DiGraph({"A": ["B", "C"],
                              "B": ["D"],
                              "C": ["D"],
                              "D": []})
        self.match_fun = lambda x, y: (x['capacity'] == y['capacity'])
        
    def test_no_capacity_used(self):
        """Test case where flow uses no capacity."""
        flow = nx.create_empty_copy(self.k3)
        for start, end in self.k3.edges():
            self.k3[start][end]['capacity'] = 2

        self.assertTrue(nx.is_isomorphic(self.k3, 
                                         residual_flow(self.k3, flow),
                                         edge_match=self.match_fun))
        
    def test_all_capacity_used(self):
        """Test case where all of the capacity is used."""
        flow = self.k3.copy()
        for start, end in self.k3.edges():
            self.k3[start][end]['capacity'] = 2
            flow[start][end]['capacity'] = 2

        self.assertTrue(nx.is_isomorphic(self.k3.reverse(), 
                                         residual_flow(self.k3, flow),
                                         edge_match=self.match_fun))


    def test_some_capacity_used(self):
        """Test case where half of the capacity is used on each edge."""
        flow = self.k3.copy()
        for start, end in self.k3.edges():
            self.k3[start][end]['capacity'] = 2
            flow[start][end]['capacity'] = 1

        expected = nx.DiGraph()
        expected.add_edges_from(flow.edges(data=True))
        expected.add_edges_from(flow.reverse().edges(data=True))

        self.assertTrue(nx.is_isomorphic(expected, 
                                         residual_flow(self.k3, flow),
                                         edge_match=self.match_fun))


if __name__ == '__main__':
    unittest.main(verbosity=3)
