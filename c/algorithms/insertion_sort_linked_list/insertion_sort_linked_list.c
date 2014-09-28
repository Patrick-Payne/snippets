/******************************************************************************
 * File: insertion_sort_linked_list.c
 * Author: Patrick Payne
 * Date Created: Sun Sep 28 15:41:06 EDT 2014
 * Purpose: Implements insertion sort for a singly linked list.
 * Copyright Sun Sep 28 15:41:06 EDT 2014 by Patrick Payne.
 *****************************************************************************/
#include "insertion_sort_linked_list.h"
#include <stdlib.h>
#include <assert.h>

/******************************************************************************
 * Static Function Declarations
 *****************************************************************************/

/*! Inserts a new node into a sorted list, in sorted order. */
void insert(Node **list, Node *new_node);

/******************************************************************************
 * Public Function Definitions
 *****************************************************************************/

/*! Sorts a singly linked list in increasing order, using insertion sort. */
void sort_linked_list(Node **list) {
  assert(list != NULL);

  Node *temp_list = NULL;

  // Keep going while there are still elements left to insert.
  while (*list != NULL) {
    // Pop the left-most element off of the list.
    Node *element = *list;
    *list = element->next;
    element->next = NULL;

    // Insert the element into the sorted temp_list
    insert(&temp_list, element);
  }

  // Set the list to point to the new, sorted list.
  *list = temp_list;
}

/*! Tests if the insertion sort algorithm generates the correct result.
 * @param list The array of values to make a linked list out of.
 * @param expected The array of values expected of the sorted output.
 * @param size The number of elements in the list.
 * @return true if the result is as expected, false otherwise.
 */
bool test_sort(int *list, int *expected, int size) {
  assert(size > 0);
  assert(list != NULL);
  assert(expected != NULL);

  // First we create a linked list out of the input array.
  Node *linked_list = malloc(sizeof(Node));
  linked_list->value = list[0];
  linked_list->next = NULL;

  Node *current_node = linked_list;
  for (int i = 1; i < size; i++) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = list[i];
    new_node->next = NULL;

    current_node->next = new_node;
    current_node = new_node;
  }

  // Now we sort the linked list.
  sort_linked_list(&linked_list);

  // Now iterate over the expected array and the linked list, and check values.
  bool result = true;
  current_node = linked_list;
  for (int i = 0; i < size; i++) {
    if (current_node->value != expected[i]) {
      result = false;
      break;
    } else {
      current_node = current_node->next;
    }
  }

  // Free the memory in the linked list.
  current_node = linked_list;
  while (current_node != NULL) {
    Node *temp = current_node;
    current_node = current_node->next;
    free(temp);
  }

  return result;
}

/******************************************************************************
 * Static Function Definitions
 *****************************************************************************/

/*! Inserts a new node into a sorted list, in sorted order. */
void insert(Node **list, Node *new_node) {
  assert(list != NULL);
  assert(new_node != NULL);

  // If the list is empty, just throw the new element on it.
  if (*list == NULL) {
    *list = new_node;
    new_node->next = NULL;
    return;
  }

  // Check if the new element is the smallest element.
  if (new_node->value <= (*list)->value) {
    new_node->next = *list;
    *list = new_node;
    return;
  }

  // Loop invariant: prev is smaller than new_node.
  Node *prev = *list;
  Node *next = (*list)->next;
  while (next != NULL) {
    if (next->value < new_node->value) {
      prev = next;
      next = next->next;
    } else { // Next is greater or equal.
      prev->next = new_node;
      new_node->next = next;
      return;
    }
  }

  // If we get here, the new node is the largest element, and prev is the
  // last element in the linked list.
  prev->next = new_node;
  new_node->next = NULL;
}
