/******************************************************************************
 * File: hash_table.c
 * Author: Patrick Payne
 * Date Created: Oct 05, 2013
 * Purpose: Implements a basic hash table for ints, without resizing and using
 *    chaining for collision resolution.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/
#include "hash_table.h"

#include <assert.h>
#include <stdlib.h>

/******************************************************************************
 * PRIVATE FUNCTION DECLARATIONS:
 *****************************************************************************/ 

/*! @brief returns the hash-table index for an item given the table size.
 *  @param item The integer item in question.
 *  @param num_slots The number of slots in the hash table.
 *  @return The index that item would be located in the hash table.
 */
static int HashFunction(int item, int num_slots);


/******************************************************************************
 * PUBLIC FUNCTION DEFINITIONS:
 *****************************************************************************/ 

/*! @brief Initializes and returns a new hash table of a specified size.
 *  @param num_slots The number of slots the new dictionary should have.
 *  @return A new hash table, allocated from the free store.
 */
HashTable HashCreate(int num_slots) {
  HashTable new_table;

  // Allocate the memory for the table from the heap.
  new_table.table = malloc(sizeof(Node *) * num_slots);

  // Clear all pointers to NULL.
  for (int i = 0; i < num_slots; i++) {
    new_table.table[i] = NULL;
  }

  // The new table has num_slots slots, and no elements yet.
  new_table.num_slots = num_slots;
  new_table.num_elements = 0;
  return new_table;
}


/*! @brief Frees all heap memory allocated for the member variables of a hash
 *     table.
 *  @param hash_table The hash table to destroy.
 */
void HashDestroy(HashTable *hash_table) {
  // Iterate over all chain lists, freeing nodes.
  for (int i = 0; i < hash_table->num_slots; i++) {
    // Free all nodes in the linked list.
    while (hash_table->table[i] != NULL) {
      Node *temp = hash_table->table[i];
      hash_table->table[i] = temp->next;
      free(temp);
    }
  }

  // Free the table itself.
  free(hash_table->table);
  hash_table->table = NULL;
  hash_table->num_slots = 0;
  hash_table->num_elements = 0;
}


/*! @brief Inserts an integer into an existing hash table.
 *  @param hash_table The hash table to insert into.
 *  @param item The integer to add to the hash table.
 */
void HashInsert(HashTable *hash_table, int item) {
  // Calculate the slot to insert the item into.
  int slot = HashFunction(item, hash_table->num_slots);

  // If the slot is empty, we can just insert it immediately.
  if (hash_table->table[slot] == NULL) {
    Node *new_node = malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->value = item;
    hash_table->table[slot] = new_node;
    hash_table->num_elements++;
  } else {
    // Check if item is already in the chain list.
    Node *check_node = hash_table->table[slot];
    while (check_node != NULL) {
      if (check_node->value == item) {
        return;
      }
      check_node = check_node->next;
    }

    // The item is not in the hash table. Insert it.
    Node *new_node = malloc(sizeof(Node));
    new_node->value = item;
    new_node->next = hash_table->table[slot];
    hash_table->table[slot] = new_node;
    hash_table->num_elements++;
  } /* else */
}


/*! @brief Check if an integer is in a hash table.
 *  @param hash_table The hash table to insert into.
 *  @param item The item to look for.
 *  @return true if the item is in the hash table, false otherwise.
 */
bool HashSearch(HashTable *hash_table, int item) {
  // Calculate the slot where the item should be located.
  int slot = HashFunction(item, hash_table->num_slots);

  // If there are no items at that slot, the item is not in the hash table.
  if (hash_table->table[slot] == NULL) {
    return false;
  } else {
    // Check if the item is in the chain list at this slot already.
    Node *check_node = hash_table->table[slot];
    while (check_node != NULL) {
      if (check_node->value == item) {
        return true;
      }
      check_node = check_node->next;
    }

    // The item was not in the chain list.
    return false;
  } /* else */
}


/*! @brief Inserts an integer into an existing hash table.
 *  @param hash_table The hash table to insert into.
 *  @param item The integer item to be deleted.
 *  @return true if the item was in the list and deleted, false otherwise.
 */
bool HashDelete(HashTable *hash_table, int item) {
  // Calculate the slot where the item should be located.
  int slot = HashFunction(item, hash_table->num_slots);

  // If no items are at the slot, the item does not exist and can't be deleted.
  if (hash_table->table[slot] == NULL) {
    return false;
  } else {
    // See if the node is in the chain list.
    Node *current_node = hash_table->table[slot];
    Node **previous_next_ptr = &(hash_table->table[slot]);
    while (current_node != NULL) {
      if (current_node->value == item) {
        // delete item.
        *previous_next_ptr = current_node->next;
        free(current_node);
        hash_table->num_elements--;
        return true;
      }
      previous_next_ptr = &(current_node->next);
      current_node = current_node->next;
    }
    // The item was not in the chain list.
    return false;
  } /* else */
}


/******************************************************************************
 * PRIVATE FUNCTION DECLARATIONS:
 *****************************************************************************/ 

/*! @brief returns the hash-table index for an item given the table size.
 *  @param item The integer item in question.
 *  @param num_slots The number of slots in the hash table.
 *  @return The index that item would be located in the hash table.
 */
static int HashFunction(int item, int num_slots) {
  return (abs(item) % num_slots);
}
