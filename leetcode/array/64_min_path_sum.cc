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

void depth_search(vector<vector<int>>& grid, int x, int y, vector<int> path, vector<int>& result) {
  if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) {
    return;
  }

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
    return;
  }

  path.push_back(grid[x][y]);

  depth_search(grid, x + 1, y, path, result);
  depth_search(grid, x, y + 1, path, result);
}

int minPathSum(vector<vector<int>>& grid) {
  vector<int> path;        
  vector<int> ret;        
  depth_search(grid, 0, 0, path, ret); 
  return accumulate(ret.begin(), ret.end(), 0);
}



int main() {


  return 0;

}



