/*
 * Lowest Common Ancestor of a Binary Search Tree
 * 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * 
 * == Example 1: ==
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 *
 *          6
 *         / \
 *        /   \
 *       /     \
 *      2       8 
 *     / \     / \
 *    /   \   /   \
 *   0     4 7     9
 *        / \
 *       /   \
 *      3     5
 *
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * == Example 2: ==
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 * 
 */

namespace based_on_recursive_method {

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr) return nullptr;

  if (root == p) return p;

  if (root == q) return q;

  auto result1 = lowestCommonAncestor(root->left, p, q);
  auto result2 = lowestCommonAncestor(root->right, p, q);
        
  if (result1 != nullptr && result2 != nullptr) return root;

  if (result1 == nullptr && result2 != nullptr) return result2;

  if (result1 != nullptr && result2 == nullptr) return result1;
  
  return nullptr;
}

}


namespace based_on_stack {

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
}

}




























