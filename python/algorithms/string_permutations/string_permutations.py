#!/usr/bin/env python3
from sys import argv,exit
"""
File: string_permutations.py
Author: Patrick Payne
Date Created: Nov 23, 2014
Description: Implements a basic algorithm for generating a list of permutations
    of a string of characters. This is not really an ideal algorithm, since it
    stores all permutations in memory, thus taking exponential space.
"""

def get_permutations(in_str):
    permutations = []
    recursive_get_permutations(list(in_str), "", permutations)
    return permutations

def recursive_get_permutations(chars, so_far, permutations):
    if len(chars) == 0:
        permutations.append(so_far)
    else:
        for char in chars:
            new_str = so_far + char
            new_chars = chars[:]
            new_chars.remove(char)
            recursive_get_permutations(new_chars, new_str, permutations)

if __name__ == '__main__':
    if len(argv) != 2:
        print("Usage: {} string".format(argv[0]))
        exit(-1)

    permutations = get_permutations(argv[1])
    for permutation in permutations:
        print(permutation)

    exit(0)

