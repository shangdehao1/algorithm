

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


// ==================

namespace pass_ac {


void depth_search(Node* root, vector<vector<int>>& result, int level) {
  if (root == nullptr) {
    return;
  }

  if (result.size() < (level + 1)) {
    result.push_back(vecotr<int>{});
  }

  result[level].push_back(root->val);

  for (auto child : root->children) {
    depth_search(child, result, level + 1);
  }
}


vector<vector<int>> levelOrder(Node* root) {
  vector<vector<int>> result;
  depth_search(root, result, 0);
  return result;
}

}













