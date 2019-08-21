/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree 
 * in which the depth of the two subtrees of every node never differ by more than 1.
 * 
 * Example:
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 * 
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 * 
 */

#include "common.h"

namespace pass_ac {

TreeNode* traverse_create_bst(vector<int>& data, int left, int right) {
  if (left > right) {
    return nullptr;
  }

  int mid = (left + right) / 2;
  TreeNode* root = new TreeNode(data[mid]); 

  root->left = traverse_create_bst(data, left, mid - 1); 
  root->right = traverse_create_bst(data, mid + 1, right);

  return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
  return traverse_create_bst(data, 0, nums.size() - 1);
}

}



