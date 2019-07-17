/*

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/



void depth_search(const vector<int>& data, int index, vector<int> temp, vector<vector<int>>& result) {
}




vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> result;

  depth_search(nums, index
        
}



void dfs(vector<vector<int>> &results, vector<int> &path, int index){
    if (index==(path.size()-1)) {
        results.push_back(path);
        return;
    }
    for (int i=index; i<path.size(); i++) {
        swap(path[index], path[i]);
        dfs(results,path, index+1);
        swap(path[index], path[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> results;
  dfs(results, nums, 0);
  return results;
}




