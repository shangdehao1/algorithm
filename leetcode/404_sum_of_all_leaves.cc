/*
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 * 
 */

#include "common.h"

int binary_search(TreeNode* root, bool is_left) {
  if (root == nullptr) return 0;
  
  if (root->left == nullptr && root->right == nullptr && is_left) return root->val;

  return binary_search(root->left, true) + binary_search(root->right, false);
}


int sumOfLeftLeaves(TreeNode* root) {
  return binary_search(root, false);
}

int main(){return 0;}
