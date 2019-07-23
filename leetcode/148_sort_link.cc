/*
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 *      Input: 4->2->1->3
 *      Output: 1->2->3->4
 * 
 * Example 2:
 * 
 *      Input: -1->5->3->4->0
 *      Output: -1->0->3->4->5
 */



  ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode dummy(-1); 
    ListNode* curr = &dummy;

    while(head1 || head2) {
      if (head1 && (!head2 || head1->val <= head2->val)) {
        curr = curr->next = head1 ; 
        head1 = head1->next;
      }

      if (head2 && (!head1 || head2->val < head1->val)) {
        curr = curr->next = head2 ; 
        head2 = head2->next;
      }
    }

    curr->next = nullptr;
    return dummy.next;
  }

   ListNode* sortList(ListNode* head) {
     if(!head || !head->next) { 
       return head;
     }

     ListNode* slow = head;
     ListNode* fast = head->next;

     while (fast && fast->next) {
       fast= fast->next->next;
       slow = slow->next;
     }

     ListNode* head2 = slow->next;
     slow->next = NULL;                 

     return merge(sortList(head) , sortList(head2));
   }










