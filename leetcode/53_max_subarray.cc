/*
 * Maximum Subarray
 * 
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 * 
 */

namespace method_1 {

int maxSubArray(vector<int>& nums) {
  int left_max = 0;
  int result = INT_MIN;

  for (int i = 0; i < nums.sie(); i++) {
    left_max = max(left_max + nums[i], nums[i]);
    result = left_max > result ? left_max : result; 
  }

  return result;
}


int maxSubArray(vector<int>& nums) {

}


int maxSubArray(vector<int>& nums) {
        
}
