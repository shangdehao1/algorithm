/*
 * 19. Remove Nth Node From End of List
 * 
 * 
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * 
 * Example:
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 */



ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode dummy(-1);
  dummy.next = head;

  ListNode* slower = &dummy;
  ListNode* faster = &dummy;
  while (n-- > 0) {
    faster = faster->next;
  }
  
  while (faster->next != nullptr) {
    slower = slower->next;
    faster = faster->next;
  }

  slower->next = slower->next->next;

  return dummy.next;
}




