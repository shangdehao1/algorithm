/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

*/

namespace new_space_method {

int removeDuplicates(vector<int>& nums) {
  if (nums.size() < 2) return nums;
  vector<int> temp{nums[0]};
  for (auto t : nums) {
    if (temp.back() != t) {
      temp.push_back(t);
    } 
  }
  swap(nums, temp);
  return nums.size();
}

}

namespace two_index_method {

int removeDuplicates(vector<int>& nums) {
  int index = 0;
  bool is_erase = false;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[index] != nums[i]) {
      nums[++index] = nums[i];
      is_erase = true;
    }
  }

  if (index != nums.size()) {
    nums.erase(nums.begin() + index + 1, nums.end());
  }

  return nums.size();
}

}
