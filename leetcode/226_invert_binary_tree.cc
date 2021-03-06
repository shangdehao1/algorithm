/* * Invert a binary tree.  * * Example:
 * 
 * Input:
 * 
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * 
 * Output:
 * 
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * 
 * This problem was inspired by this original tweet by Max Howell:
 * 
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
 * 
 */

namespace pass_ac {

TreeNode* invertTree(TreeNode* root) {
  if(root == nullptr) return;

  swap(root->left, root->right);

  invertTree(root->left);
  invertTree(root->right);
  return root;
}

}




TreeNode* invertTree(TreeNode* root) {
  if (!root) {
    return root;
  }
  
  swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
}



