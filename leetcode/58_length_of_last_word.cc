/*
 * Length of Last Word
 * 
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 */

#include "common.h"

int lengthOfLastWord(string s) {

  // hanlde some string which contains some bank at tails.
  while (!s.empty() && s.back() == ' ') {
    s.pop_back();
  }

  string ret;
  for (auto i = s.rbegin(); i != s.rend(); i++) {
    if (*i == ' ') { 
      break;
    }
    ret = ret + *i; 
  }
  return ret.size();
}


int main() {
  cout << lengthOfLastWord("xxx yyy 123456") << endl;;
  cout << lengthOfLastWord("a") << endl;;

  return 0;
}

