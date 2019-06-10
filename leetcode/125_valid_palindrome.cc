/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*/

#include "common.h"

// two function...
// transfrom(source.begin(), source.end(), destination.begin(), ::tolower)
// isalnum(char)


namespace general_method {

bool isPalindrome(string s) {

  if (s.empty()) return true;

  auto filter_1 = [] (string& data) {
    string ret;
    int j = 0;
    for (int i = 0; i < data.size(); i++) {
      if (('A' <= data[i] && data[i] <= 'Z')) {
        data[j++] =  data[i] + ('a' - 'A'); 
      } else if (('0' <= data[i] && data[i] <= '9')|| ('a' <= data[i] && data[i] <= 'z')) { 
        data[j++] = data[i];
      }
    }
    data.erase(data.begin() + j, data.end());
    return ret;
  };

  filter_1(s);

  cout << s << endl;

  int left = 0;
  int right = s.size() - 1;

  while (left < right) {
    if (s[left++] != s[right--]) {
      return false;
    }
  }

  return true;
}

}

namespace std_method {


bool isPalindrome(string s) {
  if (s.empty()) return true;

  int left = 0; 
  int right = s.size() - 1;

  transform(s.begin(), s.end(), s.begin(), ::tolower);

  while (left < right) {
    if (!isalnum(s[left])) {
      left++;
      continue;
    }

    if (!isalnum(s[right])) {
      right--;
      continue;
    }

    if (s[left++] != s[right--]) {
      return false;
    }
  }

  return true;
}


}



int main() {

  isPalindrome("A man, a plan, a canal: Panama");
  isPalindrome("A man");

  return 0;

}
