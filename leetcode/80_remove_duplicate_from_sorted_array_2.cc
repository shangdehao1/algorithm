/*
 * 80. Remove Duplicates from Sorted Array II
 * 
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 *   Given nums = [1,1,1,2,2,3],
 * 
 *   Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 * 
 *   It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 *   Given nums = [0,0,1,1,1,1,2,3,3],
 * 
 *   Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
 * 
 *   It doesn't matter what values are set beyond the returned length.
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 */

#include "common.h"


int removeDuplicates(vector<int>& nums) {
  if (nums.size() < 2) return nums.size();

  uint32_t index = 0;

  for (int i = 2; i < nums.size(); i++) {
    if (nums[index] != nums[i]) {
      nums[index+2] = nums[i];
      index++;
    }
  }

  nums.resize(index + 2);
  return index + 2;
}


// ================================ general method ===============================


int remove_duplicate(vector<int>& nums, int k) {
  if (nums.size() < k) return nums.size();

  uint32_t index = 0;

  for (int i = k; i < nums.size(); i++) {
    if (nums[index] != nums[i]) {
      nums[index+k] = nums[i];
      index++;
    }
  }

  nums.resize(index + k);
  return index + k;
}


int remove_deplicate(vector<int>& nums, int k) {
  return remove_duplicate(nums, k);
}


int main () {
  vector<int> data1{1,1,3,3,3,4,4,4,4,5,5,5,5,8,8,8,9,10,11,11,13,13,15};
  
  vector<int> result1{1,3,4,5,8,9,10,11,13,15};
  vector<int> result2{1,1,3,3,4,4,5,5,8,8,9,10,11,11,13,13,15};
  vector<int> result3{1,1,3,3,3,4,4,4,5,5,5,8,8,8,9,10,11,11,13,13,15};

  {
    vector<int> test1 = data1;
    remove_deplicate(test1, 1);
    assert(test1 == result1);
  }
  

  {
    vector<int> test2 = data1;
    remove_deplicate(test2, 2);
    assert(test2 == result2);
  }


  {
    vector<int> test3 = data1;
    remove_deplicate(test3, 3);
    assert(test3 == result3);
  }

  return 0;
}































