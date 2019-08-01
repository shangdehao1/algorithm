/*
 * 222. Count Complete Tree Nodes
 * 
 * Given a complete binary tree, count the number of nodes.
 * 
 * Note:
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 * 
 * Example:
 * 
 * Input: 
 * 
 *                           1
 *                          / \
 *                         2   3
 *                        / \  /
 *                       4  5 6
 */





int countNodes(TreeNode* root) {

  if (root == nullptr ) {
    return 0;
  }
        
  int left = 1;
  int right = 1;
        
  TreeNode* left_node = root->left;
  TreeNode* right_node = root->right;
        
  while (left_node != nullptr && right_node != nullptr) {
    left++;
    right++;
    left_node = left_node->left;
    right_node = right_node->right;
  }
        
  if (left_node == right_node) {
    return pow(2, left) - 1;
  }
        
  return 1 + countNodes(root->left) + countNodes(root->right);
}



