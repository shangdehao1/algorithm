/*
Merge Sorted Array

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

*/


#include "common.h"

namespace from_back_to_front {

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

  int index = nums1.size() - 1;
  int index1 = m - 1;
  int index2 = n - 1;

  while (index >= 0) {
    if (nums1[index1] >= nums2[index2] && index2 >= 0) {
      nums1[index--] = nums1[index1--];
    } else {
      nums1[index--] = nums2[index2--];
    }
  }
}

}


namespace sort_method {

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  for (int i = nums1.size() - 1, j = 0; j < nums2.size(); j++, i--) {
    nums1[i] = nums2[j];
  }

  sort(nums1.begin(), nums1.end());
}


}





int main() {

  vector<int> temp1{1,2,3,0,0,0};
  vector<int> temp2{2,5,6};

  merge(temp1, 3, temp2, 3); 

  output_container(temp1, "===");

  return 0;


}


