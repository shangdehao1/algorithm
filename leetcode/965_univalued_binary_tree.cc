/*

965. Univalued Binary Tree
Easy

228

37

Favorite

Share
A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

*/


bool depth_search(TreeNode* root, const int target) {
  if (root == nullptr) {
    return true;
  }

  if (root->val != target) {
    return false;
  }

  return depth_search(root->left, target) && depth_search(root->right, target);
}


bool isUnivalTree(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }

  return depth_search(root, root->val);
}


