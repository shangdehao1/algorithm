
/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.


Example 1:

        1
      /   \
     0     1
    / \   / \
   0   1 0   1

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
Accepted
9,579
Submissions
18,393
*/

#include "common.h"

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

namespace method1{

long long get_value(vector<int>& stack) {
  int index = 0;
  long long result = 0;

  for(auto i = stack.rbegin(); i != stack.rend(); i++, index++) {
    result += ((*i) << index);
    std::cout << *i << " "<< "result : " << result << std::endl;
  }

  return result;
}

void search_sum(TreeNode* root, vector<int>& stack, long long& result) {
  if(root == nullptr) return;

  stack.push_back(root->val);

  if(root->left == nullptr && root->right == nullptr) {
    result += get_value(stack);
  }
  
  search_sum(root->left, stack, result);
  search_sum(root->right, stack ,result);

  stack.pop_back();
}

int sumRootToLeaf(TreeNode* root) {
  vector<int> stack;
  long long result;

  search_sum(root, stack, result);
    
  return result;
}

}


int main() {

  using namespace method2;

  cout << map[0] << endl;
  cout << map[3] << endl;
    

  vector<int> temp;
  temp.push_back(1);
  temp.push_back(0);
  temp.push_back(0);

  for(auto i = temp.begin(); i != temp.end(); i++) {
    std::cout << *i << " ";
  }

  cout <<endl;

//  cout << get_value(temp) << endl;


}



