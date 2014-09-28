/******************************************************************************
 * File: insertion_sort_linked_list.h
 * Author: Patrick Payne
 * Date Created: Sun Sep 28 15:41:06 EDT 2014
 * Purpose: Provides an insertion sort algorithm for linked lists.
 * Copyright Sun Sep 28 15:41:06 EDT 2014 by Patrick Payne.
 *****************************************************************************/
#ifndef SNIPPET_C_INSERTION_SORT_LINKED_LIST_H_
#define SNIPPET_C_INSERTION_SORT_LINKED_LIST_H_

#include <stdbool.h>

/******************************************************************************
 * Structure declarations
 *****************************************************************************/
typedef struct Node {
    int value;
    struct Node *next;
} Node;

/******************************************************************************
 * Public Function Declarations
 *****************************************************************************/

/*! Sorts a singly linked list in increasing order, using insertion sort. */
void sort_linked_list(Node **list);


/*! Tests if the insertion sort algorithm generates the correct result.
 * @param list The array of values to make a linked list out of.
 * @param expected The array of values expected of the sorted output.
 * @param size The number of elements in the list.
 * @return true if the result is as expected, false otherwise.
 */
bool test_sort(int *list, int *expected, int size);

#endif /* SNIPPET_C_INSERTION_SORT_LINKED_LIST_H_ */
