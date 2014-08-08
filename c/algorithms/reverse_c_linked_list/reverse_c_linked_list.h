/******************************************************************************
 * File: reverse_c_linked_list.h
 * Author: Patrick Payne
 * Date Created: Aug 07, 2014
 * Purpose: Implements a simple algorithm to reverse a C linked list in place.
 * Copyright 2014 by Patrick Payne.
 *****************************************************************************/
#ifndef SNIPPET_C_REVERSE_C_LINKED_LIST_H_
#define SNIPPET_C_REVERSE_C_LINKED_LIST_H_

typedef struct Node {
  int value;
  struct Node *next;
} Node;


/*! @brief Reverses a c-style singly-linked list. Assumes the memory location
 *   that holds the linked_list is valid and writeable, and that the linked_list is
 *   properly null-terminated. 
 *  @param list A pointer to the linked list.
 */
void ReverseList(Node **list);

#endif /* SNIPPET_C_REVERSE_C_LINKED_LIST_H_ */
