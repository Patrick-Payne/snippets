/******************************************************************************
 * File: reverse_words.cc
 * Author: Patrick Payne
 * Date Created: Sun Nov 30 19:57:38 EST 2014
 * Purpose:
 * Copyright Sun Nov 30 19:57:38 EST 2014 by Patrick Payne.
 *****************************************************************************/
#include "reverse_words.h"

#include <string>
#include <list>
#include <cctype>

using std::string;
using std::list;


/*! Given a string, return a string with all the words reversed. */
void ReverseWords(const string& in_str, string& out_str) {
  list<string> words;
  bool in_word = true;
  string cur_word;
  
  // Put all of the words into a linked list.
  for (string::const_iterator i = in_str.begin(); i != in_str.end(); i++) {
    if ((in_word && isspace(*i)) || (!in_word && isalnum(*i))) {
      if (cur_word.size() > 0) {
        words.push_back(cur_word);
        cur_word.clear();
      }
      in_word = isalnum(*i);
    }

    cur_word += *i;
  }

  if (cur_word.size() > 0) {
    words.push_back(cur_word);
  }

  // Now words contains all the words in forward order.
  out_str.clear();
  for (list<string>::reverse_iterator i = words.rbegin(); i != words.rend(); i++) {
    out_str += *i;
  }
}
