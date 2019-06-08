/*

 Power of Four

Share
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

== Example 1: ==

Input: 16
Output: true

== Example 2: ==

Input: 5
Output: false

Follow up: Could you solve it without loops/recursion?

*/

bool isPowerOfFour(int num) {
  return (!(num & (num - 1))) && (num & 0x55555555);
}
