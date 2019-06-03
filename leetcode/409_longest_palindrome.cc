/*
 * Given a string which consists of lowercase or uppercase letters, 
 * find the length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * Example:
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
*/


// =============== mistake :( =====================

#include "common.h"

/*
namespace method1 {
int longestPalindrome(string s) 
{
  auto search = [](const string& s, int left, int right) {        
    while (left >= 0 && right < s.size()) {
      if (s[left] == s[right]) {
        left--;
        right++;
      } else {
        break;
      }
    }
    
    return  right - left + 1;
  };

  int len = 0;
  for (int i = 1; i < s.size(); i++) {
    len = max(len, search(s, i, i);
    if(s[i - 1] == s[i]) {
      len = max(len, search(s, i - 1, i);
    }
  }

  return len;
}
}

*/

int longestPalindrome(string s) {
  unordered_map<char, int> hash_map;
  int ret = 0;

  for (auto t : s) {
    hash_map[t]++;
    if (hash_map[t] == 2) {
      ret += 2;
      hash_map.erase(t);
    }
  }

  return hash_map.size() != 0 ? ret + 1 : ret;
}


int main() {

  cout << longestPalindrome("abccccdd") << endl;

  return 0;
}



