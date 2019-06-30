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

namespace search_deplicate_method {

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

  while (n != 1) 
  {
    vector<int> digits;
    break_down_digit(n, digits);
    n = power_of_array(digits);

    if (hash_map.find(n) != hash_map.end()) {
      return false;
    } else {
      hash_map.insert(n);
    }
  } 

  return true;     
}

}

namespace nice_method {

int my_digit(int n) {
    int sum = 0;
    while (n != 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
        slow = my_digit(slow);
        fast = my_digit(my_digit(fast));
    } while(slow != fast);

    if (slow == 1) {
        return 1;
    }

    return 0;
}


}


int main () {

  cout << isHappy(19) << endl;;
  return 0;


}
