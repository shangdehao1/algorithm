

namespace depth_method_1 {

void depth_search(TreeNode* root, vector<int>& result) {
  if (root == nullptr) return;

  depth_search(root->left, result);
  depth_search(root->right, result);
  result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
  vector<int> result;
  depth_search(root, result);
  return result;
}

}

namespace depth_method_2 {

vector<int> postorderTraversal(TreeNode* root) {
  if (root == nullptr) return {};

  auto left = postorderTraversal(root->left);
  auto right = postorderTraversal(root->right);
  left.insert(left.end(), right.begin(), right.end());
  left.push_back(root->val);
  return left;
}

}


// ================ stack ====================


 vector<int> postorderTraversal(TreeNode* root) {
   if (root == nullptr) return {}; 

     vector<int> results;

     TreeNode* curr = root;
     TreeNode* prev = nullptr;
     stack<TreeNode*> path;

     do {
       while (curr != nullptr) {
         path.push(curr);
         curr = curr->left;
       }

       prev = nullptr;

       while (!path.empty()) {
         curr = path.top();
         path.pop();

         if (curr->right == prev) {
           results.push_back(curr->val);
           prev = curr;
         } else {
           path.push(curr);
           curr = curr->right;
           break;
         }
       }
    } while(!path.empty());

    return results;
  }


