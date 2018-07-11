/*
 * Given two binary trees and imagine that when you put one of them to cover the other, 
 *       some nodes of the two trees are overlapped while the others are not.
 * 
 * You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, 
 *     then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
 * Input: 
 * 
 *     Tree 1                     Tree 2                  
 *       1                         2                             
 *      / \                       / \
 *     3   2                     1   3                        
 *    /                           \   \
 *  5                             4   7                  
 * 
 * Output: 
 * Merged tree:
 *          3
 *         / \
 *        4   5
 *       / \   \
 *      5   4   7
 * 
*/

/*
 *   Definition for a binary tree node.
 *   struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *    };
 * 
 */



class Solution {
public:

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr && t2 == nullptr) {
           return nullptr; 
        }

        if(t1 == nullptr && t2 != nullptr) {
            TreeNode* node = new TreeNode(t2->val);
            node->left = mergeTrees(nullptr, t2->left);
            node->right = mergeTrees(nullptr, t2->right);
            return node;
        }

        if(t1 != nullptr && t2 == nullptr) {
            TreeNode* node = new TreeNode(t1->val);
            node->left = mergeTrees(t1->left, nullptr);
            node->right = mergeTrees(t1->right, nullptr);
            return node;
        }

        TreeNode* node = new TreeNode(t1->val + t2->val);
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
        return node;
    }
};


