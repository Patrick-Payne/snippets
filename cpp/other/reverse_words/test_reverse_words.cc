/******************************************************************************
 * File: test_reverse_words.cc
 * Author: Patrick Payne
 * Date Created: Sun Nov 30 19:57:38 EST 2014
 * Purpose:
 * Copyright Sun Nov 30 19:57:38 EST 2014 by Patrick Payne.
 *****************************************************************************/

#include "reverse_words.h"
#include "gtest/gtest.h"

/******************************************************************************
 * Test Cases
 *****************************************************************************/ 

TEST(TESTREVERSE, TESTBASIC) {
  string in_word = "hello, world!";
  string out_word;
  ReverseWords(in_word, out_word);

  ASSERT_EQ("world! hello,", out_word);

  in_word = " i am  omnizod! ";
  ReverseWords(in_word, out_word);
  ASSERT_EQ(" omnizod!  am i ", out_word);
}
