/******************************************************************************
 * File: reverse_c_string.c
 * Author: Patrick Payne
 * Date Created: Sep 25, 2013
 * Purpose: Implements a function to reverse a c style string in place.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/
#include "reverse_c_string.h"

#include <string.h>


/******************************************************************************
 * Public Function Definitions
 *****************************************************************************/ 

/*! @brief Reverses a c-style string in place. Assumes the memory location
 *   that holds the string is valid and writeable, and that the string is
 *   properly null-terminated. In addition, the string should use only ASCII
 *   characters, each stored as a char in memory.
 *  @param in_string A pointer to the first character in the string.
 */
void reverse_string(char *in_string) {
  int length = strlen(in_string);

  // We swap characters from the first half with corresponding characters from
  // the second half of the string, going from the outside inwards.
  char *left_char = in_string;
  char *right_char = in_string + (length - 1);
  while ((right_char - left_char) > 0) {
    char temp = *left_char;
    *left_char = *right_char;
    *right_char = temp;

    // Go to the next characters closer to the middle of the string.
    left_char++;
    right_char--;
  }
}
