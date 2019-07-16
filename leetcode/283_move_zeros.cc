/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Note:
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */




void moveZeroes(vector<int>& nums) {

  int index = 0;

  for(int i = 0; i < nums.size(); i++) {
    if(nums[i] != 0) {
      nums[index++] = nums[i];
    }
  }

  while(index < nums.size()) {
    nums[index++] = 0; 
  }
}



// this method is very nice, but i still don't know how to maintain relative orders.
void moveZeroes(vector<int>& nums) {
  if (nums.size() < 2) return;

  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    while (left < right && nums[left] != 0) {
      left++;
    } 
    
    while (left < right && nums[right] == 0) {
      right--;
    }

    if (nums[left] == 0 && nums[right] != 0) {
      swap(nums[left++], nums[right--]);
    }
  }
}



