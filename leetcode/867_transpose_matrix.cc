
/*
 * Given a matrix A, return the transpose of A.
 * 
 * The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 * 
 * Example 2:
 * 
 * Input: [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 *  
 * 
 * Note:
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 *
 */

#include <vector> 

using namespace std;

// time : n*n 
// space :  n*n
vector<vector<int>> transpose(vector<vector<int>>& A) 
{
  vector<vector<int>> results;

  for (int i = 0; i < A[0].size(); i++) {
    vector<int> temp(A.size(), 0);
    results.push_back(temp);
  }

  for(int i = 0; i < A.size(); i++) {
    for(int j = 0; j < A[0].size(); j++) {
      results[j][i] = A[i][j];
    }
  }
  return results;
}

vector<vector<int>> transpose(vector<vector<int>>& A) {

}

// ===========================

// for m*n matrix , m must be equal to n. 

namespace method3 {

vector<vector<int>> transpose(vector<vector<int>>& A) 
{
  if (A.size() < 2) return A;

  for (int i = 0; i < A.size(); i++) {
    for (int j = i + 1; j < A[0].size(); j++) {
      swap(A[i][j], A[j][i]);
    }
  }
  return A;
}

}

/*

class Solution(object):
    def transpose(self, A):
        return zip(*A)
*/












