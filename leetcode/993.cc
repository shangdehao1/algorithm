/*

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

*/

#include "common.h"


namespace method1 {

typedef std::pair<int, TreeNode*> result;

void search(TreeNode* root, int x, int y, int depth, TreeNode* p, result& result_x, result& result_y) {
      if(root == nullptr) return;

      if(result_x.first != -1 && result_y.first != -1) {
        return;
      }

      if(root->val == x) {
        result_x.first = depth;
        result_x.second = p;
      } else if(root->val == y) {
        result_y.first = depth;
        result_y.second = p;
      }

      search(root->left, x, y, depth + 1, root, result_x, result_y);
      search(root->right, x, y, depth + 1, root, result_x, result_y);
    }

}

bool isCousins(TreeNode* root, int x, int y) {
  result result_x{-1, nullptr};
  result result_y{-1, nullptr};

  search(root, x, y, 0, nullptr, result_x, result_y);
     
  if(result_x.first == result_y.first && result_x.second != result_y.second) {
    return true;
  }

  return false;
}

}



int main () 
{
return 0;

}

