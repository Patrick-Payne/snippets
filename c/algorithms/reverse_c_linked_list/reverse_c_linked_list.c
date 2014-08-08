/******************************************************************************
 * File: reverse_c_linked_list.c
 * Author: Patrick Payne
 * Date Created: Aug 07, 2014
 * Purpose: Implements a simple algorithm to reverse a C linked list in place.
 * Copyright 2014 by Patrick Payne.
 *****************************************************************************/
#include "reverse_c_linked_list.h"
#include <stdlib.h>

/******************************************************************************
 * Public Function Definitions
 *****************************************************************************/ 

void ReverseList(Node **list) {
  // Do nothing if list is NULL
  if (list == NULL) return;

  Node *temp_list = NULL;
  // Iterate over each node until none are left in the original list.
  while (*list) {
    // Pop first element from original list.
    Node *swap_temp = *list;
    *list = (*list)->next;

    // Now add the node to the temporary list.
    swap_temp->next = temp_list;
    temp_list = swap_temp;
  }

  // Copy the temporary list back to the original list.
  *list = temp_list;
}
