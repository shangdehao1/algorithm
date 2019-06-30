/*
 *  Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *  
 *  Example:
 *  
 *  Input: 38
 *  Output: 2 
 *  Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 *               Since 2 has only one digit, return it.
 *  Follow up:
 *  Could you do it without any loop/recursion in O(1) runtime?
*/

#include "common.h"

// stl : accumulate(begin(), end(), 0);

int addDigits(int num) {

  auto get_digits = [](int num) {
    vector<int> result;
    while(num != 0) {
      result.emplace_back(num % 10);
      num = num / 10;
    }
    return result;
  };
        

  while(0 < num && num < 10) {
    auto digits = get_digits(num);
    num = accumulate(digits.begin(), digits.end(), 0);
  }

  return num;
}

int main() {

  addDigits(12345);

  int tt = 12345;
  cout << tt / 10 << endl;
  tt = tt / 10;
  cout << tt / 10 << endl;
  tt = tt / 10;
  cout << tt / 10 << endl;
  tt = tt / 10;
  cout << tt / 10 << endl;
  tt = tt / 10;
  cout << tt / 10 << endl;
  tt = tt / 10;
   
  return 0;

}


