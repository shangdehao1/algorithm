/*
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Input:
 * 
 *    1
 *   / \
 *  2   3
 *   \
 *    5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */

#include "common.h"

namespace depth_search_method {

void depth_search(TreeNode* node, string path, vector<string>& result) {
  if (node == nullptr) {
    return;
  }

  // note the first element !!!!
  path += (path.size() == 0 ? (to_string(node->val)) : ("->" + to_string(node->val)));  

  if (node->left == nullptr && node->right == nullptr) {
    result.push_back(path);
  }

  depth_search(node->left, path, result);
  depth_search(node->right, path, result);
} 

vector<string> binaryTreePaths(TreeNode* root) {
  vector<string> result; 

  depth_search(root, "", result);

  return result;
}

}





int main() {return 0;}




