/*
 * 61. Rotate List
 * 
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 * 
 * Example 1:
 * 
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * Example 2:
 * 
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
 * 
 */

ListNode* rotateRight(ListNode* head, int k) {
  if(k == 0 || head == nullptr || head->next == nullptr) return head;

  ListNode* slower = head;
  ListNode* faster = head;

  auto temp = head;
  int len = 0;
  while (temp != nullptr) {
    len++;
    temp = temp->next;
  }

  k = k % len;

  while (k-- > 0) {
    faster = faster->next;
  }

  while(faster->next != nullptr) {
    slower = slower->next;
    faster = faster->next;
  }

  faster->next = head;
  auto next = slower->next;
  slower->next = nullptr;

  return next;
}





