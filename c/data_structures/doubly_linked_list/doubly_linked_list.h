/******************************************************************************
 * File: doubly_linked_list.h
 * Author: Patrick Payne
 * Date Created: Sep 30, 2013
 * Purpose: Implements a doubly linked list.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

#ifndef SNIPPET_C_DOUBLY_LINKED_LIST_H_
#define SNIPPET_C_DOUBLY_LINKED_LIST_H_

#include <stdbool.h>

/******************************************************************************
 * STRUCTURE DEFINITIONS:
 *****************************************************************************/ 

/*! @brief The structure used to represent nodes of a doubly-linked list. */
typedef struct Node {
  int value;
  struct Node *prev;
  struct Node *next;
} Node;


/*! @brief The structure representing a whole linked list. */
typedef struct List {
  struct Node dummy_first;  // An empty element, used to reduce special cases.
  struct Node dummy_last;   // An empty element, used to reduce special cases.
  int size;
} List;

/******************************************************************************
 * PUBLIC FUNCTION DECLARATIONS:
 *****************************************************************************/ 

/*! @brief Adds an integer element to the beginning of the linked list.
 *  @param list A pointer to the list in question.
 *  @param new_item The integer to be inserted into the list.
 */
void AddItemToBeginning(List *list, int new_item);


/*! @brief Adds an integer element to the end of the linked list.
 *  @param list A pointer to the list in question.
 *  @param new_item The integer to be inserted into the list.
 */
void AddItemToEnd(List *list, int new_item);


/*! @brief Removes and returns the first element from a linked list.
 *  @param list A pointer to the list in question.
 *  @param item The location to store the result in.
 *  @return false if the list was empty, true otherwise.
 */
bool PopFirstItem(List *list, int *item);


/*! @brief Removes and returns the last element from a linked list.
 *  @param list A pointer to the list in question.
 *  @param item The location to store the result in.
 *  @return false if the list was empty, true otherwise.
 */
bool PopLastItem(List *list, int *item);


/*! @brief Removes the first item in the list with the specified value.
 *  @param list A pointer to the list in question.
 *  @param item The item to look for and delete.
 *  @return true if the item was found and deleted, false otherwise.
 */
bool DeleteItem(List *list, int item);


/*! @brief Frees the memory allocated for a particular list.
 *  @param list A pointer to the list in question.
 */
void DeleteList(List *list);


/*! @brief Performs a linear search to see if an int is in the linked list.
 *  @param list A pointer to the list in question.
 *  @param item The integer to search for.
 *  @return True if the integer was in the list.
 */
bool IsItemInList(List *list, int item);


/*! @brief Performs an insertion sort to put nodes in increasing order.
 *  @param list A pointer to the list in question.
 */
void InsertionSort(List *list);


/*! @brief Performs an mergesort to put nodes in increasing order.
 *  @param list A pointer to the list in question.
 */
void MergeSort(List *list);


#endif /*SNIPPET_C_DOUBLY_LINKED_LIST_H_*/
