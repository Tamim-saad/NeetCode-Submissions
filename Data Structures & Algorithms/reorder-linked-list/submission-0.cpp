class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;

    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  void reorderList(ListNode *head) {
    if (!head || !head->next)
      return;
    ListNode *slow = head, *fast = head, *ans, dummy(0);
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *part1 = head;
    ListNode *part2 = reverseList(slow->next);
    slow->next = nullptr;

    ans = &dummy;
    while (part1 && part2) {
      ans->next = part1;
      ans = ans->next;
      part1 = part1->next;
      ans->next = part2;
      ans = ans->next;
      part2 = part2->next;
    }
    if (part1) {
      ans->next = part1;
    }
     else
      ans->next = part2;
    // ans->next = nullptr;
    // head = dummy.next;
  }
};