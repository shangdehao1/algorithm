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



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        for(int i = 0; i < A.size(); i++ ){
            if(i == (A.size() - 1)) {
                return i;
            }
            if(A[i] > A[i+1]) {
               return i; 
            }
        }
    }
};


class Solution {
public:
    int binary_search(vector<int> &A, int front, int end) {
        if ((end - front)  < 2) return 0;

        int peak = (end - front)/2 + front;

        if (A.at(peak-1) < A.at(peak) && A.at(peak) > A.at(peak+1)) {
            return peak;
        }

        if (A.at(peak-1) < A.at(peak) && A.at(peak) < A.at(peak+1) ) {
            return binary_search(A, peak, A.size()-1);
        }

        return binary_search(A, front, peak);
    }

    int peakIndexInMountainArray(vector<int>& A) {
        if (A.size() < 3) return 0; 
        return binary_search(A, 0, A.size()-1);
    }
};

namespace method1 {

int binary_search(vector<int>& A, int left, int right) {
  if (right - left < 2) {
    return -1;
  }

  int index = (right + left) / 2;

  if (A[index - 1] < A[index] && A[index] > A[index + 1]) {
    return index;
  }

  if (A[index - 1] < A[index] && A[index] < A[index + 1]) {
    return binary_search(A, index, right);
  }

  return binary_search(A, left, index);
}


int peakIndexInMountainArray(vector<int>& A) {
  if (A.size() < 3) {
    return -2;
  }
  return binary_search(A, 0, A.size() - 1); 
}

}

int main() {
    return 0;
}





