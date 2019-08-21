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

#include "common.h"

// cool !!!!!

namespace method1 {

};

namespace method2 {
  
vector<int> find_dispeared_number(vector<int>& nums) 
{
  for (int i = 0; i < nums.size(); i++) {
    int index = abs(nums[i]) - 1;
    nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
  } 

  vector<int> result;
  for (int i = 0; i < nums.size(); i++) {
    if ( nums[i] > 0) {
      result.emplace_back(i + 1);
    }
  }

  return result;
}

}


int main() {
  vector<int> data{4,3,2,7,8,2,3,1};

  auto ret = method2::find_dispeared_number(data);

  output_container(ret, "results : ");

  return 0;
}


