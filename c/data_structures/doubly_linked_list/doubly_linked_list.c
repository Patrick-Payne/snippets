/******************************************************************************
 * File: doubly_linked_list.c
 * Author: Patrick Payne
 * Date Created: Sep 30, 2013
 * Purpose: Implements a doubly linked list, with basic functionality.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

#include "doubly_linked_list.h"

#include <assert.h>
#include <stdlib.h>


/******************************************************************************
 * PRIVATE FUNCTION DECLARATIONS:
 *****************************************************************************/ 

/*! @brief Creates a node by allocating memory it on the heap.
 *  @param item The integer to be put in the node.
 *  @return A pointer to the new node, allocated on the heap.
 */
static Node *CreateNode(int item);


/*! @brief Deletes a node from a linked list.
 *  @param node A pointer to the node to delete.
 */
static void DeleteNode(Node *node);


/*! @brief Inserts a new node before an existing node.
 *  @param new_node A pointer to the new node being added to the list.
 *  @param existing_node A pointer to the node we are placing new node before.
 */
static void InsertNodeBefore(Node *existing_node, Node *new_node);


/*! @brief Inserts a new node after an existing node.
 *  @param new_node A pointer to the new node being added to the list.
 *  @param existing_node A pointer to the node we are placing new node after.
 */
static void InsertNodeAfter(Node *existing_node, Node *new_node);


/******************************************************************************
 * PUBLIC FUNCTION DEFINITIONS:
 *****************************************************************************/ 

/*! @brief Create a new, empty list.
 *  @return The new list.
 */
List *CreateList(void) {
  List *new_list = malloc(sizeof(List));
  new_list->size = 0;

  // Link the dummy first to the dummy last node.
  new_list->dummy_first.prev = NULL;
  new_list->dummy_first.next = &(new_list->dummy_last);

  new_list->dummy_last.next = NULL;
  new_list->dummy_last.prev = &(new_list->dummy_first);

  return new_list;
}


/*! @brief Deletes a list, freeing all heap memory associated with it.
 *  @param list The list to be deleted.
 */
void DeleteList(List *list) {
  assert(list != NULL);

  // Free the memory associated with individual nodes.
  while (list->size > 0) {
    int dummy_item;
    PopFirstItem(list, &dummy_item);
  }

  // Now free the memory associated with the list struct itself.
  free(list);
}


/*! @brief Adds an integer element to the beginning of the linked list.
 *  @param list A pointer to the list in question.
 *  @param new_item The integer to be inserted into the list.
 */
void AddItemToBeginning(List *list, int new_item) {
  assert(list != NULL);

  // Create a new node with the given integer value.
  Node *new_node = CreateNode(new_item);

  // Put this node after the dummy first node, at the beginning of the list.
  InsertNodeAfter(&(list->dummy_first), new_node);
  list->size++;
}


/*! @brief Adds an integer element to the end of the linked list.
 *  @param list A pointer to the list in question.
 *  @param new_item The integer to be inserted into the list.
 */
void AddItemToEnd(List *list, int new_item) {
  assert(list != NULL);

  // Create a new node with the given integer value.
  Node *new_node = CreateNode(new_item);

  // Put this node before the dummy last node, at the end of the list.
  InsertNodeBefore(&(list->dummy_last), new_node);
  list->size++;
}


/*! @brief Removes and returns the first element from a linked list.
 *  @param list A pointer to the list in question.
 *  @param item The location to store the result in.
 *  @return false if the list was empty, true otherwise.
 */
bool PopFirstItem(List *list, int *item) {
  assert(list != NULL);
  assert(item != NULL);
  assert(list->size >= 0);

  if (list->size > 0) {
    list->size--;
    *item = list->dummy_first.next->value;
    DeleteNode(list->dummy_first.next);
    return true;
  } else {
    return false;
  }
}


