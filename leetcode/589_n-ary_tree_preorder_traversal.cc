/*

n-tree 


*/


class Node {
public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val, vector<Node*> _children) {
      val = _val;
      children = _children;
  }
};



void depth_search(Node* root, vector<int>& result) {
  if (root == nullptr) {
    return;
  }

  result.push_back(root->val);

  for (auto c : root->children) {
    depth_search(c, result);
  }
}

vector<int> preorder(Node* root) {
  vector<int> result;
  depth_search(root, result);
  return result;
}



