'''
File: dijkstra.py
Author: Patrick Payne
Date Created: Oct 08, 2013
Description: Uses dijkstra's algorithm to find the shortest path between two
   nodes on a graph.
'''

import heapq


def shortest_path(graph, start, end):
    """
    Finds the shortest path between two nodes on a graph, specified as an
    adjacency dictionary, with the keys being nodes, and the values being
    lists of edges adjacent to the node. The edges are 2-tuples, with the first
    item being the length of the edge, and the second being the destination
    vertex. E.g.:
        test_graph = {"A": [(10, "B"), (20, "C")],
                      "B": [(10, "A"), (5, "C")],
                      "C": [(20, "A"), (5, "B")]}

    The path is returned along with the total length of the path, in the
    following form:
    (total_length, ["A", "B", ....])
    """
    # Tree will contain both the final path and some other paths in reverse.
    # Each value is a 2-tuple; the first item is the depth of the key, and the
    # second is the parent of the key.
    tree = {start: (0, None)}

    # next_edges is a min_heap used as a priority queue; the next item in it
    # will always be the node adjacent to the growing tree that adds the least
    # to the total depth of the branch.
    next_edges = []

    # Add all of the edges adjacent to the start to next_edges.
    for edge in graph[start]:
        heapq.heappush(next_edges, edge + (start, ))

    # Loop until we run out of edges or we find the end (see condition below).
    while len(next_edges) > 0:
        depth, child, parent = heapq.heappop(next_edges)

        # Ignore edges connecting to children nodes already in the tree.
        if child in tree:
            continue

        tree[child] = (depth, parent)

        # Add the edges from the new node to the list of possible edges.
        for length, new_child in graph[child]:
            if new_child not in tree:
                heapq.heappush(next_edges, (depth + length, new_child, child))

        # If we found the end, flush the next_edges queue and end the search.
        if child is end:
            next_edges = []
            break

    # Construct the forward path from start -> end from the tree.
    path = []
    node = end
    while node is not None:
        path.append(node)
        node = tree[node][1]

    path.reverse()

    total_depth = tree[end][0]
    return (total_depth, path)
