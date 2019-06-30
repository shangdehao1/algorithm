/*
Implement strStr()

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

*/

#include "common.h"

// better method....

namespace general_method {

int strStr(string haystack, string needle) {
  if(haystack.empty() && !needle.empty()) return -1;
  if(haystack.empty() && needle.empty()) return 0;
    
  auto compare_string = [] (string x, string y) {
    return x == y;
  };


  for (int i = 0; i < haystack.size(); i++) {
    if ((haystack.size() - i) < needle.size()) {
      return -1;
    }

    if (compare_string(haystack.substr(i, needle.length()), needle)) {
      return i;
    }
  }
  return -1;
}


}



int main() {return 0; }
