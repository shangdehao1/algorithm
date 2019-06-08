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
{
  auto remove_element_using_last_point = [] (ListNode* last_node) {
    assert(last_node->next != nullptr);
    //delete last_node->next; // should not delete this element at leetcode environment.
    last_node->next = last_node->next->next;
  };

  ListNode dummy(INT_MIN);
  dummy.next = head;
  ListNode* index = &dummy;

  while (index->next != nullptr) {
    if (index->next->val == val) {
      remove_element_using_last_point(index);
    } else {
      index = index->next;
    }
  }

  return dummy.next;
}

