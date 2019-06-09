/*
 * Reverse Integer
 * 
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 *  == Example 1: ==
 * 
 * Input: 123
 * Output: 321
 * 
 *  == Example 2: ==
 * 
 * Input: -123
 * Output: -321
 * 
 *  == Example 3: ==
 * 
 * Input: 120
 * Output: 21
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 * 
 * 
 */

#include "common.h"

// ==================================


int reverse(int x) {
  long long y = abs((long long)x);

  long long ret = 0;
  while (y > 0) {
    ret = ret * 10 + y % 10;
    y = y / 10;
  }

  if (ret > INT_MAX || ret < INT_MIN) return 0;

  return (x > 0) ? ret : -ret;
}






