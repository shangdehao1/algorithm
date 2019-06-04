/*
 * Search Insert Position
 *
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * Example 2:
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * Example 3:
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * Example 4:
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
*/

namespace iterator_method {

/*
 *  no matter what situation, the last is 
 * 
 * 
 *       left right
 *        |    |
 *        v    v
 *  xxx  yyy  zzz  kkk
 *             
 * 
 * 
 * 
 */

// still can't totally understand index....
int searchInsert(vector<int>& nums, int target) {

  int left = 0;
  int right = nums.size() - 1;

  while (left <= right) {
    int mid = (left + right) >> 1;
    
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target){
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left; // why left can cover all cases ?      
}


} // namespace 


namespace depth_search {

int depth_search(const vector<int>& data, int left, int right, int target) {
  if (left > right) {
    return left;
  }

  int mid = (left + right) >> 1;
  if (data[mid] == target) {
    return mid;
  }

  if (data[mid] > target) {
    return depth_search(data, left, mid -1, target);
  }

  return depth_search(data, mid + 1, right, target);
} 


int searchInsert(vector<int>& nums, int target) {
  return depth_search(nums, 0, nums.size() - 1, target);
}


} // namespace

