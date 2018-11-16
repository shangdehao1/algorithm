/*
 * Maximum Depth of Binary Tree
 * 
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
 * return its depth = 3
 *
 */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// ====== method 1 : depth search ========
int depth_search(TreeNode* node) {
  if(node == nullptr) {
    return 0;
  }
  return max(depth_search(node->left), depth_search(node->right)) + 1;  
}

int maxDepth11(TreeNode* root) {
  return depth_search(root);
}


// === clean code : depth prior search =====

int maxDepth(TreeNode* root) {
  return root == nullptr ? 0 : (max( maxDepth(root->left), maxDepth(root->right)) + 1);
}



// ======  methodd 2 : width search =======

int maxDepth1(TreeNode* root) {
  queue<TreeNode*> current_queue;
  queue<TreeNode*> next_queue;
  int index = 0;
  if(root != nullptr) {
    current_queue.push(root);
  }
  while(!current_queue.empty()) {
    index++;
    while(!current_queue.empty()) {
      auto temp = current_queue.front();
      current_queue.pop();
      if(temp->left != nullptr) 
        next_queue.push(temp->left);
      if(temp->right != nullptr) 
        next_queue.push(temp->right);
    }
    swap(current_queue, next_queue);
  }
  return index;
}



// ======== method 3 :  =======



int main() {
  return 0;
}















