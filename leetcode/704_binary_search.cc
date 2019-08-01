



int search(vector<int>& nums, int target) {
  
  int left = 0;
  int right = nums.size() - 1;

  while (left <= right) {
    int mid = (left + right) >> 1;

    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      right = mid -1;
    } else {
      left = mid + 1;
    }
  }
        
  return -1;
}



int binary_search(vector<int>& nums, int target, int left, int right) {
  if (left > right) {
    return -1;
  }

  int mid = (left + right) >> 1;
  if (nums[mid] == target) {
    return mid;
  } 

  if (nums[mid] > target) {
    return binary_search(nums, target, left, mid - 1);
  }

  return binary_search(nums, target, mid + 1, right);
} 


int search(vector<int>& nums, int target) {
  return binary_search(nums, target, 0, nums.size() - 1);
}


