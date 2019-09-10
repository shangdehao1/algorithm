/*
 *
 *
 *
 * 445. Add Two Numbers II
 * Medium
 *
 * 840
 *
 * 113
 *
 * Favorite
 *
 * Share
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 */

// ==========================
//
// interesting error solution 
//
// intput1 : [7 4 2 3]
// intput2 : [5 6 4]
// the following solution : [12 8 8 3]
//

void depth_search(ListNode* l1, ListNode* l2) {
  if (l1 == nullptr && l2 == nullptr) {
    return;
  }

  if (l2 == nullptr) {
    return;
  }

  depth_search(l1->next, l2->next);
  
  l1->val += l2->val;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  auto temp1 = l1;
  auto temp2 = l2;
  while (temp1 != nullptr && temp2 != nullptr) {
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  if (temp1 == nullptr) {
    depth_search(l2, l1);
    return l2;
  }

  depth_search(l1, l2);
  return l1;
}



namespace ac_solution {


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  stack<ListNode*> stack1;
  stack<ListNode*> stack2;

  while(l1 != nullptr || l2 != nullptr) {
    if (l1 != nullptr) {
      stack1.push(l1);
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      stack2.push(l2);
      l2 = l2->next;
    }
  }

  ListNode dummy(-1);
  dummy.next = nullptr;

  int index = 0;

  while (!stack1.empty() || !stack2.empty()) {
    int temp1 = 0;
    int temp2 = 0;
    if (!stack1.empty()) {
      temp1 = stack1.top()->val; 
      stack1.pop();
    }

    if (!stack2.empty()) {
      temp2 = stack2.top()->val;
      stack2.pop();
    }

    auto sum = (temp1 + temp2 + index) % 10;
    index = (temp1 + temp2 + index) / 10;

    auto temp = new ListNode(sum);
    temp->next = dummy.next;
    dummy.next = temp;
  }

  if (index != 0) {
    auto temp = new ListNode(index);
    temp->next = dummy.next;
    dummy.next = temp;
  }


  return dummy.next;
}



} // namespace 




