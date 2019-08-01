/*
 * 143. Reorder List
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * 
 * Example 1:
 * 
 *   Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 *   Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 * 
 */


void reorderList(ListNode* head) {
  ListNode dummy(-1); 
  dummy.next = head;

  ListNode* head1 = &dummy;
  ListNode* head2 = &dummy;
  
  while (head2 != nullptr && head2->next != nullptr) {
    head1 = head1->next;
    head2 = head2->next->next;
  }

  ListNode* temp = head1->next;
  head1->next = nullptr; 
  while (temp != nullptr) {
    auto next = temp->next;
    temp->next = head1->next;
    head1->next = temp;
    temp = next;
  }

  
  temp = head1;
  head2 = head1->next;
  temp->next = nullptr;

  head1 = dummy.next;
  head = &dummy;

  while (head1 != nullptr || head2 != nullptr) {
    if (head1 != nullptr) {
      head->next = head1; 
      head1 = head1->next;
      head = head->next;
    }

    if (head2 != nullptr) {
      head->next = head2;
      head2 = head2->next;
      head = head->next;
    }
  }

  head->next = nullptr;
  head1 = dummy.next;
}






void reorderList(ListNode *head) 
{
    if (!head || !head->next) return;
    
    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = nullptr;
    
    p2 = head2->next;
    head2->next = nullptr;
    while (p2) {
      p1 = p2->next;
      p2->next = head2;
      head2 = p2;
      p2 = p1;
    }
    
    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
    
}


















