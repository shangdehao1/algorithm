/*
 * Reverse Linked List II
 * 
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
 */



ListNode* reverseBetween(ListNode* head, int m, int n) {
  ListNode dummy(-1);
  dummy.next = head;

  ListNode* front = &dummy; // position : m - 1
  ListNode* curr = &dummy; // position : m
  ListNode* end = &dummy; // position : n + 1 

  while (m-- > 1) {
    front = front->next;
  }

  curr = front->next;

  while (n-- >= 0) {
    end = end->next; 
  }

  while (curr != end) {
    auto next = curr->next;

    if (curr == front->next) { // the first element need special handing....
      curr->next = end;
    } else {
      curr->next = front->next;
    }
    front->next = curr;

    curr = next;
  }

  return dummy.next;
}


