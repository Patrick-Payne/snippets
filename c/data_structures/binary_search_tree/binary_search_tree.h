/******************************************************************************
 * File: binary_search_tree.h
 * Author: Patrick Payne
 * Date Created: Sep 19, 2014
 * Purpose: Implements a basic binary search tree data structure.
 * Copyright 2014 by Patrick Payne.
 *****************************************************************************/

#ifndef SNIPPET_C_BINARY_SEARCH_TREE_H_
#define SNIPPET_C_BINARY_SEARCH_TREE_H_

#include <stdbool.h>

/******************************************************************************
 * STRUCTURE DEFINITIONS:
 *****************************************************************************/ 

/*! @brief A structure to represent a single node in the binary tree. */
typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;


/*! @brief A structure for representing entire binary search trees. */
typedef struct BST {
  struct Node *root;
  int size;
} BST;

/******************************************************************************
 * PUBLIC FUNCTION DECLARATIONS:
 *****************************************************************************/ 

/*! @brief Create a new, empty binary tree.
 *  @return A pointer to the new tree.
 *  @note The memory used by this structure must be freed using destroy_tree().
 */
BST *create_bst(void);


/*! @brief Destroys an existing tree, freeing the memory used. */
void destroy_bst(BST *tree);


/*! @brief Inserts an item into a binary tree. */
void insert_into_bst(BST *tree, int item);


/* @brief Removes an item from the tree.
 * @param tree The tree to remove from.
 * @param item The integer to remove from the tree.
 * @return true if the item was in the tree, and removed, false otherwise.
 */
bool remove_from_bst(BST *tree, int item);


/*! @brief Returns true if the tree contains a particular value. */
bool bst_contains(BST *tree, int item);


/*! @brief Returns the smallest item in the tree. */
int get_smallest_in_vst(BST *tree);


/*! @brief Returns the largest item in the tree. */
int get_largest_in_bst(BST *tree);


/*! @brief Returns the median of the items in the tree. */
int get_median_of_bst(BST *tree);


/*! @brief Returns the mean of the items in the tree. */
double get_mean_of_bst(BST *tree);


/*! @brief Prints the inorder traversal of the tree. */
void print_bst(BST *tree);


#endif /*SNIPPET_C_BINARY_SEARCH_TREE_H_*/
