/*
Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include "common.h"

unordered_map<char, char> hash_map{{')', '('}, {']', '['}, {'}', '{'}};

bool isValid(string s) {

  stack<char> stack;

  for (auto t : s) {
    if (hash_map.find(t) == hash_map.end()) {
      stack.push(t);
    } else {
      if (stack.size() == 0) return false;
      if (stack.top() != t) return false; 
      stack.pop();
    }
  }

  return stack.empty();
}

int main() {}

