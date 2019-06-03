/*
 * Given two arrays, write a function to compute their intersection.
 * 
 * == Example 1: ==
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 * == Example 2: == 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 *
 * Note:
 * 
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * Follow up:
 * 
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 * 
*/

namespace method1 {

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> hash_map;
  vector<int> result;

  for (auto t : nums1) {
    hash_map[t]++;
  }

  for (auto t : nums2) {
    if (hash_map.find(t) != hash_map.end()) {
      if (hash_map[t] > 0) {
        hash_map[t]--;
        result.push_back(t); 
      }
    }
  }
  return result;
}

}


// sort + binary search

namespace method2 {

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());

  auto binary_search = [] (vector<int>& data, int target) {
    int left = 0;
    int right = data.size() - 1;
    int mid = -1;

    while(left <= right) {
      mid = (left + right) / 2;
      if (data[mid] == target) {
        return mid;
      } else if (data[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  };

  vector<int> ret;

  for (auto t : nums1) {
    int index = binary_search(nums2, t);
    if (index != -1) {
      ret.push_back(nums2[index]);
      nums2.erase(nums2.begin() + index);
    }
  }

  return ret;
}

}








