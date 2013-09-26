/******************************************************************************
 * File: test_reverse_c_string.cpp
 * Author: Patrick Payne
 * Date Created: Sep 25, 2013
 * Purpose: Tests the string reversal function from reverse_c_string.h
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/extern "C" {
#include "reverse_c_string.h"
}

#include <cstring>
#include "gtest/gtest.h"


/******************************************************************************
 * Test Cases
 *****************************************************************************/ 

/* Test the cases where we have an even number of characters. */
TEST(ReverseCString, EvenLength) {
  char test_string[30] = {};

  // We should not do anything with an empty string.
  strcpy(test_string, "");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, ""));

  // We should swap the characters of a 2 character string.
  strcpy(test_string, "ab");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "ba"));

  strcpy(test_string, ")1");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "1)"));

  // Now test longer strings.
  strcpy(test_string, "abcd");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "dcba"));

  strcpy(test_string, "Orangutans");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "snatugnarO"));

  strcpy(test_string, "1a2b3c4d5e6f");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "f6e5d4c3b2a1"));
}

/* Test the cases where we have an odd number of characters. */
TEST(ReverseCString, OddLength) {
  char test_string[30] = {};

  // We should not modify a string with one element.
  strcpy(test_string, "A");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "A"));

  strcpy(test_string, "2");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "2"));

  // We should flip first and last letter for 3 letter words.
  strcpy(test_string, "123");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "321"));

  strcpy(test_string, "god");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "dog"));


  // Now test longer words.
  strcpy(test_string, "racecar");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "racecar"));

  strcpy(test_string, "1$nb+?)12z");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "z21)?+bn$1"));

  strcpy(test_string, "zippity-zap..!");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, "!..paz-ytippiz"));

  strcpy(test_string, "I like eating cheese.");
  reverse_string(test_string);
  EXPECT_EQ(0, strcmp(test_string, ".eseehc gnitae ekil I"));
}
