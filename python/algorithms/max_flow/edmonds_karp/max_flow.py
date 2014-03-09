#!/usr/bin/env python3
"""
File: max_flow.py
Author: Patrick Payne
Date Created: Feb 20, 2014
Description: An implementation of the Ford Fulkerson method using BFS to find
    augmenting paths (aka. Edmond-Karp algorithm).
    The sample data file was taken from:
    http://www-cs-staff.stanford.edu/~knuth/contiguous-usa.dat
"""

import networkx as nx
import pdb

def max_flow(graph, source, sink, attribute='capacity'):
    """Return the maximum flow through a flow network.

    Uses the Edmonds-Karp algorithm.
    Parameters:
    graph -- an nx.Digraph object representing the flow network. Antiparallel
        edges are supported, but other contraints on flow networks must hold.
    source -- The source node on the graph.
    sink -- The sink node on the graph.
    attribute -- the edge attribute containing the capacities.

    Returns: An nx.Digraph representing the flow.
    """
    # Eliminate any antiparallel edges.
    simplified_graph = graph.copy()
    fake_nodes = remove_antiparallel(simplified_graph)

    # Create the empty flow.
    curr_flow = nx.create_empty_copy(simplified_graph)

    # Keep augmenting the flow with paths from the residual network until
    # no more augmenting paths exist.
    can_augment = True
    while can_augment:
        can_augment = augment(simplified_graph, curr_flow,
                              source, sink, attribute)

    # Restore antiparallel edges.
    restore_antiparallel(curr_flow, fake_nodes)

    return curr_flow


def augment(network, flow, source, sink, attribute='capacity'):
    """Augment a flow through a network. Return True if augmented, False if
    no augmenting paths exist.

    Parameters:
    network -- The flow network, represented using an nx.DiGraph object.
    flow -- The flow through the network, also represented by an nx.DiGraph.
    source -- The source node of the flow network.
    sink -- The sink node of the flow network.
    attribute -- The name of the edge attribute containing the capacity.

    Returns: True if successful, False if no more augmenting paths exist.
    """
    # Generate the residual network.
    residual = residual_flow(network, flow, attribute)


    # Use BFS to find an augmenting path. Return False if none exist.
    try:
        path_nodes = nx.shortest_path(residual, source, sink)
    except nx.exception.NetworkXNoPath:
        return False

    # Generate a list of edges in the augmenting path.
    path = []
    for index in range(len(path_nodes) - 1):
        path.append((path_nodes[index], path_nodes[index+1]))

    # Find the flow though this augmenting path.
    residual_capacities = nx.get_edge_attributes(residual, attribute)

    aug_flow = residual_capacities[path[0]]
    for edge in path:
        aug_flow = min(residual_capacities[edge], aug_flow)


    # Now augment flow with the discovered path.
    for start, end in path:
        # Check if we are pushing flow in the reverse direction.
        if (end, start) in flow.edges():
            flow[edge][start][attribute] -= aug_flow

        # Otherwise, we are pushing flow in the forward direction.
        elif (start, end) in flow.edges():
            flow[start][end][attribute] += aug_flow

        else:
            flow.add_edge(start, end)
            flow[start][end][attribute] = aug_flow

    return True


def residual_flow(network, flow, attribute='capacity'):
    """Return the residual flow through a flow network.

    Parameters:
    network -- The flow network, represented using an nx.DiGraph object.
    flow -- The flow through the network, also represented by an nx.DiGraph.
    attribute -- The name of the edge attribute containing the capacity.

    Returns: An nx.Digraph representing the residual flow.
    """
    residual = nx.create_empty_copy(network)
    for u, v in network.edges_iter():
        # Get the edge attributes from each graph
        capacity = network[u][v][attribute]
        used = flow[u][v][attribute] if (u, v) in flow.edges() else 0
        excess = capacity - used
        assert excess >= 0, "Flow had edges greater than capacity."

        # Add in any leftover forward capacity.
        if excess > 0:
            residual.add_edge(u, v, {attribute: excess})
        # Add in the decreasing flow residual
        if used > 0:
            residual.add_edge(v, u, {attribute: used})

    return residual


def remove_antiparallel(graph):
    """Given a nx.DiGraph, return the graph with antiparallel edges transformed
    to make an equivalent flow network without antiparallel edges.

    Parameters:
    graph -- An nx.Digraph object, representing what would be a network flow
      if not for the antiparallel edges.

    Returns: A set of tuples. The first element of each tuple is the name of
      a fake node, while the second and third are the nodes originally
      connected by the antiparallel edge.
    """
    # Collect all the antiparallel edges to remove.
    antiparallel_edges = set()
    for u, v in graph.edges_iter():
        if ((v, u) not in antiparallel_edges) and ((v, u) in graph.edges()):
            antiparallel_edges.add((u, v))

    fake_num = 0
    fake_set = set()
    for u, v in antiparallel_edges:
        # Create a name for the fake node, and make sure it's unique.
        new_node = "Fake" + str(fake_num)
        while (new_node in graph):
            fake_num += 1
            new_node = "Fake" + str(fake_num)

        # Insert the new node and pass (u,v) through this fake node.
        fake_set.add((new_node, u, v))
        graph.add_node(new_node)
        data = graph[u][v]
        graph.remove_edge(u, v)
        graph.add_edges_from([(u, new_node, data), (new_node, v, data)])

    return fake_set


def restore_antiparallel(graph, fake_nodes):
    """Remove the fake nodes inserted by remove_antiparallel.

    Parameters:
    graph -- An nx.DiGraph object representing a flow network.
    fake_nodes -- An iterable containing all of the fake nodes to remove.

    Returns: Does not return anything.
    """
    for fake, u, v in fake_nodes:
        if (u, fake) in graph.edges():
            data = graph[u][fake]
            graph.remove_edge(u, fake)
            graph.remove_edge(fake, v)
            graph.remove_node(fake)
            graph.add_edge(u, v, data)


if __name__ == '__main__':
    import matplotlib.pyplot as plt

    # Create an edge list from the file
    usa_edges = [tuple(line.split()) for line in open("usa_edges.dat")]
    reverse_edges = [(v, u) for (u, v) in usa_edges]
    usa_edges += reverse_edges

    # Get the node positions as well.
    pos = {}
    for line in open("state_locations.dat"):
        args = line.split()
        pos[args[0]] = [float(args[1]), float(args[2])]

    # Use this edge list to generate a networkx graph.
    usa_graph = nx.DiGraph(usa_edges)
    for start, end in usa_graph.edges():
        usa_graph[start][end]['weight'] = 4

    # Now find the shortest path from California to New York.
    # path_nodes = nx.shortest_path(usa_graph, "OR", "FL")
    
    flow = max_flow(usa_graph, "CA", "MO", attribute='weight')

    #non_path = [(u, v) for (u, v) in usa_edges if
    #                      (((u, v) not in path) and ((v, u) not in path))]

    # Draw ALL the edges.
    nx.draw_networkx_edges(flow, pos, width=3)
    nx.draw_networkx_edges(usa_graph, pos,
                           alpha=0.5, edge_color='r')
    nx.draw_networkx_nodes(usa_graph, pos, node_size=500)
    nx.draw_networkx_labels(usa_graph, pos, font_size=10)
    plt.show()

