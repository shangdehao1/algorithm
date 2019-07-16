/*
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 * 
 * Example:
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * Note:
 * 
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */

#include <iostream> 
#include <vector>
#include <unordered_set>

using namespace std;

// TODO better method ?

vector<int> singleNumber(vector<int>& nums) {
  unordered_set<int> xx; 
  for(auto temp : nums) {
    if(xx.find(temp) != xx.end()) {
      xx.insert(temp);
    } else {
      xx.erase(temp);
    }
  }
  return vector<int>{*(xx.begin()), *(xx.begin()++)};
}

// nice algorithm

vector<int> singleNumber(vector<int>& nums) {

  // get the xor of the two numbers we need to find
  int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

  // get its last set bit
  diff &= -diff;

  vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
  for (int num : nums) {
    if ((num & diff) == 0) { // the bit is not set
      rets[0] ^= num;
    } else { // the bit is set
      rets[1] ^= num;
    }
  }

  return rets;
}



int main() {

return 0;
}



