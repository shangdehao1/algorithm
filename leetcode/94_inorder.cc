/*
Given a binary tree, return the inorder traversal of its nodes' values.
*/

// =========== method 1 : depth prior search

namespace depth_search_method {

namespace method1 {

  void depth_search(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
      
    depth_search(root->left, result);
    result.push_back(root->val);
    depth_search(root->right, result);
  }
  
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    depth_search(root, result);
    return result;
  }

}

namespace method2 {

vector<int> inorderTraversal(TreeNode *root) {
  if (root == nullptr) return {};
  
  auto left = inorderTraversal(root->left);
  left.push_back(root->val);
  auto right = inorderTraversal(root->right);
  left.insert(left.end(), right.begin(), right.end());
  return left;
}

}

}

// ============ method 2 : stack ===============

vector<int> inorderTraversal(TreeNode *root) {
  if (root == nullptr) return {}; 

  vector<int> results;
  TreeNode* prev = nullptr;
  TreeNode* curr = root;
  stack<TreeNode*> path;

  while(curr != nullptr || !path.empty()) {
    if(curr != nullptr) {
      path.push(curr);
      curr = curr->left;
    } else {
      curr = path.top();
      path.pop();
      results.push_back(curr->val);
      curr = curr->right;
    }
  }

  return results;
}

// method 3: index

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> results;
    TreeNode* prev = nullptr;
    TreeNode* curr = root;

    while( curr != nullptr) {
        if(curr->left == nullptr) {
            results.push_back(curr->val);
            prev = curr;
            curr = curr->right;
        } else {
            TreeNode* temp = curr->left;
            while(temp->right != nullptr && temp->right != curr) {
                temp = temp->right;
            }
            
            if(temp->right == nullptr) {
                temp->right = curr;
                prev = curr;
                curr = curr->left;
            } else {
                temp->right = nullptr;
                results.push_back(curr->val);
                prev = curr;
                curr = curr->right;
            }
        }
    }
    return results;
}










vector<int> inorderTraversal(TreeNode* root) {
  vector<int> result;
  TreeNode* prev = nullptr;
  TreeNode* curr = root;
  stach<TreeNode*> path;

  while (!path.empty() || curr != nullptr) {
    if (curr != nullptr) {
      while (curr != nullptr) {
        path.push(curr);
        curr = curr->left;
      }
    } else {
      curr = path.top();
      path.pop();
      result.push(curr->val); 
      curr = curr->right;
    }
  }

  return result;

}








