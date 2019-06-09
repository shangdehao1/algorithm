/*
 * Third Maximum Number
 * 
 * Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
 * 
 * == Example 1: ==
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * == Example 2: ==
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 * 
 * == Example 3: ==
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 */

#include "common.h"

namespace sorted_method {

int thirdMax(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end())-nums.begin());
    return nums.size()>=3?nums[nums.size()-3]:nums.back();
}

}


int main () {

  vector<int> data{1,22, 2,3,23,1,2,2323,90};


  set<int> hash_map(data.begin(), data.end());

  for (auto i = hash_map.rbegin(); i != hash_map.rend(); i++) {
    std::cout << *i << endl;
  }




}


