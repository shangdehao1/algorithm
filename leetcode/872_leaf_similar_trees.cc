/*



*/

namespace pass {

void depth_search(TreeNode* root, vector<int>& result) {
  if (root == nullptr) {
    return;
  }

  if (root->left == nullptr && root->right == nullptr) {
    result.push_back(root->val);
    return;
  }

  depth_search(root->left, result);
  depth_search(root->right, result);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
  vector<int> result1;
  vector<int> result2;
  depth_search(root1, result1);
  depth_search(root2, result2);
  return result1 == result2;       
}


}



