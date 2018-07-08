/*
Given a binary tree, return the inorder traversal of its nodes' values.
*/

// method 1 : depth prior search
//
void dps(TreeNode* node, vector<int>& results) {
    if(node == nullptr) {
        return;
    }
    if(node->left != nullptr) {
        dps(node->left, results);
    }

    results.push_back(node->val);

    if(node->right != nullptr) {
        dps(node->right, results);
    }
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> results;
    dps(root, results);
    return results;
}


// method 2 : stack
//
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> results;
    TreeNode* prev = nullptr;
    TreeNode* curr = root;
    stack<TreeNode*> path;

    while(curr != nullptr || !path.empty()) {
        if(node != nullptr) {
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
//
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



















