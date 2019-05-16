/*

Given a Binary Search Tree and a target number, return true 
if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 

        5
       / \
      3   6
     / \   \
    2   4   7

Target = 9

Output: True
 

Example 2:

Input: 

        5
       / \
      3   6
     / \   \
    2   4   7

Target = 28

Output: False

*/

#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// general method
class Solution_1 {
public:
  bool findTarget(TreeNode* root, int k) {
    vector<int> results;      
    search(results, root);
  
    int index_front = 0;
    int index_back = results.size() - 1;
    
    while(index_front < index_back) {
      int temp = results[index_front] + results[index_back];

      if(temp == k) {
        return true;
      } else if(temp < k) {
        index_front++;
      } else {
        index_back--;
      }
    }
    return false;
  }

  void search(vector<int>& results, TreeNode* root) {
    if(root == nullptr) return;

    if(root-> left != nullptr) {
      search(results, root->left);
    }

    results.push_back(root->val);

    if(root->right != nullptr) {
      search(results, root->right);
    }
  }    
    
};


// =============== beautiful solution ========================================

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

class Solution 
{
public:
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
};

int main() {
  return 0;
}





