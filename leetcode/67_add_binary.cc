/*

Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

*/


#include "common.h"



string addBinary(string a, string b) {
  int index_a = a.size() - 1;
  int index_b = b.size() - 1;
  int carry = 0;

  string result;

  while (index_a >= 0 || index_b >= 0 || carry != 0) {
    int x = index_a >= 0 ? a[index_a--] - '0' : 0;
    int y = index_b >= 0 ? b[index_b--] - '0' : 0;

    result = (char)(x ^ y ^ carry + '0') + result;
    carry = (x + y + carry) >> 1;
  }

  return result;
}





int main() {


  return 0;

}
