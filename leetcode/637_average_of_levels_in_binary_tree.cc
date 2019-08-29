


// TODO better method.

void depth_search(TreeNode* root, vector<vector<int>>& result, int level) {
  if (root == nullptr) {
    return;
  }

  if (result.size() < (level + 1)) {
    result.push_back(vector<int>{});
  }

  result[level].push_back(root->val);

  depth_search(root->left, result, level + 1);
  depth_search(root->right, result, level + 1);
}


vector<double> averageOfLevels(TreeNode* root) {
  vector<vector<int>> result;

  depth_search(root, result, 0);

  vector<double> ret;
  for (auto i : result) {
    double temp = 0;
    for (auto j : i) {
      temp += j;
    }
    temp = temp / i.size();
    ret.push_back(temp);
  }
  return ret;
}


