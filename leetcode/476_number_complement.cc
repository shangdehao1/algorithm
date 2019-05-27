/*
 * 
 *  Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
 *  
 *  Note:
 *  The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 *  You could assume no leading zero bit in the integer’s binary representation.
 *  
 *  Example 1:
 *  
 *  Input: 5
 *  Output: 2
 *  
 *  Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 *  
 *  Example 2:
 *  
 *  Input: 1
 *  Output: 0
 *  
 *  Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 *  
 */
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

/*
num          = 00000101 --> 11111010
mask         = 11111000 --> 00000111
                            00000010

~mask & ~num = 00000010 

*/

int findComplement(int num) 
{
  // reverse
  unsigned mask = ~0;

  // obtain mask
  while (num & mask) mask <<= 1;

  // &
  return ~mask & ~num;
}



int main() {
  bitset<8> temp(~0);
  cout << temp.count() << endl;
  cout << (11111 & 0) << endl;

  unsigned mask = ~0;

  for(int i = 0; i < 32; i++) {
    cout << bitset<64>((mask <<= 1)).to_string() << endl;
  }


  return 0;
}

