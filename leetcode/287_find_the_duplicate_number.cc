/*
Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

  Input: [1,3,4,2,2]
  Output: 2


Example 2:

  Input: [3,1,3,4,2]
  Output: 3

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n*n).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

namespace stupid_method {

int findDuplicate(vector<int>& nums) {
  set<int> hash_map;
  for (auto temp : nums) {
    if (hash_map.find(temp) != hash_map.end()) {
      return temp;
    }
    hash_map.insert(temp);
  }
  return -1;    
}

} // 



namespace hash_method {


int findDuplicate(vector<int>& nums) {
  vector<int> hash_map(nums.size(), 0);
  for (auto temp : nums) {
    if (hash_map[temp] != 0) {
      return temp;
    }
    hash_map[temp]++;
  }
  return -1;
}

}



// TODO TODO TODO TODO

int findDuplicate3(vector<int>& nums)
{
  if (nums.size() > 1)
  {
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast)
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    fast = 0;
    while (fast != slow)
    {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
  return -1;
}









