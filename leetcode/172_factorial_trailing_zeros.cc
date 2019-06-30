/*
 * Factorial Trailing Zeroes
 * 
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * 
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * Example 2:
 * 
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 */

#include "common.h"


// TODO

namespace method1{

int trailingZeroes(int n) {
  return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5); 
}

}

namespace method2 {

int trailingZeroes(int n) {

}

}


int main() {
  trailingZeroes(30);
  return 0;
}

