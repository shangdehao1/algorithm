/*
 * K-th Largest Element in an Array
 * 
 * Find the kth largest element in an unsorted array. 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 *   Input: [3,2,1,5,6,4] and k = 2
 *   Output: 5
 * 
 * Example 2:
 * 
 *   Input: [3,2,3,1,2,4,5,5,6] and k = 4
 *   Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

namespace pass_ac {

int binary_search(vector<int>& data, int first, int last, const int index) {
  if (first > last) {
    return -1;
  }

  int left = first;
  int right = last;
  int target = data[left];

  while (left < right) {
    while (left < right && target <= data[right]) right--;
    if (left < right) data[left++] = data[right];

    while (left < right && data[left] <= target) left++;
    if (left < right) data[right--] = data[left];
  }

  data[left] = target;
  
  if (left == index) {
    return data[index];
  } else if (index < left) {
    return binary_search(data, first, left - 1, index);
  } else {
    return binary_search(data, left + 1, last, index);
  }

  return -1;
}

int findKthLargest(vector<int>& nums, int k) {
  return binary_search(nums, 0, nums.size() - 1, nums.size() - k);
}

}







