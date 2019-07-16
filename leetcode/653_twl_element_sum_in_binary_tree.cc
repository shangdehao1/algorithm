/*
 * Given a Binary Search Tree and a target number, return true 
 * if there exist two elements in the BST such that their sum is equal to the given target.
 * 
 * == Example 1: ==
 * 
 * Input: 
 * 
 *         5
 *        / \
 *       3   6
 *      / \   \
 *     2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 *  
 * 
 * == Example 2: ==
 * 
 * Input: 
 * 
 *         5
 *        / \
 *       3   6
 *      / \   \
 *     2   4   7
 * 
 * Target = 28
 * 
 * Output: False
 * 
 */

#include "common.h"

// depth search method
namespace method3 {

void search(TreeNode* root, vector<int>& data) {
  if (root == nullptr) return;

  search(root->left, data);
  data.push_back(root->val);
  search(root->right, data);
}


bool findTarget(TreeNode* root, int k) {
  vector<int> data;
  search(root, data);

  int left = 0;
  int right = data.size() - 1;

  while (left < right) {
    if ((data[left] + data[right]) == k) {
      return true;
    } else if ((data[left] + data[right]) < k){
      left++;
    } else {
      right--;
    }
  }

  return false;
}


} // namespace 

namespace stack_method {


bool findTarget(TreeNode* root, int k) {
   // TODO stack
}


}


// =============== beautiful solution ========================================

// i should implement ++ and -- operation 

// do something....

namespace method2 {

class BSTIterator 
{
  stack<TreeNode*> s;
  TreeNode* node;
  bool forward;

public:

  BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward) {};

  bool hasNext() {
    return node != nullptr || !s.empty();
  }

  int next() {
    while (node || !s.empty()) {
      if (node) 
      {
        s.push(node);
        node = forward ? node->left : node->right;
      }
      else 
      {
        node = s.top();
        s.pop();
        int nextVal = node->val;
        node = forward ? node->right : node->left;
        return nextVal;
      }
    }
    return -1;  // never reach & not necessary
  }
};

bool findTarget(TreeNode* root, int k) {
  if (!root) return false;

  BSTIterator l(root, true);
  BSTIterator r(root, false);

  for (int i = l.next(), j = r.next(); i < j;) {
    int sum = i + j;
    if (sum == k) {
      return true;
    }
    else if (sum < k) {
      i = l.next();
    }
    else {
      j = r.next();
    }
  }

  return false;
}


}



int main() {
  return 0;
}