/*! @brief Removes and returns the last element from a linked list.
 *  @param list A pointer to the list in question.
 *  @param item The location to store the result in.
 *  @return false if the list was empty, true otherwise.
 */
bool PopLastItem(List *list, int *item) {
  assert(list != NULL);
  assert(item != NULL);
  assert(list->size >= 0);

  if (list->size > 0) {
    list->size--;
    *item = list->dummy_last.prev->value;
    DeleteNode(list->dummy_last.prev);
    return true;
  } else {
    return false;
  }
}


/*! @brief Returns the value of the specified item in the list.
 *  @param list A pointer to the list in question.
 *  @param index The index of the item in the list.
 *  @param item A pointer to the location to store the item.
 *  @return true if an item exists at that index, false otherwise.
 */
bool GetItem(List *list, int index, int *item) {
  assert(list != NULL);

  if (list->size > index) {
    Node *current_node = list->dummy_first.next;
    for (int i = 0; i < index; i++) {
      current_node = current_node->next;
    }
    *item = current_node->value;
    return true;
  } else {
    return false;
  }
}


/*! @brief Removes the first item in the list with the specified value.
 *  @param list A pointer to the list in question.
 *  @param item The item to look for and delete.
 *  @return true if the item was found and deleted, false otherwise.
 */
bool DeleteItem(List *list, int item) {
  return true;
}


/*! @brief Performs a linear search to see if an int is in the linked list.
 *  @param list A pointer to the list in question.
 *  @param item The integer to search for.
 *  @return True if the integer was in the list.
 */
bool IsItemInList(List *list, int item) {
  return true;
}


/*! @brief Performs an insertion sort to put nodes in increasing order.
 *  @param list A pointer to the list in question.
 */
void InsertionSort(List *list) {
}


/*! @brief Performs an mergesort to put nodes in increasing order.
 *  @param list A pointer to the list in question.
 */
void MergeSort(List *list) {
}


/******************************************************************************
 * PRIVATE FUNCTION DEFINITIONS:
 *****************************************************************************/ 

/*! @brief Creates a node by allocating memory it on the heap.
 *  @param item The integer to be put in the node.
 *  @return A pointer to the new node, allocated on the heap.
 */
static Node *CreateNode(int item) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = item;
  new_node->next = NULL;
  new_node->prev = NULL;

  return new_node;
}


/*! @brief Deletes a node from a linked list.
 *  @param node A pointer to the node to delete.
 */
static void DeleteNode(Node *node) {
  assert(node != NULL);

  // Update the pointers of the previous and/or next nodes, if they exist.
  if (node->prev != NULL) {
    node->prev->next = node->next;
  }

  if (node->next != NULL) {
    node->next->prev = node->prev;
  }

  // Now deallocate the memory allocated for the node.
  free(node);
}


/*! @brief Inserts a new node before an existing node.
 *  @param new_node A pointer to the new node being added to the list.
 *  @param existing_node A pointer to the node we are placing new node before.
 */
static void InsertNodeBefore(Node *existing_node, Node *new_node) {
  assert(existing_node != NULL);
  assert(new_node != NULL);

  // Link new_node with the previous node, if it exists.
  new_node->prev = existing_node->prev;
  if (existing_node->prev != NULL) {
    existing_node->prev->next = new_node;
  }

  // Link new_node with existing node.
  new_node->next = existing_node;
  existing_node->prev = new_node;
}


/*! @brief Inserts a new node after an existing node.
 *  @param new_node A pointer to the new node being added to the list.
 *  @param existing_node A pointer to the node we are placing new node after.
 */
static void InsertNodeAfter(Node *existing_node, Node *new_node) {
  assert(existing_node != NULL);
  assert(new_node != NULL);

  // Link to the next node, if it exists.
  new_node->next = existing_node->next;
  if (existing_node->next != NULL) {
    existing_node->next->prev = new_node;
  }

  // Link the new_node to the existing_node.
  new_node->prev = existing_node;
  existing_node->next = new_node;
}
