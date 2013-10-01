/******************************************************************************
 * File: doubly_linked_list.c
 * Author: Patrick Payne
 * Date Created: Sep 30, 2013
 * Purpose: Implements a doubly linked list, with basic functionality.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

#include "doubly_linked_list.h"

#include <stdio.h>
#include <assert.h>


/******************************************************************************
 * PRIVATE FUNCTION DECLARATIONS:
 *****************************************************************************/ 

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

/*! @brief Adds an integer element to the beginning of the linked list.
 *  @param list A pointer to the list in question.
 *  @param new_item The integer to be inserted into the list.
 */
void AddItemToBeginning(List *list, int new_item) {
}


/*! @brief Adds an integer element to the end of the linked list.
 *  @param list A pointer to the list in question.
 *  @param new_item The integer to be inserted into the list.
 */
void AddItemToEnd(List *list, int new_item) {
}


/*! @brief Removes and returns the first element from a linked list.
 *  @param list A pointer to the list in question.
 *  @param item The location to store the result in.
 *  @return false if the list was empty, true otherwise.
 */
bool PopFirstItem(List *list, int *item) {
  return true;
}


/*! @brief Removes and returns the last element from a linked list.
 *  @param list A pointer to the list in question.
 *  @param item The location to store the result in.
 *  @return false if the list was empty, true otherwise.
 */
bool PopLastItem(List *list, int *item) {
  return true;
}


/*! @brief Removes the first item in the list with the specified value.
 *  @param list A pointer to the list in question.
 *  @param item The item to look for and delete.
 *  @return true if the item was found and deleted, false otherwise.
 */
bool DeleteItem(List *list, int item) {
  return true;
}


/*! @brief Frees the memory allocated for a particular list.
 *  @param list A pointer to the list in question.
 */
void DeleteList(List *list) {
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

/*! @brief Deletes a node from a linked list.
 *  @param node A pointer to the node to delete.
 */
static void DeleteNode(Node *node) {
}


/*! @brief Inserts a new node before an existing node.
 *  @param new_node A pointer to the new node being added to the list.
 *  @param existing_node A pointer to the node we are placing new node before.
 */
static void InsertNodeBefore(Node *existing_node, Node *new_node) {
}


/*! @brief Inserts a new node after an existing node.
 *  @param new_node A pointer to the new node being added to the list.
 *  @param existing_node A pointer to the node we are placing new node after.
 */
static void InsertNodeAfter(Node *existing_node, Node *new_node) {
}
