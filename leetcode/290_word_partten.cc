/*

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1: Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.

*/

#include "common.h"


bool wordPattern(string pattern, string str) {
  map<char, int> p2i;
  map<string, int> w2i;
  istringstream in(str);
  int i = 0, n = pattern.size();
  for (string word; in >> word; ++i) {
    if (i == n || p2i[pattern[i]] != w2i[word])
      return false;
    p2i[pattern[i]] = w2i[word] = i + 1;
  }

  return i == n;
}




int main() {

  // break down string using istringstream
  {
    string temp("aa bb xxxx yyy zzz kkk iii ");
    istringstream stream(temp);

    string word;

    while(stream >> word) {
      cout << word << endl;
    }
  }
  
  


  return 0;
}


