/*
Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false

Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false

Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

*/

namespace method_base_method {

bool isPalindrome(int x) {
  if (x < 0) return false;

  auto break_down_number = [] (int num) {
    vector<int> result;
    while (num > 0) {
      result.push_back(num % 10);
      num = num / 10;
    }
    return result;
  };

  vector<int> digits = break_down_number(x);
  int left = 0;
  int right = digits.size() - 1;

  while (left < right) {
    if (digits[left--] != digits[right--]) {
      return false;
    }
  }
        
  return true;
}

}




