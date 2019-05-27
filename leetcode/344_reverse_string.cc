/*
 *  Write a function that takes a string as input and returns the string reversed.
 *  
 *  Example 1:
 *  
 *  Input: "hello"
 *  Output: "olleh"
 *  Example 2:
 *  
 *  Input: "A man, a plan, a canal: Panama"
 *  Output: "amanaP :lanac a ,nalp a ,nam A"
 *  
 */


#include "common.h"


string reverseString(string s) {
  reverse(s.begin(), s.end());
  return s;
}


void reverseString(vector<char>& s) {
  for (int i = 0; i < s.size() / 2; i++) {
    swap(s[i], s[s.size() - 1 - i]);
  }
}



