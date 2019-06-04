/*
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * 
 * Example 1:
 * 
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * Return true.
 * 
 * Example 2:
 * 
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 *        1
 *       / \
 *      2   2
 *     / \
 *    3   3
 *   / \
 *  4   4
 * Return false.
 */


namespace depth_search {

int depth_search(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }    

  int left_high = depth_search(root->left);
  if (left_high == -1) {
    return -1;
  }

  int right_high = depth_search(root->right);
  if (right_high == -1) {
    return -1;
  }
  
  if (abs(right_high - left_high) > 1) {
    return -1;
  }

  return max(right_high, left_high) + 1;
}

bool isBalanced(TreeNode* root) {
  return depth_search(root) != -1;      
}

}
