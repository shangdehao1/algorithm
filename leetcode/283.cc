/*
  Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

  Example:

  Input: [0,1,0,3,12]
  Output: [1,3,12,0,0]
  Note:
  
  You must do this in-place without making a copy of the array.
  Minimize the total number of operations.

*/

#include "common.h"

using namespace std;


// general method
void moveZeroes_0(vector<int>& nums) {
  if(nums.size() == 0) {
    return;
  }

  vector<int> temp(std::move(nums));
  assert(nums.size() == 0);
    
  for(auto t : temp) {
    if(t != 0) {
      nums.push_back(t);
    }
  } 

  while(temp.size() != nums.size()) {
    nums.push_back(0);
  }
}


// two index method
void moveZeroes_1(vector<int>& nums) {
  int index_front = 0;
  int index_back = 0;

  while(index_back < nums.size()) {
    if(nums[index_back] != 0) {
      nums[index_front] = nums[index_back];
      index_front++;
      index_back++;
    } else {
      index_back++;
    }
  }

  while(index_front < nums.size()) {
    nums[index_front++] = 0;
  }
}












