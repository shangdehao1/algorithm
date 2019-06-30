/*
 * Palindrome Linked List
 * 
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * Input: 1->2
 * Output: false
 * Example 2:
 * 
 * Input: 1->2->2->1
 * Output: true
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */

#include "common.h"

// time n,  space n

namespace space_method {

bool isPalindrome(ListNode* head) {
  deque<int> result;
  while(head != nullptr) {
    result.push_back(head->val);
    head = head->next;
  }

  while (result.size() >= 2) {
    if (result.back() != result.front()) {
      return false;
    }
    result.pop_back();
    result.pop_front();
  }
  return true;
}


}

// TODO : better depth search method ????
namespace depth_search {

bool depth_search(ListNode* head, int index) {
  if (index < 2) return true;

  ListNode* end = head;
  for (int i = 0; i < index - 1; i++) {
    end = end->next;
  }
  assert(end != nullptr);

  return head->val == end->val && depth_search(head->next, index - 2);
}

bool isPalindrome(ListNode* head) {
  int index = 0;
  ListNode* temp = head;

  while (head != nullptr) {
    head = head->next;
    index++;
  }

  return depth_search(temp, index);
}
  
}



int main() {
  return 0;
}
