/*
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * Input: [3,0,1]
 * Output: 2
 * Example 2:
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 * 
 */

int missingNumber(vector<int>& nums) {
  int ret = 0;
  for(int i = 0; i < nums.size(); ++i) {
    ret ^= i;
    ret ^= nums[i];
  }
  return ret ^= nums.size();
}


namespace method1 {

int missingNumber(vector<int>& nums) {
  int result = 0;
  for (int i = 0; i < nums.size(); i++) {
    result ^= i;
    result ^= nums[i];
  }
  return result ^ nums.size();
}



}

