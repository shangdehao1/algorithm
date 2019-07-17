/*

Odd Even Linked List


Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...



*/

ListNode* oddEvenList(ListNode* head) {
  ListNode dummy1(-1);
  ListNode dummy2(-1);
  
  ListNode* node1 = &dummy1;
  ListNode* node2 = &dummy2;

  while (head != nullptr) {
    if (head != nullptr) {
      node1->next = head;
      node1 = node1->next;
      head = head->next;
    }

    if (head != nullptr) {
      node2->next = head;
      node2 = node2->next;
      head = head->next;
    }
  }

  node2->next = nullptr; // don't ignore it. !!!!!
  node1->next = dummy2.next;
  return dummy1.next;
}


