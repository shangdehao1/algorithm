/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 *  Input: [1,null,2,3]
 *
 *    1
 *     \
 *      2
 *    /
 *  3
 *
 *  Output: [1,2,3]
 *
 */


// ===== method 1 : depth prior search based param referrence ============

namespace method1 {

void pre_order_traversal_tree(TreeNode* node, vector<int> &results) {
  if(node == nullptr) {
    return;
  }

  results.push_back(node->val);
  pre_order_traversal_tree(node->left, results);
  pre_order_traversal_tree(node->right, results);
}

vector<int> preorderTraversal(TreeNode *root ) {
     vector<int> results;
     pre_order_traversal_tree(root, results);
     return results;
}

}

// ========== method 2 ===============

namespace method2 {

vector<int> preorderTraversal(TreeNode *root ){
  if (root == nullptr) return vector<int>{};

  auto left = preorderTraversal(root->left);
  auto right = preorderTraversal(root->right);

  left.insert(left.begin(), root->val);
  left.insert(left.end(), right.begin(), right.end());
  return left;
}

}


// ==== method 2 : stack  ===================

vector<int> preorderTraversal( TreeNode *root ) {
    if (root == nullptr) return {};

    vector<int> results;
    TreeNode* curr = root; 
    TreeNode* prev = nullptr;

    stack<TreeNode*> path;
    path.push(curr);

    while(!path.empty()) {
        curr = path.top();
        path.pop();

        results.push_back(curr->val); 

        if(curr->right != nullptr) path.push(curr->right);
        if(curr->left != nullptr) path.push(curr->left);
    }
    return results;
}


// === method 3 : index

vector<int> preorderTraversal( TreeNode *root ) {
    vector<int> results;
    TreeNode* curr = root;
    TreeNode* pre = nullptr;

    while(curr != nullptr) {
        if(curr->left == nullptr) {
            results.push_back(curr->val);
            pre = curr;
            curr = pre->right;
        } else {
            TreeNode* temp = curr->left; 
            // namely, get the right node
            while(temp->right != nullptr && temp->right != curr) {
                temp = temp->right;
            }

            // namely, no touch left sub-tree
            if(temp->right == nullptr) {
                results.push_back(curr->val);
                temp->right = curr; // index
                pre = curr;
                curr = currr->left;
            }else{  
                temp->right = nullptr; // de-index
                pre = curr;
                curr = curr->right;
            }
        }
    }

    return results;
}

// ============================

