/*
 * 86. Partition List
 * 
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * Example:
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 * 
 */



ListNode* partition(ListNode* head, int x) {

  ListNode node1(-1);
  ListNode node2(-1);

  ListNode* ptr1 = &node1;
  ListNode* ptr2 = &node2;
        
  while (head != nullptr) {
    if (head->val < x) {
      ptr1->next = head;
      ptr1 = ptr1->next;
    } else {
      ptr2->next = head;
      ptr2 = ptr2->next;
    }
    head = head->next;
  }

  ptr1->next = node2.next;
  ptr2->next = nullptr;

  return node1.next;
}


















