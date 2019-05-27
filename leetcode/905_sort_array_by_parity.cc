/*
 *   Sort Array By Parity
 * 
 *   Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
 * 
 *   You may return any answer array that satisfies this condition.
 * 
 *  
 *   == Example 1 ==
 * 
 *     Input: [3,1,2,4]
 * 
 *     Output: [2,4,3,1]
 * 
 *     The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 *  
 *   == Note ==
 * 
 *     1 <= A.length <= 5000
 *     0 <= A[i] <= 5000
 * 
 */

#include "common.h"

namespace method1 {

void print_output(vector<int>& data) {
  for(auto temp : data) {
    cout << temp << " ";
  }
  cout << endl;
}

vector<int> sortArrayByParity(vector<int>& A) {
  int left = 0;
  int right = A.size() - 1;

  while(left < right) {
    while(left < right && (A[left] & 1) == 0) {
      left++; 
    }

    while(left < right && (A[right] & 1) == 1) {
      right--;
    }
    
    if((A[left] & 1) == 1 && (A[right] & 1) == 0) {
      swap(A[left++], A[right--]);
    }
    print_output(A);
  
  }
  return A;
}

}


int main() {

  vector<int> temp{3, 1, 2, 4};

  vector<int> temp1{1,2,3,4,2,3,6,7,8,1,2,3,5,0};

  sortArrayByParity(temp1);

  return 0;
  
  
}



