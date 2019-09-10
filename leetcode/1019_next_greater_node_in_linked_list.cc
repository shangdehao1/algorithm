









int depth_search(ListNode* head, vector<int>& result, set<int>& index) {
  if (head == nullptr) {
    return INT_MIN;
  }

  auto back = depth_search(head->next, result, index);

  if (back == INT_MIN) {
    result.push_back(0);
  } else {
    result.push_back(back);
  }
    
  int temp = 0;
  for (auto i : index) {
    if (i >= head->val) {
      temp = i;
      break;
    }
  }

  index.insert(head->val);
  result.push_back(temp);

  return temp;
} 

  
vector<int> nextLargerNodes(ListNode* head) {
  if (head == nullptr) {
    return vector<int>{};
  }
  
  vector<int> result;
  set<int> index;
  depth_search(head, result, index);
  reverse(result.begin(), result.end());
    
  return result;
}





