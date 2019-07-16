/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * 
 * == Example: ==
 * 
 * Input: 1 --> 2 --> 4,
 *        1 --> 3 --> 4
 * 
 * Output: 1 --> 1 --> 2 --> 3 --> 4 --> 4
 * 
 */

#include "common.h"

// use total new list 

namespace method1 {

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
  ListNode dummy(-1); 
  ListNode* current_node = &dummy;

  while (l1 != nullptr && l2 != nullptr) {
    ListNode* node = new ListNode(-1);
    if (l1->val <= l2->val) {
      node->val = l1->val;
      l1 = l1->next;
    } else {
      node->val = l2->val;
      l2 = l2->next;
    }
    current_node->next = node;
    current_node = node;
  }        

  if (l1 != nullptr) {
    current_node-> next = l1; 
  }

  if (l2 != nullptr) {
    current_node->next = l2;
  }

  return dummy.next;
}

} // namespace



namespace method2 {

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode dummy(-1); 
  ListNode* current_node = &dummy;

  while(l1 != nullptr && l2 != nullptr) {
    if (l1->val <= l2->val) {
      current_node->next = l1;
      l1 = l1->next;
    } else {
      current_node->next = l2;
      l2 = l2->next;
    }
    current_node = current_node->next;
  }

  if (l1 != nullptr) {
    current_node->next = l1;
  } 

  if (l2 != nullptr) {
    current_node->next = l2;
  }

  return dummy->next;
}

} // namespace


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  ListNode node;
  ListNode* ptr = &node;

  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val <= l2->val) {
      ptr->next = l1;
      l1 = l1->next;
    } else {
      ptr->next = l2;
      l2 = l2->next;
    }
    ptr = ptr->next;
  }

  if (l1 != nullptr) {
    ptr->next = l1;
  } else {
    ptr->next = l2;
  }

  return node->next;
}

int main() {

  return 0;

}

