/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/


// general binary search method 

namespace general_binary_search {


int binary_search(const vector<int>& data, int target, bool is_low) {
  int left = 0;
  int right = data.size() - 1;

  while (left <= right) {
    int mid = (left + right) >> 1;

    if (is_low && (mid - 1) >= 0 && data[mid-1] < data[mid] && data[mid] == target) {
      return mid;
    } else if (is_low && mid == 0 && data[mid] == target) {
      return 0;
    } else if (!is_low && (mid + 1) < data.size() && data[mid] < data[mid+1] && data[mid] == target) {
      return mid; 
    } else if (!is_low && (mid + 1) == data.size() && data[mid] == target) {
      return data.size() - 1;
    } else if (is_low && data[mid] >= target) {
      right = mid - 1;
    } else if (is_low && dat[mid] < target) {
      left = mid + 1;
    } else if (!is_low && data[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {

  return vector<int>{binary_search(nums, target, true), binary_search(nums, target, false)};
}

}


namespace method2 {

int binary_search_low(vector<int>& data, int target) {

  if (!data.empty() && data.front() == target) {
    return 0;
  }

  int left = 0;
  int right = data.size() - 1;

  while (left <= right) {
    int mid = (left + right) >> 1;

    if ((mid - 1) >= 0 && data[mid -1] < data[mid] && data[mid] == target) {
      return mid; 
    } else if (data[mid] >= target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

int binary_search_high(vector<int>& data, int target) {
  if (!data.empty() && data.back() == target) {
    return data.size() - 1;
  }

  int left = 0;
  int right = data.size() - 1;

  while (left <= right) {
    int mid = (left + right) >> 1;
    if ((mid + 1) < data.size() && data[mid] < data[mid+1] && data[mid] == target) {
      return mid;
    } else if (data[mid] <= target) {            
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {

  return vector<int>{binary_search_low(data, target), binary_search_high(data, target)};
}


}










