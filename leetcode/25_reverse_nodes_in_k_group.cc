/*
 * 25 : Reverse Nodes in k-Group
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be changed.
 *
 */

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(-1);
        preheader->next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while(cur = cur->next) 
            num++;
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return preheader->next;
    }
};

/*
 * -1 -> 1 -> 2 -> 3 -> 4 -> 5
 *  |    |    |    | 
 *  pre  cur  nex  tmp
 *
 * -1 -> 2 -> 1 -> 3 -> 4 -> 5
 *  |         |    |    | 
 *  pre       cur  nex  tmp
 *
 * -1 -> 3 -> 2 -> 1 -> 4 -> 5
 *  |              |    |    | 
 * pre            cur  nex  tmp
 *
 */

ListNode* reverseKGroup(ListNode* head, int k) {
  if (head == nullptr || k == 1) {
    return  head;
  }

  ListNode dummy(-1);
  dummy.next = head; 
  ListNode* pre = &dummy;
  ListNode* cur = head;
  ListNode* next;

  uint32_t link_size = 0;
  while (cur != nullptr) {
    cur = cur->next; 
    link_size++;
  }

  while (link_size >= k) {
    cur = pre->next;
    next = cur->next;
    for (int i = 1; i < k; i++) {
      auto temp = next->next;
      next->next = pre->next;
      pre->next = next;
      cur->next = temp; // i speet many time to fix this bug...
      next = temp;
    }
    pre = cur;
    link_size -= k;
  }
  return dummy.next;
}



