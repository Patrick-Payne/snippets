/******************************************************************************
 * File: hash_table.c
 * Author: Patrick Payne
 * Date Created: Oct 05, 2013
 * Purpose: declares functions for operating on hash table for ints, without
 *     resizing and using chaining for collision resolution.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

#ifndef SNIPPET_C_HASH_TABLE_H_
#define SNIPPET_C_HASH_TABLE_H_

#include <stdbool.h>

/******************************************************************************
 * STRUCT DEFINITIONS:
 *****************************************************************************/ 
/*! @brief The structure used to represent the singly-linked list nodes in
 *    collision chains.
 */
typedef struct Node {
  int value;
  struct Node *next;
} Node;

/*! @brief This is the structure used to hold hash tables.
 */
typedef struct HashTable {
  Node **table;
  int num_slots;
  int num_elements;
} HashTable;

/******************************************************************************
 * PUBLIC FUNCTION DECLARATIONS:
 *****************************************************************************/ 

/*! @brief Initializes and returns a new hash table of a specified size.
 *  @param num_slots The number of slots the new dictionary should have.
 *  @return A new hash table, allocated from the free store.
 */
HashTable HashCreate(int num_slots);


/*! @brief Frees all heap memory allocated for the member variables of a hash
 *     table.
 *  @param hash_table The hash table to destroy.
 */
void HashDestroy(HashTable *hash_table);


/*! @brief Inserts an integer into an existing hash table.
 *  @param hash_table The hash table to insert into.
 *  @param item The integer to add to the hash table.
 */
void HashInsert(HashTable *hash_table, int item);


/*! @brief Check if an integer is in a hash table.
 *  @param hash_table The hash table to insert into.
 *  @param item The item to look for.
 *  @return true if the item is in the hash table, false otherwise.
 */
bool HashSearch(HashTable *hash_table, int item);


/*! @brief Inserts an integer into an existing hash table.
 *  @param hash_table The hash table to insert into.
 *  @param item The integer item to be deleted.
 *  @return true if the item was in the list and deleted, false otherwise.
 */
bool HashDelete(HashTable *hash_table, int item);


#endif /*SNIPPET_C_HASH_TABLE_H_*/
