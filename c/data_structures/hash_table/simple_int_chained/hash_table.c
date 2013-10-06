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
