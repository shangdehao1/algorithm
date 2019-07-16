/*
 * Let's call an array A a mountain if the following properties hold:
 * 
 * A.length >= 3
 * There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
 * Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
 * 
 * Example 1:
 * 
 * Input: [0,1,0]
 * Output: 1
 * 
 * Example 2:
 * 
 * Input: [0,2,1,0]
 * Output: 1
 * 
 * Note:
 * 
 * 3 <= A.length <= 10000
 * 0 <= A[i] <= 10^6
 * A is a mountain, as defined above.
 * 
*/

#include "common.h"




// ================ binary search ===================

namespace method1 {

int peakIndexInMountainArray(vector<int>& A) {
  int left = 0; 
  int right = A.size() - 1;

  while ((right - left) > 1) {
    int mid = (left + right) >> 1;

    if ((A[mid - 1] < A[mid]) && (A[mid] > A[mid + 1])) { 
      return mid;
    } else if (A[mid - 1] > A[mid] && A[mid + 1] < A[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  assert((right - left) <= 1);

  return A[left] > A[right] ? left : right;
}

}

namespace method2 {

int binary_search(const vector<int>& data, int left, int right) {

  if (right - left < 1) {
    return data[left] > data[right] ? left : right;
  }

  int mid = (left + right) >> 1;
  if (data[mid - 1] < data[mid] && data[mid] > data[mid + 1]) {
    return mid;
  }

  if (data[mid - 1] < data[mid] && data[mid] < data[mid + 1]) {
    return binary_search(data, mid + 1, right);
  }

  return binary_search(data, left, mid - 1);
}

int peakIndexInMountainArray(vector<int>& A) {
  return binary_search(A, 0, A.size() - 1);
}

}




// ======================================

int main() {
    return 0;
}





