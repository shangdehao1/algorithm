/*

Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?

*/

namespace general_method {

bool isPowerOfThree(int n) {
  while (n >= 3) {
    if ((n % 3) != 0) {
      return false;
    }
    n = n / 3;
  }
  return n == 1;
}

}


// TODO better method ???? 

namespace bit_method {

bool isPowerOfThree(int n) {
}


}




