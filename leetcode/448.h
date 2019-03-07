/*
 * 448. Find All Numbers Disappeared in an Array
 * 
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 */


// cool !!!!!

class Solution {
 public:
  vector<int> find_dispeared_number(vector<int>& nums) {
    int len = nums.size();
    for(int i=0; i<len; i++) {
      int m = abs(nums[i])-1; // index start from 0
      nums[m] = nums[m]>0 ? -nums[m] : nums[m];
      for(int j = 0; j < len; j++) {
        std::cout << nums[j] << " ";
      }
      std::cout<<endl;
    }
    vector<int> res;
    for(int i = 0; i<len; i++) {
      if(nums[i] > 0) {
       res.push_back(i+1);
       std::cout << i+1<<" ";
      }
    }
    std::cout << std::endl;
    return res;
 }
};


