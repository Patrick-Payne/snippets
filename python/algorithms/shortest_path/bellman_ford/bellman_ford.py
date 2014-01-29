"""
File: bellman_ford.py
Author: Patrick Payne
Date Created: Jan 26, 2014
Description: Implements the Bellman-Ford algorithm for finding the shortest
   paths between any two edges.
"""


class NegativeCycleError(Exception):
    """Raised if finding the shortest path in a graph with a negative cycle."""
    pass


def get_shortest_path(graph, start, end):
    """ Return the shortest path between two nodes on a graph.

    Uses the Bellman-Ford algorithm.

    Parameters:
    graph -- A NetworkX DiGraph.
    start -- The starting node.
    end -- The destination node.

    Returns: (dist, path)
    dist -- The total weight of the shortest path, None if no path exists.
    path -- An ordered list of the nodes in the path, None if no path exists.
    """
    # Check the validity of the graph and endpoints.
    assert len(graph) >= 2
    assert start in graph
    assert end in graph

    # Create two dicts keyed by node, one for the distance to that node by the
    # currently known shortest path, and one with the previous node along said
    # shortest path (to be followed backwards to reconstruct this path).
    dist = {node: None for node in graph}
    prev = {node: None for node in graph}
    dist[start] = 0

    # Now relax the distances at most |V| - 1 times, or until no change occurs.
    num_iters = 0
    while num_iters < len(graph):
        if not update_edges(graph, dist, prev):
            break
        num_iters += 1

    # Check for negative cycles.
    if num_iters >= len(graph):
        raise NegativeCycleError

    # Reconstruct the shortest path.
    if dist[end] is not None:
        path = []
        current_node = end
        while(current_node is not None):
            path.append(current_node)
            current_node = prev[current_node]

        # The we went backwards through the path.
        path.reverse()

        return (dist[end], path)

    else:
        return (None, None)


def update_edges(graph, dist, prev):
    """Relaxes the current shortest path lengths for a graph.

    Parameters:
    graph -- A NetworkX DiGraph.
    dist -- A node-keyed dict of lengths of the shortest known path to nodes.
    prev -- A node-keyed dict of the previous node in the shortest known path.

    Returns: True if any paths were relaxed, False otherwise.

    Side Effects: Both dist and prev are modified, with the new relaxed paths.
    """
    modified = False
    for start, end, data in graph.edges_iter(data=True):
        if dist[start] is not None:
            if dist[end] is None or (dist[start] + data["weight"] < dist[end]):
                dist[end] = dist[start] + data["weight"]
                prev[end] = start
                modified = True

    return modified
