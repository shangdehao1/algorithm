/*
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: 
 * Starting with any positive integer, replace the number by the sum of the squares of its digits, 
 * and repeat the process until the number equals 1 (where it will stay), 
 * or it loops endlessly in a cycle which does not include 1. 
 * Those numbers for which this process ends in 1 are happy numbers.
 * 
 * == Example: 
 * 
 * == Input: 19
 * 
 * Output: true
 *
 * Explanation: 
 *
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 02 = 1
 */

#include "common.h"

bool isHappy(int n) 
{
  unordered_set<int> hash_map;

  auto break_down_digit = [] (int num, vector<int>& result) {
    while (num != 0) {
      result.push_back(num % 10); 
      num = num / 10;
    }
  };
    
  auto power_of_array = [] (const vector<int>& data) {
    uint64_t ret = 0;
    for (auto t : data) {
      ret += (t * t);
    }
    return ret;
  };

  while (n > 9) 
  {
    hash_map.insert(n);

    vector<int> digits;
    break_down_digit(n, digits);
    n = power_of_array(digits);

    if (hash_map.find(n) != hash_map.end()) {
      std::cout << "==== " << n << endl;
      return false;
    } else {
      std::cout << "---- " << n << endl;
    }
  } 

  std::cout << "final : " << n << endl;
  return n == 1;     
}



int main () {

  cout << isHappy(19) << endl;;
  return 0;


}
