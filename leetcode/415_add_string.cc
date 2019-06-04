/*
 * Add Strings
 * 
 * Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 * 
 * Note:
 * 
 * - The length of both num1 and num2 is < 5100.
 * - Both num1 and num2 contains only digits 0-9.
 * - Both num1 and num2 does not contain any leading zero.
 * - You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * 
 */

#include "common.h"

string addStrings(string num1, string num2) {

  // accumulate sum of two char
  auto sum_of_two_char = [] (char i, char j, char k) {
    int ret = (i - '0') + (j - '0') + (k - '0');
    return pair<char, char>{(ret / 10) + '0', (ret % 10) + '0'};
  };

  int index1 = num1.size() - 1;
  int index2 = num2.size() - 1;
  char k = '0';
  string result;

  while (index1 >= 0 || index2 >= 0 || k != '0') {
    char num_1 = (index1 < 0) ? '0' : num1[index1];
    char num_2 = (index2 < 0) ? '0' : num2[index2];

    auto ret = sum_of_two_char(num_1, num_2, k);
    k = ret.first;
    result = ret.second + (result);

    index1--;
    index2--;
  }

  return result;
}





int main() {

  int x = '5' - '0';
  cout << x << endl;

  char a = '0' + 5;
  cout << a << endl;

  cout << addStrings("123", "53201") << endl;


  string xx("12345");
  cout << xx[0] << endl;

  return 0;

}


