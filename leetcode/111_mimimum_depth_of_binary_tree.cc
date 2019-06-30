/*
 * Minimum Depth of Binary Tree
 * 
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * return its minimum depth = 2.
 * 
 */

namespace depthd_search {

int minDepth(TreeNode* root) {
  if (root == nullptr) return 0;

  int left = minDepth(root->left);
  int right = minDepth(root->right);

  if (left == 0 && right == 0) return 1;
  
  if ((left * right) == 0) 
    return left == 0 ? (right + 1) : (left + 1);

  return 1 + min(left, right);
}

}

namespace depth_search {

int depth(TreeNode* root) {
  if (root == nullptr) return INT_MAX;

  if (root->left == nullptr && root->right == nullptr) return 1;

  return min(depth(root->left), depth(root->right)) + 1;
}

int minDepth(TreeNode* root) {
  if (root == nullptr) return 0;
  return depth(root);
}


}







