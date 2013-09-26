/******************************************************************************
 * File: reverse_c_string.cpp
 * Author: Patrick Payne
 * Date Created: Sep 25, 2013
 * Purpose: Reverses a C style string in place.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/
#ifndef SNIPPET_C_REVERSE_C_STRING_H_
#define SNIPPET_C_REVERSE_C_STRING_H_

/*! @brief Reverses a c-style string in place. Assumes the memory location
 *   that holds the string is valid and writeable, and that the string is
 *   properly null-terminated. In addition, the string should use only ASCII
 *   characters, each stored as a char in memory.
 *  @param in_string A pointer to the first character in the string.
 */
void reverse_string(char *in_string);

#endif /* SNIPPET_C_REVERSE_C_STRING_H_ */
