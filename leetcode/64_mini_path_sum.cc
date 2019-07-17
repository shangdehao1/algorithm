/*
 * Minimum Path Sum
 * 
 * Given a m x n grid filled with non-negative numbers, 
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */

#include "common.h"

namespace depth_search {

void depth_search(vector<vector<int>>& grid, int x, int y, vector<int> path, vector<int>& result) {
  if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) {
    return;
  }

  path.push_back(grid[y][x]);

  if ((x == (grid[0].size() - 1)) && y == (grid.size() - 1)) {
    if (result.empty()) {
      result = path;
    } else {
      int ret1 = accumulate(path.begin(), path.end(), 0);
      int ret2 = accumulate(result.begin(), result.end(), 0);
      if (ret1 < ret2) {
        result = path;
      }
    }
    for (auto t : result) {
      cout << t << " ";
    }
    cout << endl;
    return;
  }

  depth_search(grid, x + 1, y, path, result);
  depth_search(grid, x, y + 1, path, result);
}

int minPathSum(vector<vector<int>>& grid) {
  vector<int> path;        
  vector<int> ret;        
  depth_search(grid, 0, 0, path, ret); 
  return accumulate(ret.begin(), ret.end(), 0);
}

}

// dp

int minPathSum(vector<vector<int>>& grid) {
  vector<vector<int>> data(grid.size(), vector<int>(grid[0].size(), INT_MAX));

  data[0][0] = grid[0][0];

  for (int i = 1; i < grid[0].size(); i++) {
    data[0][i] = data[0][i-1] + grid[0][i];
  }

  for (int i = 1; i < grid.size(); i++) {
    data[i][0] = data[i-1][0] + grid[i][0];
  }

  for (int i = 1; i < grid.size(); i++) {
    for (int j = 1; j < grid[0].size(); j++) {
      data[i][j] = min(data[i-1][j], data[i][j-1]) + grid[i][j];
    }
  }

  return data.back().back();
}




int main() {

  vector<vector<int>> temp{{1,2,5}, {3, 4, 1}};

  vector<vector<int>> temp1{{1,3,1}, {1, 5, 1}, {4, 2, 1}};

  cout << minPathSum(temp1) << endl;

  return 0;

}



