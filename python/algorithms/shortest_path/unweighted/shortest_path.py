'''
File: shortest_path.py
Author: Patrick Payne
Date Created: Oct 07, 2013
Description: Calculates the shortest path from a start node to an end node for
   an unweighted graph specified by an adjacency list.
'''

from collections import deque


def get_shortest_path(graph, start, end):
    """
    Finds the shortest path from start to end using a breadth-first search.
    graph must be represented as an adjacency list. The adjacency list is
    a dictionary keyed by vertex, whose values are lists representing adjacent
    vertices.

    graph = {"A":["B", "C"], "B": ["A", "C"], "C": ["A", "B"]}
    """
    # Make sure that the vertices input are valid.
    assert (start in graph) and (end in graph), "Invalid vertices"

    # Create the FIFO we will use to remember grayed vertices during the BFS.
    node_fifo = deque()
    node_fifo.append(start)

    # Create a set that contains all nodes that have been discovered.
    found_nodes = {start}

    # Create a dict to contain the Breadth-First tree produced by the search.
    # This is created by specifying the unique parent of each node in the tree
    # as a value in a dict. None is a sentinal value used for the parent of the
    # root node.
    parent = {start: None}

    # This is the main body of the breadth-first search.
    while len(node_fifo) > 0:
        current_node = node_fifo.popleft()

        # Add all newly discovered nodes adjacent to the current node.
        for node in graph[current_node]:
            if node not in found_nodes:
                found_nodes.add(node)
                parent[node] = current_node
                node_fifo.append(node)

            # We short-circuit the search if we find the end vertex.
            if node == end:
                # Flush the queue; we have no need of further searching.
                node_fifo.clear()
                break

    # We have exited the loop; see if we have found the end vertex.
    if end in found_nodes:
        path = []
        node = end
        while node is not None:
            path.append(node)
            node = parent[node]

        # The current path is from end to start, so reverse it.
        path.reverse()
        return path
    else:
        # Start is not connected to end.
        return None
