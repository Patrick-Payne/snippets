/******************************************************************************
 * File: bst.h
 * Author: Patrick Payne
 * Date Created: Tue Oct  7 19:01:08 EDT 2014
 * Purpose:  Implements a basic binary tree.
 * Copyright Tue Oct  7 19:01:08 EDT 2014 by Patrick Payne.
 *****************************************************************************/
#ifndef SNIPPET_C_BST_H_
#define SNIPPET_C_BST_H_

#include <cstdlib>
#include <cstdio>
#include <cassert>

/******************************************************************************
 * Struct declarations
 *****************************************************************************/
template<class T>
struct Node {
  T value;
  struct Node<T> *left;
  struct Node<T> *right;
  struct Node<T> *parent;
};

template<class T>
class BinaryTree
{
public:
  BinaryTree();
  ~BinaryTree();

  /*! Insert a new element in the BST if it did not already exist. */
  void insert(T item);

  /*! Remove an element from the BST if it exists. Return True if it existed.*/
  bool remove(T item);

  /*! Return true if an item exists in the BST, false otherwise. */
  bool contains(T item);

  /*! Get the number of elements in the BST. */
  size_t size();

  /*! Set min_out to the least member of the BST. Return true if successful.*/
  bool min(T *min_out);

  /*! Set max_out to the greatest member of the BST. Return true if successful.*/
  bool max(T *max_out);

  /*! Set med_out to the lower median of the BST. Return true if successful.*/
  bool median(T *med_out);

  /*! Set deepest_out to the value in the deepest node of the tree. */
  bool deepest(T *deepest_out);

  /* Sum up all of the nodes in a BST, and return this sum. */
  T sum_nodes(Node<T> *root);

  /* Print all the elements of the tree in order. */
  void print_tree();

private:
  Node<T> **find_node(T value);
  Node<T> **get_smallest_node(Node<T> **root);
  Node<T> **get_largest_node(Node<T> **root);
  void recursive_print_tree(Node<T> *root);

  Node<T> *create_node(T value);
  void free_nodes(Node<T> *root);

  bool recursive_insert_value(Node<T> *root, T value);

  bool get_ith_node(Node<T> *root, int *num_remaining, Node<T> **item);

  size_t get_deepest_node(Node<T> *root, Node<T> **deepest_node);

  Node<T> *m_root;
  size_t m_size;
};

/******************************************************************************
 * BinaryTree Method Definitions
 *****************************************************************************/

template<class T>
BinaryTree<T>::BinaryTree() {
  m_root = NULL;
  m_size = 0;
}


template<class T>
BinaryTree<T>::~BinaryTree() {
  free_nodes(m_root);
}


template<class T>
void BinaryTree<T>::insert(T item) {
  if (m_root == NULL) {
    assert(m_size == 0);
    m_root = create_node(item);
    m_size = 1;
  } else {
    bool inserted = recursive_insert_value(m_root, item);
    if (inserted) {
      m_size++;
    }
  }
}


template<class T>
bool BinaryTree<T>::remove(T item) {
  Node<T> **found_node = find_node(item);
  if (found_node == NULL) {
    return false;
  }

  Node<T> *left_child = (*found_node)->left;
  Node<T> *right_child = (*found_node)->right;

  if (left_child != NULL) {
    // We replace the root with the largest node in the left subtree.
    Node<T> **pointer_to_largest = get_largest_node(&(left_child));
    Node<T> *largest = *pointer_to_largest;
    assert(largest->right == NULL);

    // We replace the largest element with whatever was in its left subtree.
    *pointer_to_largest = largest->left;

    // Now transplant the largest element into the root.
    if (largest != left_child) {
      largest->left = left_child;
    }
    largest->right = right_child;

    delete *found_node;
    *found_node = largest;

  } else if (right_child != NULL) {
    // We replace the root with the smallest node in right subtree
    Node<T> **pointer_to_smallest = get_smallest_node(&(right_child));
    Node<T> *smallest = *pointer_to_smallest;
    assert(smallest->left == NULL);

    // We replace the smallest element with whatever was in its right subtree.
    *pointer_to_smallest = smallest->right;

    // Now transplant the smallest element into the root.
    if (smallest != right_child) {
      smallest->right = right_child;
    }
    smallest->left = left_child;

    delete *found_node;
    *found_node = smallest;
  } else { // Left and right subtrees are empty.
    delete *found_node;
    *found_node = NULL;
  }

  m_size--;
  return true;
}


template<class T>
bool BinaryTree<T>::contains(T item) {
  return find_node(item) != NULL;
}

template<class T>
size_t BinaryTree<T>::size() {
  return m_size;
}

