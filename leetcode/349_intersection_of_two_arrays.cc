/*
 * Given two arrays, write a function to compute their intersection.
 * 
 * == Example 1: ==
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 * == Example 2: ==
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 *
 * Note:
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 */

#include "common.h"

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> map1(nums1.begin(), nums1.end());
  unordered_set<int> map2(nums2.begin(), nums2.end());

  vector<int> result;

  for (auto t : map1) {
    if (map2.count(t)) {
      result.push_back(t);
    }    
  }
  return result;
}

int main() {
  vector<int> xx{1,2,3,4,5};
  unordered_set<int> map(xx.begin(), xx.end());

  for(auto t : map) {
    cout << t << endl;
  }

  return 0;
}

