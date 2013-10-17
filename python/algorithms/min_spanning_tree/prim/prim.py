'''
File: prim.py
Author: Patrick Payne
Date Created: Oct 08, 2013
Description: Uses Prim's algorithm to find the minimum spanning tree of a
    graph.
'''

import heapq

def min_spanning_tree(graph, root):
    """
    Returns the adjacency list of the minimum spanning tree of thew weighted
    graph, starting at root. The graph is specified in the following form:
    G = {"A": [(10, "B")], "B": [(10, "A")]}
    """
    # This dict will hold the adjacency list of the tree.
    tree = {}

    # This set holds the nodes currently contained in the tree.
    connected_nodes = {root}

    # We start a priority queue to hold the potential edges for the tree.
    next_edges = []

    # Push all nodes adjacent to the root onto the queue.
    for edge in graph[root]:
        heapq.heappush(next_edges, edge + (root,))

    # Loop until we have the spanning tree in variable tree.
    while (len(next_edges) > 0) and (len(tree) < len(graph)):
        length, child, parent = heapq.heappop(next_edges)

        # Break the loop if child is already in the tree.
        if child in connected_nodes:
            continue

        # Add child to the tree.
        if parent in tree:
            tree[parent].append((length, child))
        else:
            tree[parent] = [(length, child)]

        connected_nodes.add(child)

        # Now add any new edges starting from child into the queue of potential
        # next edges.
        for edge in graph[child]:
            if edge[1] not in connected_nodes:
                heapq.heappush(next_edges, edge + (child,))

    return tree
