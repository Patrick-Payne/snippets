/******************************************************************************
 * File: test_hash_table.c
 * Author: Patrick Payne
 * Date Created: Oct 05, 2013
 * Purpose: Tests the simple hash table implemented in hash_table.c.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/
extern "C" {
#include "hash_table.h"
}

#include "gtest/gtest.h"

/******************************************************************************
 * BASIC FUNCTIONALITY TEST:
 *****************************************************************************/ 

// Test that we can properly create and destroy a hash table.
TEST(BasicFunctionality, CreateDestroy) {
  // Create a new hash table.
  HashTable test_table = HashCreate(22);
  EXPECT_EQ(22, test_table.num_slots);
  EXPECT_EQ(0, test_table.num_elements);

  // All of the table elements should have been initialized to NULL.
  for (int i = 0; i < 22; i++) {
    ASSERT_EQ(NULL, test_table.table[i]);
  }

  // Now destroy the list, and make sure the table was set to NULL.
  HashDestroy(&test_table);
  EXPECT_EQ(NULL, test_table.table);
  EXPECT_EQ(0, test_table.num_slots);
}


// Test that we can properly add items into a table and search for them.
TEST(BasicFunctionality, Insert) {
  // Create a new hash table.
  HashTable test_table = HashCreate(22);

  // Insert a single dummy element.
  HashInsert(&test_table, 0);
  EXPECT_EQ(1, test_table.num_elements);

  // Searching for this element should return true, but not for other elements.
  EXPECT_TRUE(HashSearch(&test_table, 0));
  EXPECT_FALSE(HashSearch(&test_table, 1));

  // Items with the same hash code as items in the hash table should still
  // return false for the search.
  EXPECT_FALSE(HashSearch(&test_table, 22));
  EXPECT_FALSE(HashSearch(&test_table, 44));

  // Insert more dummy elements.
  HashInsert(&test_table, 1);
  EXPECT_EQ(2, test_table.num_elements);
  HashInsert(&test_table, -125);
  EXPECT_EQ(3, test_table.num_elements);
  HashInsert(&test_table, 22);
  EXPECT_EQ(4, test_table.num_elements);

  // Now search for these elements.
  EXPECT_TRUE(HashSearch(&test_table, 0));
  EXPECT_TRUE(HashSearch(&test_table, 22));
  EXPECT_TRUE(HashSearch(&test_table, -125));
  EXPECT_TRUE(HashSearch(&test_table, 1));

  // Destroy the hash table.
  HashDestroy(&test_table);
}

// Test that we can both and and remove items.
TEST(BasicFunctionality, Delete) {
  // Create a new hash table.
  HashTable test_table = HashCreate(31);

  // Insert some dummy elements.
  HashInsert(&test_table, -1);
  HashInsert(&test_table, 0);
  HashInsert(&test_table, 1);
  HashInsert(&test_table, 22);
  EXPECT_EQ(4, test_table.num_elements);

  // Now search for these elements.
  EXPECT_TRUE(HashSearch(&test_table, 0));
  EXPECT_TRUE(HashSearch(&test_table, 22));
  EXPECT_TRUE(HashSearch(&test_table, -1));
  EXPECT_TRUE(HashSearch(&test_table, 1));

  // Now delete an item.
  EXPECT_TRUE(HashDelete(&test_table, 1));
  EXPECT_EQ(3, test_table.num_elements);
  EXPECT_FALSE(HashSearch(&test_table, 1));

  // Make sure we didn't touch the other elements.
  EXPECT_TRUE(HashSearch(&test_table, 0));
  EXPECT_TRUE(HashSearch(&test_table, 22));
  EXPECT_TRUE(HashSearch(&test_table, -1));

  // Delete more elements.
  EXPECT_TRUE(HashDelete(&test_table, 22));
  EXPECT_TRUE(HashDelete(&test_table, -1));
  EXPECT_FALSE(HashSearch(&test_table, 1));
  EXPECT_FALSE(HashSearch(&test_table, 22));
  EXPECT_FALSE(HashSearch(&test_table, -1));
  EXPECT_EQ(1, test_table.num_elements);
  EXPECT_TRUE(HashSearch(&test_table, 0));

  // Destroy the hash table.
  HashDestroy(&test_table);
}


/******************************************************************************
 * STRESS TESTING:
 *****************************************************************************/ 

// Test the case where we have a very large number of elements.
TEST(StressTesting, LotsOfElements) {
  for (int num_slots = 1; num_slots < 100; num_slots++) {
    // Create a new hash table.
    HashTable test_table = HashCreate(num_slots);

    // Insert a lot of elements into the hash table.
    for (int i = 0; i < 200; i++) {
      HashInsert(&test_table, i);
    }

    // Check that all the elements are still in the hashtable.
    for (int i = 0; i < 200; i++) {
      EXPECT_TRUE(HashSearch(&test_table, i));
    }

    // Check that all elements can be removed successfully.
    for (int i = 0; i < 200; i++) {
      EXPECT_TRUE(HashDelete(&test_table, i));
    }

    // Destroy the hash table.
    HashDestroy(&test_table);
  }
}
