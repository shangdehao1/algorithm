/*
 
 Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
 You may assume all four edges of the grid are surrounded by water.
 
 Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 
 Example 1:

 [[0,0,1,0,0,0,0,1,0,0,0,0,0],
  [0,0,0,0,0,0,0,1,1,1,0,0,0],
  [0,1,1,0,1,0,0,0,0,0,0,0,0],
  [0,1,0,0,1,1,0,0,1,0,1,0,0],
  [0,1,0,0,1,1,0,0,1,1,1,0,0],
  [0,0,0,0,0,0,0,0,0,0,1,0,0],
  [0,0,0,0,0,0,0,1,1,1,0,0,0],
  [0,0,0,0,0,0,0,1,1,0,0,0,0]]

 Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

 Example 2:

 [[0,0,0,0,0,0,0,0]]

 Given the above grid, return 0.

 Note: The length of each dimension in the given grid does not exceed 50.*

 */



// depth search method

void dfs(vector<vector<int>>& grid, int x_index, int y_index, int& results) {
    if(x_index < 0 || x_index > (grid.size()-1)) { // Note: bound
        return;
    }

    if( y_index < 0 || y_index > (grid[0].size()-1)) {
        return;
    }

    if(grid[x_index][y_index] == 2) {
        return;
    }

    if(grid[x_index][y_index] == 0) {
        grid[x_index][y_index] = 2;
        return;
    }

    if(grid[x_index][y_index] == 1) {
        results++;
        grid[x_index][y_index] = 2;
    }
    dfs(grid, x_index - 1, y_index, results);
    dfs(grid, x_index + 1, y_index, results);
    dfs(grid, x_index, y_index-1, results);
    dfs(grid, x_index, y_index + 1, results);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int results = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size() ; j++) {
            int temp = 0;
            if(grid[i][j] == 1) {
                dfs(grid, i, j, temp);
            }
            if(temp > results) {
                results = temp;
            }
        }
    }
    return results;
}




// depth search method 

namespace depth_search {

void depth_search(vector<vector<int>>& grid, int x, int y, int& results) {
  if (x >= grid.size() || y >=grid[0].size() || grid[x][y] != 1) return;
  
  results++;
  grid[x][y] = 2;
  depth_search(grid, x - 1, y, results);
  depth_search(grid, x + 1, y, results);
  depth_search(grid, x, y - 1, results);
  depth_search(grid, x, y + 1, results);
}



int maxAreaOfIsland(vector<vector<int>>& grid) {
  int result = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      int temp_ret = 0;
      depth_search(grid, i, j, temp_ret);
      result = temp_ret > result ? temp_ret : result;
    }
  }
  return result;
}





}

