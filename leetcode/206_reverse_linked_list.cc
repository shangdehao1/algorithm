/*
 * Reverse Linked List
 * Example:
 * 
 * Input: 1->2->3->4->5->NULL
 * 
 * Output: 5->4->3->2->1->NULL
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 
 */

#include "common.h"

  
// orinial list : 1 --> 2 --> 3 --> 4 --> 5
//
//                    head   node
//                      |     |
//                      v     v
// recursive    : 1 --> 2     5 --> 4 --> 3
//                      |                 |
//                      --------->---------
//
//
namespace method1 {

ListNode* reverseList(ListNode* head) {
  if (head == nullptr || head->next == nullptr) 
    return head;      

  ListNode* node = reverseList(head->next);

  head->next->next = head;
  head->next = nullptr;

  return node;
}

}

namespace method2 {

ListNode* reverseList(ListNode* head) {
  ListNode temp(-1); 

  while(head != nullptr) {
    auto next = head->next; 

    head->next = temp.next;
    temp.next = head;

    head = next;
  }

  return temp.next;
}

}



ListNode* reverseList(ListNode* head) {
  ListNode dummy(-1);
  dummy.next = nullptr;

  while(head != nullptr) {
    auto next = head->next;
    head->next = dummy.next;
    dummy.next = head;
    head = next;
  }

  return dummy.next;
}




ListNode* reverseList(ListNode* head) {

}




