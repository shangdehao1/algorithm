/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * 
 * Example 1:
 * 
 * Input: [3,2,3]
 * Output: 3
 * Example 2:
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 */

#include "common.h"

// ========= sort method ==============

namespace method1 {

int majorityElement(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  return nums[nums.size() / 2];
}

}

// ========== binary search method based on quick sorting thinking ==============

namespace method2 {


int quick_adjust(vector<int>& data, int first, int last) {
  if(first >= last) {
    return first;
  }

  int left = first;
  int right = last;

  int target = data[first];

  while(left < right) {
    while(left < right && target <= data[right]) {
      right--;
    }

    if (left < right) {
      data[left++] = data[right];
    }

    while (left < right && target >= data[left]) {
      left++;
    }

    if (left < right) {
      data[right--] = data[left];
    }
  }
  data[left] = target;
  
  std::cout << "==============" << left << std::endl;

  output_container(data, "one time  quick adjust : ");

  return left;
}


int quick_method(vector<int>& data, int first, int last, int k) {
  if (first >= last) {
    return data[first];
  }

  int temp = quick_adjust(data, first, last);
  assert(temp >= first && temp <= last);

  std::cout << "first : temp : last : k : " << endl;

  std::cout << first << " " << temp << " " << last << " " << k <<std::endl;

  output_container(data, "===" );

  if (temp == k) {
    return data[k];
  } else if (temp < k) {
    return quick_method(data, temp + 1, last, k - temp - 1);
  } else {
    return quick_method(data, first, temp - 1, k);
  }
}


int majorityElement(vector<int>& nums) {
  if(nums.size() < 3) {
    return nums[0];
  }

  return quick_method(nums, 0, nums.size() - 1, nums.size() / 2);
}

}


namespace method3 {

int majorityElement(vector<int>& nums) {
}

}




namespace method4 {

int majorityElement(vector<int>& nums) {
}

}



namespace method5 {

int majorityElement(vector<int>& nums) {
}

}



namespace method6 {

int majorityElement(vector<int>& nums) {
}

}


int main() {
 vector<int> ttt{2,2,1,1,1,2,2};

 std::cout <<  method2::majorityElement(ttt) << std::endl;

 return 0;
}