template<class T>
bool BinaryTree<T>::min(T *min_out) {
  Node<T> **smallest = get_smallest_node(&m_root);
  if (smallest != NULL) {
    *min_out = (*smallest)->value;
    return true;
  } else {
    return false;
  }
}


template<class T>
bool BinaryTree<T>::max(T *max_out) {
  Node<T> **largest = get_largest_node(&m_root);
  if (largest != NULL) {
    *max_out = (*largest)->value;
    return true;
  } else {
    return false;
  }
}


template<class T>
bool BinaryTree<T>::median(T *med_out) {
  if (size() == 0) {
    return false;
  }

  Node<T> *result_node = NULL;
  int num_remaining = (size() + 1) / 2;
  assert(get_ith_node(m_root, &num_remaining, &result_node));
  *med_out = result_node->value;
  return true;
}

template<class T>
bool BinaryTree<T>::deepest(T *deepest_out) {
  Node<T> *deepest_node = NULL;
  size_t depth = get_deepest_node(m_root, &deepest_node);
  if (depth == 0) {
    return false;
  } else {
    assert(deepest_node != NULL);
    *deepest_out = deepest_node->value;
    return true;
  }
}


template<class T>
T BinaryTree<T>::sum_nodes(Node<T> *root) {
  if (root == NULL) {
    return 0;
  } else {
    return root->value + sum_nodes(root->left) + sum_nodes(root->right);
  }
}


template<class T>
void BinaryTree<T>::print_tree() {
  return;
}

/******************************************************************************
 * Private function declarations
 *****************************************************************************/

/*! Allocates memory for a new BST node. */
template<class T>
Node<T> *BinaryTree<T>::create_node(T value) {
  Node<T> *new_node = new Node<T>;
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}


/*! Recursively free the nodes of a subtree of the BST. */
template<class T>
void BinaryTree<T>::free_nodes(Node<T> *root) {
  if (root == NULL) return;

  free_nodes(root->left);
  free_nodes(root->right);

  delete root;
}


/*! Recurse down the tree until we find the correct place to insert a value.
 * When we find it, insert the value.
 */
template<class T>
bool BinaryTree<T>::recursive_insert_value(Node<T> *root, T value) {
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


/*! Find the node containing a certain value.  Return NULL if not in BST. */
template<class T>
Node<T> **BinaryTree<T>::find_node(T value) {
  Node<T> **current_node = &m_root;
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


/*! Return the node containing the min element of the subtree. */
template<class T>
Node<T> **BinaryTree<T>::get_smallest_node(Node<T> **root) {
  // Handles base case where there is no root.
  if (root == NULL || *root == NULL) {
    return NULL;
  }

Node<T> **current_node = root;
  while ((*current_node)->left != NULL) {
    current_node = &((*current_node)->left);
  }
  return current_node;
}


/*! Return the node containing the max element of the subtree. */
template<class T>
Node<T> **BinaryTree<T>::get_largest_node(Node<T> **root) {
  // Handles base case where there is no root.
  if (root == NULL || *root == NULL) {
    return NULL;
  }
  Node<T> **current_node = root;
  while ((*current_node)->right != NULL) {
    current_node = &((*current_node)->right);
  }
  return current_node;
}


/*! Recursively print out the elements in the subtree inorder. */
template<class T>
void BinaryTree<T>::recursive_print_tree(Node<T> *root) {
  if (root == NULL) {
    return;
  }
  recursive_print_tree(root->left);
  printf("derp");
  recursive_print_tree(root->right);
}

/*! Gets the ith smallest item in the BST. */
template<class T>
bool BinaryTree<T>::get_ith_node(Node<T> *root, int *num_remaining, Node<T> **item) {
  if (root == NULL) {
    return false;
  }

  bool found_in_left = get_ith_node(root->left, num_remaining, item);
  if (found_in_left) {
    return true;
  }

  (*num_remaining)--;
  if (*num_remaining == 0) {
    *item = root;
    return true;
  }

  bool found_in_right = get_ith_node(root->right, num_remaining, item);
  assert(found_in_right);
  return true;
}

template<class T>
size_t BinaryTree<T>::get_deepest_node(Node<T> *root, Node<T> **deepest_node) {
  if (root == NULL) {
    return 0;
  }

  Node<T> *left_deepest, *right_deepest;
  size_t left_depth = get_deepest_node(root->left, &left_deepest);
  size_t right_depth = get_deepest_node(root->right, &right_deepest);

  if (left_depth == 0 && right_depth == 0) {
    *deepest_node = root;
    return 1;
  } else if (right_depth >= left_depth) {
    *deepest_node = right_deepest;
    return right_depth + 1;
  } else {
    *deepest_node = left_deepest;
    return left_depth + 1;
  }
}

#endif /* SNIPPET_C_BST_H_ */
