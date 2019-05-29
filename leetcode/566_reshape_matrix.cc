/*
 * In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
 * 
 * You're given a matrix represented by a two-dimensional array, and two positive integers r and c 
 * representing the row number and column number of the wanted reshaped matrix, respectively.
 * 
 * The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
 * 
 * If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
 * 
 * == Example 1: ==
 * 
 *       [[1,2],
 *        [3,4]]
 * 
 *       r = 1, c = 4
 * 
 * Output: 
 * 
 *     [[1,2,3,4]]
 * 
 * == Example 2: == 
 * 
 *       [[1,2],
 *        [3,4]]
 * 
 *       r = 2, c = 4
 * 
 * Output: 
 * 
 *       [[1,2],
 *        [3,4]]
 * 
 * Note:
 * The height and width of the given matrix is in range [1, 100].
 * The given r and c are all positive.
 */

#include "common.h"

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
  vector<vector<int>> result;

  auto put_element = [r, c, &nums, &result](int i, int j) {
    if(result.size() == 0 || result.back().size() == c) {
      vector<int> temp;
      result.push_back({});
    }
    //result.back().push_back(nums[i][j]);
    result.back().push_back(1);
  };


  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums[0].size(); j++) {
      put_element(j, j);
    }
  }

  return result;
}



int main() {
  vector<vector<int>> temp = {{1,2,3,4}, {5,6,7,8}, {9, 10,11,12}};

  for(int i = 0; i < temp.size(); i++) {
    for(int j = 0; j < temp[0].size(); j++) {
      std::cout << temp[i][j] << " ";
    }
    std::cout <<endl;
  }

  vector<vector<int>> xxx;
  vector<int> t1, t2;
  xxx.push_back(t1);
  xxx.push_back(t2);
  cout << xxx.size() << endl;

  xxx.back().push_back(1);
  xxx.back().push_back(1);
  xxx.back().push_back(1);
  cout << xxx.back().size() << endl;

  
  auto t = matrixReshape(temp, 4, 3);

  for(int i = 0; i < t.size(); i++) {
    for(int j = 0; j < t[0].size(); j++) {
      std::cout << t[i][j] << " ";
    }
    std::cout <<endl;
  }

  
}


