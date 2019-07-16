/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * Example 1:
 * 
 * Input: 1->1->2
 * Output: 1->2
 * Example 2:
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 */

#include "common.h"

// clean codes..... :)

// In leetcode environments, don't delete nodes. 
// otherwise, can't pass all test case.

ListNode* deleteDuplicates(ListNode* head) {

  ListNode* ret = head;

  while (head != nullptr && head->next != nullptr) {

    if (head->val == head->next->val) {
      head->next = head->next->next;
      // delete head->next;
    } else { 
      head = head->next;
    }
  }
  
  return ret;
}



int main() {
  return 0;
}



