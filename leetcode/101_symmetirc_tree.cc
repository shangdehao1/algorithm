/*
 * Symmetric Tree
 * 
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 *        1
 *       / \
 *      2   2
 *     / \ / \
 *    3  4 4  3
 *  
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 *        1
 *       / \
 *      2   2
 *       \   \
 *        3   3
 *  
 * 
 * Bonus points if you could solve it both recursively and iteratively.
 */

namespace depth_search {

bool depth_search (TreeNode* node1, TreeNode* node2) {
  if (node1 == nullptr && node2 == nullptr) return true;

  if (node1 == nullptr || node2 == nullptr) return false;

  if (node1->val != node2->val) return false;

  return depth_search(node1->left, node2->right) && depth_search(node1->right, node2->left);
}


bool isSymmetric(TreeNode* root) {
  if (root == nullptr) return true;       
  return depth_search(root->left, root->right);
}

}


namespace stack_method {


bool isSymmetric(TreeNode* root) {
}

}






