



ListNode* middleNode(ListNode* head) {

  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  auto slower = head;
  auto faster = head->next;

  while (faster != nullptr && faster->next != nullptr) {
    slower = slower->next;
    faster = faster->next->next;
  }

  if (faster == nullptr) {
    return slower;
  }

  return slower->next;
}
