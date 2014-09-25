/******************************************************************************
 * File: binary_search_tree.c
 * Author: Patrick Payne
 * Date Created: Sep 19, 2014
 * Purpose: Implements a basic binary search tree data structure.
 * Copyright 2014 by Patrick Payne.
 *****************************************************************************/

#include "binary_search_tree.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/******************************************************************************
 * Static Function Declarations
 *****************************************************************************/
/*! Allocates memory for and initializes a single node. */
Node *create_node(int value);

/*! Recursively frees the nodes in a binary tree. */
void free_nodes(Node *root);


/*! Recursively adds nodes to a binary tree. Return True if insertion occured. */
bool recursive_insert_value(Node *root, int value);

/*! Recursively sums up the values of a binary tree. */
int sum_nodes(Node *root);


/* Returns the pointer to the node if found, NULL otherwise. */
Node **find_node(BST *tree, int value);


/*! Obtains a pointer to the smallest node in a binary tree, or NULL if empty. */
Node **get_smallest_node(Node **root);


/*! Obtains a pointer to the largest node in a binary tree, or NULL if empty. */
Node **get_largest_node(Node **root);


/*! Prints nodes in an inorder traversal. */
void recursive_print_tree(Node *root);


/******************************************************************************
 * Public Function Definitions
 *****************************************************************************/

BST *create_bst(void) {
  BST *new_tree = malloc(sizeof(BST));
  assert(new_tree != NULL);

  new_tree->size = 0;
  new_tree->root = NULL;
  return new_tree;
}


void destroy_bst(BST *tree) {
  assert(tree != NULL);
  free_nodes(tree->root);
  free(tree);
}


void insert_into_bst(BST *tree, int item) {
  if (tree->root == NULL) {
    assert(tree->size == 0);
    tree->root = create_node(item);
    tree->size = 1;
  } else {
    bool item_added = recursive_insert_value(tree->root, item);
    if (item_added) {
      tree->size++;
    }
  }
}


bool remove_from_bst(BST *tree, int item) {
  Node **found_node = find_node(tree, item);
  // We don't do anything of the value is not in the tree.
  if (found_node == NULL) {
    return false;
  }

  Node *left_node = (*found_node)->left;
  Node *right_node = (*found_node)->right;
  
  if (left_node != NULL) {
    // We replace the root with the largest node in the left subtree.
    Node **pointer_to_largest = get_largest_node(&((*found_node)->left));
    Node *largest = *pointer_to_largest;
    assert(largest->right == NULL);

    // We replace the largest element with whatever was in its left subtree.
    *pointer_to_largest = largest->left;

    // Set the children of the replacement node.
    if (largest != left_node) {
      largest->left = left_node;
    }
      largest->right = right_node;

    // free the memory for the old root.
    free(*found_node);

    // Set the parent of the root to point to the new root.
    *found_node = largest;
  } else if (right_node != NULL) {
    // We replace the root with the smallest node in the right subtree.
    Node **pointer_to_smallest = get_smallest_node(&((*found_node)->right));
    Node *smallest = *pointer_to_smallest;
    assert(smallest->left == NULL);

    // We replace the smallest element with whatever was in its left subtree.
    *pointer_to_smallest = smallest->right;

    // Set the children of the replacement node.
    if (smallest != right_node) {
      smallest->right = right_node;
    }
    smallest->left = left_node;

    // free the memory for the old root.
    free(*found_node);

    // Set the parent of the root to point to the new root.
    *found_node = smallest;
  } else { // Both left and right are NULL.
    free(*found_node);
    *found_node = NULL;
  }

    tree->size--;
    return true;
}


bool bst_contains(BST *tree, int item) {
  return (find_node(tree, item) != NULL);
}


int get_smallest_in_bst(BST *tree) {
  assert(tree != NULL);
  assert(tree->size != 0);

  return ((*get_smallest_node(&tree->root))->value);
}


int get_largest_in_bst(BST *tree) {
  assert(tree != NULL);
  assert(tree->size != 0);

  return ((*get_largest_node(&tree->root))->value);
}


int get_median_of_bst(BST *tree) {
  assert(tree != NULL);
  return 0;
}


double get_mean_of_bst(BST *tree) {
  assert(tree != NULL);
  assert(tree->size != 0);

  int sum = sum_nodes(tree->root);
  return ((double) sum) / ((double) tree->size);
}


void print_bst(BST *tree) {
  printf("[");
  if (tree->size != 0) {
    recursive_print_tree(tree->root);
  }
  printf("]\n");
}


/******************************************************************************
 * Static Function Definitions
 *****************************************************************************/

Node *create_node(int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}


void free_nodes(Node *root) {
  if (root == NULL) return;

  free_nodes(root->left);
  free_nodes(root->right);

  free(root);
}


bool recursive_insert_value(Node *root, int value) {
  if (root == NULL || value == root->value) {
    return false;
  } else if (value < root->value) {
    if (root->left == NULL) {
      root->left = create_node(value);
      return true;
    } else {
       return recursive_insert_value(root->left, value);
    }
  } else { // value > root.value
    if (root->right == NULL) {
      root->right = create_node(value);
      return true;
    } else {
      return recursive_insert_value(root->right, value);
    }
  }
}


int sum_nodes(Node *root) {
  if (root == NULL) {
    return 0;
  } else {
    return root->value + sum_nodes(root->left) + sum_nodes(root->right);
  }
}


/*
Node **non_bst_find_node(Node **root, int value) {
  if (*root == NULL) {
    return NULL
  } else if ((*root)->value == value) {
    return root;
  } else {
    Node **left_result = find_node((*root)->left, value);
    Node **right_result = find_node((*root)->right, value);
    return (left_result != NULL) ? left_result : right_result;
  }
}
*/


Node **find_node(BST *tree, int value) {
  Node **current_node = &(tree->root);
  while (*current_node != NULL) {
    if ((*current_node)->value > value) {
      // Search the left subtree.
      current_node = &(*current_node)->left;
    } else if ((*current_node)->value < value) {
      // Search the right subtree.
      current_node = &(*current_node)->right;
    } else { // We have a match.
      return current_node;
    }
  }

  // The tree does not contain that value.
  return NULL;
}


Node **get_smallest_node(Node **root) {
  // Handles base case where there is no root.
  if (root == NULL || *root == NULL) {
    return NULL;
  }

  Node **current_node = root;
  while ((*current_node)->left != NULL) {
    current_node = &((*current_node)->left);
  }
  return current_node;
}


Node **get_largest_node(Node **root) {
  // Handles base case where there is no root.
  if (root == NULL || *root == NULL) {
    return NULL;
  }
  Node **current_node = root;
  while ((*current_node)->right != NULL) {
    current_node = &((*current_node)->right);
  }
  return current_node;
}


void recursive_print_tree(Node *root) {
  if (root == NULL) {
    return;
  }
  recursive_print_tree(root->left);
  printf("%d, ", root->value);
  recursive_print_tree(root->right);
}
