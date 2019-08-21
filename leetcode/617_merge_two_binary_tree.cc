/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

== Example 1: ==

Input: 

  Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \
        3   2                     1   3                        
       /                           \   \
      5                             4   7                  

Output: 

Merged tree:
       3
      / \
     4   5
    / \   \
   5   4   7

*/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// nice implement by dehao :)

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
   if (t1 == nullptr && t2 == nullptr) {
     return nullptr;
   }     

  TreeNode* root = new TreeNode(-1);

  if(t1 == nullptr && t2 != nullptr) {
    root->val = t2->val;
  }

  if(t1 != nullptr && t2 == nullptr) {
    root->val = t1->val;
  }

  if(t1 != nullptr && t2 != nullptr) {
    root->val = t1->val + t2->val;
  }

  root->left = mergeTrees(((t1 == nullptr) ? nullptr : t1->left), 
                           ((t2 == nullptr) ? nullptr : t2->left));

  root->right = mergeTrees(((t1 == nullptr) ? nullptr : t1->right), 
                           ((t2 == nullptr) ? nullptr : t2->right));

  return root;
}



int main() {
  return 0;
}


