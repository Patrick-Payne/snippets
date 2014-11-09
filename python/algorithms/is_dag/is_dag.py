#!/usr/bin/env python3
"""
File: is_dag.py
Author: Patrick Payne
Date Created: Nov 08, 2014
Description: Implements the basic depth-first search approach to detecting
    cycles in directed graphs.
"""

import unittest


def is_dag(graph):
    '''Return True if the input directed graph is acyclic. The graph is
        represented as an adjacency list in the form of a "dict of lists",
        e.g. {"A": ["B", "C"], ...}
    '''

    # We maintain a set containing the fully explored nodes of the graph.
    explored_nodes = set()
    
    # We have to keep performing depth first searches at different roots until
    # all nodes in the graph have been explored.
    unexplored_nodes = set(graph.keys())
    while unexplored_nodes:
        root = unexplored_nodes.pop()
        is_tree_acyclic = recursive_is_dag(graph, explored_nodes, root)
        
        if not is_tree_acyclic:
            return False
        else:
            # This is not very efficient. We could do better by returning a
            # set of explored nodes in each call to recursive_is_dag().
            unexplored_nodes = set(graph.keys()) - explored_nodes

    # If we get here, we have explored all nodes, and saw no back edges.
    return True


def recursive_is_dag(graph, explored_nodes, root, exploring=None):
    '''Performs a single tree depth-first search for any back edges starting
        at node root.
    '''
    # If the node has no outgoing edges, then it is a DAG.
    if root not in graph:
        return True

    # exploring contains the nodes that are on the current path being explored.
    if exploring == None:
        exploring = set()
    
    exploring.add(root)

    for child in graph[root]:
        if child in explored_nodes:
            continue
        elif child in exploring:
            return False
        else:
            child_is_dag = recursive_is_dag(graph, explored_nodes,
                                            child, exploring)
            if not child_is_dag:
                return False

    explored_nodes.add(root)
    exploring.remove(root)

    return True


class TestIsDag(unittest.TestCase):
    '''Performs basic unit testing on the is_dag function.'''

    def test_empty_graph(self):
        self.assertTrue(is_dag({}))

    def test_singleton_graph(self):
        self.assertTrue(is_dag({"A": []}))
        self.assertFalse(is_dag({"A": ["A"]}))

    def test_doubleton_graph(self):
        self.assertTrue(is_dag({"A": ["B"]}))
        self.assertFalse(is_dag({"A": ["B"], "B": ["A"]}))
        self.assertFalse(is_dag({"A": ["B"], "B": ["B"]}))

    def test_tripleton_graph(self):
        self.assertTrue(is_dag({"A": ["B", "C"]}))
        self.assertTrue(is_dag({"A": ["B"], "B": ["C"]}))
        self.assertFalse(is_dag({"A": ["B"], "B": ["C"], "C": ["A"]}))
        self.assertFalse(is_dag({"A": ["B"], "B": ["A", "C"], "C": ["C"]})) 

    def test_disjoint(self):
        self.assertFalse(is_dag({"A": ["B", "C"], "D": ["E"], "E": ["D"]}))

if __name__ == '__main__':
    unittest.main()
