#!/usr/bin/env python3

"""
File: matrix_chaining.py
Author: Patrick Payne
Date Created: Mar 12, 2014
Description: Implements the basic dynamic programming solution to the matrix
chaining problem. The structures used and the approach is the same as presented
in CLRS 3e, chapter 15.2. However, I combine computing the optimal costs and
constructing the optimal solution into one function.
"""

def matrix_chain_order(dims):
    """Return the optimal parenthesization of a matrix chain.
    
    Parameters:
    dims -- A list containing the dimensions of the matrices in the chain.
      for example, <10, 15> * <15, 100> * <100, 50> would be represented in
      the list [10, 15, 100, 50].
    
    Returns: The tuple (min_cost, splits)
    min_cost -- The minimum cost of any parethesization.
    splits -- A nested list. splits[i][j] will give the optimal index to split
        the matrix chain from i to j.
    """
    
    num_matrices = len(dims) - 1

    # Create blank tables to hold min_costs, splits.
    min_costs = [[None] * num_matrices for i in range(num_matrices)]
    splits = [[None] * num_matrices for i in range(num_matrices)]

    # All chains of length 1 require no steps to solve.
    for index in range(num_matrices):
        min_costs[index][index] = 0

    # We go from the smallest chain length to the largest.
    for chain_len in range(2, num_matrices + 1):
        # Try each possible starting index.
        for i in range(0, num_matrices - chain_len + 1):
            j = i + chain_len - 1

            for k in range(i, j):
                cost = (min_costs[i][k] + min_costs[k+1][j] +
                        dims[i]*dims[k+1]*dims[j+1])
                if min_costs[i][j] == None or cost < min_costs[i][j]:
                    min_costs[i][j] = cost
                    splits[i][j] = k

    return (min_costs[0][num_matrices - 1], splits)

def optimal_parens(names, splits, i, j):
    """Returns a string representation of a matrix chain parethesization.
    
    Parameters:
    names -- A list of names for the matrices, in string form.
    splits -- The matrix of optimal split locations from matrix_chain_order().
    i -- The index of the matrix to start printing at.
    j -- The index of the matrix to stop printing at.
    
    Returns: A string with the optimal parenthesization.
    """
    if i == j:
        return names[i]
    else:
        result = '('
        result += optimal_parens(names, splits, i, splits[i][j])
        result += optimal_parens(names, splits, splits[i][j] + 1, j)
        result += ')'

    return result

if __name__ == '__main__':
    # Multiply ABCD, where A is 2x2, B is 2x25, C is 25x 15, D is 15x1000
    cost, splits = matrix_chain_order([2, 2, 25, 15, 1000])
    print(optimal_parens(["A", "B", "C", "D"], splits, 0, 3))
