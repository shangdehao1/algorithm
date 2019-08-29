/*


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

  for (auto child : root->children) {
    depth_search(child, result);
  }
  result.push_back(root->val);
}

vector<int> postorder(Node* root) {
  vector<int> result;
  depth_search(root, result);
  return result;
}


