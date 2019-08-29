/*

max depth in n-ary tree.

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


// ===================

int maxDepth(Node* root) {
  if (root == nullptr) {
    return 0;
  }

  int index = 0;

  for (auto child : root->children) {
    index = max(index, maxDepth(child));
  }

  return index + 1;
}



