/*
 * Remove Linked List Elements
 * 
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
 */


#include "common.h"


ListNode* removeElements(ListNode* head, int val) 
  ListNode node(1);
  node.next = head;

  head = &node;

  while (head->next != nullptr) {
    if (head->next->val == val) {
      head->next = head->next->next;
    } else {
      head = head->next;
    }
  }

  return node.next;
}




