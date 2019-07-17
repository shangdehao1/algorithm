/*
combination Sum III

Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.

 == Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]

 == Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]

*/

#include "common.h"


void depth_search(vector<vector<int>>& result, set<int>& temp, int index, int n, int low) {

 if (index == 0) {
    int temp_sum = accumulate(temp.begin(), temp.end(), 0);
    if (temp_sum == n) {
      vector<int> ret(temp.begin(), temp.end());
      if (find(result.begin(), result.end(), ret) == result.end()) {
        result.push_back(ret);
      }
    }
    return;
 }

 for (int i = low; i <= 9; i++) {
   if (temp.find(i) == temp.end()) {
     temp.insert(i);
     depth_search(result, temp, index - 1, n, low + 1);
     temp.erase(i);
   }
  }
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> ret;
  set<int> temp;
  depth_search(ret, temp, k, n, 1);
  
  return ret;
}



int main () {

  set<int> hash_map;
  hash_map.insert(1);
  hash_map.insert(2);
  hash_map.insert(3);

  vector<int> xxx(hash_map.begin(), hash_map.end());

  assert(xxx.size() == 3);


}



