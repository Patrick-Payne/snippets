#!/usr/bin/env python3
"""
File: shortest_path.py
Author: Patrick Payne
Date Created: Jan 20, 2014
Description: A repeat of the BFS algorithm for finding the shortest
    path between two nodes in an unweighted graph, but using networkx to make
    it possible to easily plot the results as well as generate input.
    The sample data file was taken from:
    http://www-cs-staff.stanford.edu/~knuth/contiguous-usa.dat
"""

from collections import deque


def get_shortest_path(graph, start, end):
    """
    Finds the shortest path from start to end using a breadth-first search.
    graph must be of type networkx.Graph.
    """
    # Make sure that the vertices input are valid.
    assert (start in graph) and (end in graph), "Invalid vertices"

    # Create the FIFO we will use to remember grayed vertices during the BFS.
    node_fifo = deque()
    node_fifo.append(start)

    # Create a dict to contain the Breadth-First tree produced by the search.
    # This is created by specifying the unique parent of each node in the tree
    # as a value in a dict. None is a sentinal value used for the parent of the
    # root node.
    tree = {start: None}

    # This is the main body of the breadth-first search.
    while len(node_fifo) > 0:
        current_node = node_fifo.popleft()

        # Add all newly discovered nodes adjacent to the current node.
        for node in graph[current_node]:
            if node not in tree:
                tree[node] = current_node
                node_fifo.append(node)

            # We short-circuit the search if we find the end vertex.
            if node == end:
                # Flush the queue; we have no need of further searching.
                node_fifo.clear()
                break

    # We have exited the loop; see if we have found the end vertex.
    if end in tree:
        path = []
        node = end
        while tree[node] is not None:
            path.append((tree[node], node))
            node = tree[node]

        return path
    else:
        # Start is not connected to end.
        return None

if __name__ == '__main__':
    import networkx as nx
    import matplotlib.pyplot as plt

    # Create an edge list from the file
    usa_edges = [tuple(line.split()) for line in open("usa_edges.dat")]

    # Get the node positions as well.
    pos = {}
    for line in open("state_locations.dat"):
        args = line.split()
        pos[args[0]] = [float(args[1]), float(args[2])]

    # Use this edge list to generate a networkx graph.
    usa_graph = nx.from_edgelist(usa_edges)

    # Now find the shortest path from California to New York.
    path = get_shortest_path(usa_graph, "WA", "FL")
    non_path = [(u,v) for (u,v) in usa_edges if 
                          (((u,v) not in path) and ((v,u) not in path))]

    # Draw ALL the edges.
    nx.draw_networkx_edges(usa_graph, pos, edgelist=path, width=6)
    nx.draw_networkx_edges(usa_graph, pos, edgelist=non_path,
                           alpha=0.5, edge_color='r')
    nx.draw_networkx_nodes(usa_graph, pos, node_size=500)
    nx.draw_networkx_labels(usa_graph, pos, font_size=10)


    plt.show()

