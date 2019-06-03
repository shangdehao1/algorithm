/*
 * 
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * For example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 * 
 * 
 */

#include "common.h"

namespace based_on_queue {

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
  auto travel_level = [](queue<TreeNode*>& current_queue, queue<TreeNode*>& next_queue, vector<int>& current_result) 
  {
    while(!current_queue.empty()) {
      auto current_node = current_queue.front();
      current_queue.pop();
      current_result.push_back(current_node->val);
      if (current_node->left != nullptr) {
        next_queue.push(current_node->left);
      }
      if (current_node->right != nullptr) {
        next_queue.push(current_node->right);
      }
    }
  };

  vector<vector<int>> result;
  queue<TreeNode*> current_queue;

  if (root != nullptr) {
    current_queue.push(root);
  }

  while(!current_queue.empty()) 
  {
    vector<int> current_result; 
    queue<TreeNode*> next_queue;

    travel_level(current_queue, next_queue, current_result);

    result.insert(result.begin(), current_result);
    swap(next_queue, current_queue);
  }

  return result;
}

}


namespace based_on_depth_search {


}

int main() {return 0;}

