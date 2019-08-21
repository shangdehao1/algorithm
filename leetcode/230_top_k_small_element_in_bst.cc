/*
 * Kth Smallest Element in a BST
 * 
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * 
 * Example 1:
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * 
 *    3
 *   / \
 *  1   4
 *   \
 *    2
 * 
 * Output: 1
 * Example 2:
 * 
 * Input: root = [5, 3, 6, 2, 4, null, null, 1], k = 3
 * 
 *        5
 *       / \
 *      3   6
 *     / \
 *    2   4
 *   /
 *  1
 * 
 * Output: 3
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */

namespace depth_search {


// stack method....
int kthSmallest(TreeNode* root, int& k) {
  TreeNode* curr = root;
  TreeNode* prev = nullptr;
  stack<TreeNode*> path;

  while (!path.empty() || curr != nullptr) {
    if (curr != nullptr) {
      while (curr != nullptr) {
        path.push(curr);
        curr = curr->left;
      }
    } else {
      curr = path.top();
      path.pop();
      if (--k == 0) return curr->val;
      curr = curr->right;
    }
  }
  
  return -1;
}


int kthSmallest(TreeNode* root, int& k) {
  if (root) {
    int x = kthSmallest(root->left, k);
    return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
  }
}


}
















