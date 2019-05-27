/*
 * In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.
 * 
 * Return the element repeated N times.
 * 
 * == Example 1:
 * 
 * Input: [1,2,3,3]
 * Output: 3
 *
 * == Example 2:
 * 
 * Input: [2,1,2,5,3,2]
 * Output: 2
 *
 * == Example 3:
 * 
 * Input: [5,1,5,2,5,3,5,4]
 * Output: 5
 *  
 * 
 * Note:
 * 
 * 4 <= A.length <= 10000
 * 0 <= A[i] < 10000
 * A.length is even
 * 
 */


// ======== method 1 =============

/*
 * The intuition here is that the repeated numbers have to appear either next to each other (A[i] == A[i + 1]), 
 * or alternated (A[i] == A[i + 2]).
 * 
 * The only exception is sequences like [2, 1, 3, 2]. 
 * In this case, the result is the last number, so we just return it in the end. This solution has O(n) runtime.
 */


int repeatedNTimes(vector<int>& A) {
  for (auto i = 0; i < A.size() - 2; ++i)
    if (A[i] == A[i + 1] || A[i] == A[i + 2]) return A[i];
  return A[A.size() - 1]; 
}

// ========== method 2 ==============

/*
 * Another interesting approach is to use randomization. 
 * If you pick two numbers randomly, there is a 25% chance you bump into the repeated number. 
 * So, in average, we will find the answer in 4 attempts, thus O(4) runtime.
 */

int repeatedNTimes(vector<int>& A, int i = 0, int j = 0) {
  while (A[i = rand() % A.size()] != A[j = rand() % A.size()] || i == j);
  return A[i];
}


int repeatedNTimes(vector<int>& A) {
  for(int i = 0; i < A.size() - 2; i++) {
    if(A[i] == A[i + 1] && A[i] == A[i + 2])
      return A[i];
    return A[A.size() -1];
  }
}


int repeatedNTimes(vector<int>& A) {
  for(int i = 0; i < A.size() - 1; i++) {
    if (A[i] == A[i+1] || A[i] == A[i+2]) {
      return A[i];
    }
  }
  return A.back();
}
