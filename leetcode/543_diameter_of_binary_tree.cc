 



int depth_search(TreeNode* root, int& result) {
  if (root == nullptr) {
    return 0;
  }

  int left = depth_search(root->left, result);
  int right = depth_search(root->right, result);
  if ((left + right) > result) {
    result = left + right;
  } 
  
  return max(left, right) + 1;
}




int diameterOfBinaryTree(TreeNode* root) {        
  int result = 0;
  depth_search(root, result);
  return result;
}






