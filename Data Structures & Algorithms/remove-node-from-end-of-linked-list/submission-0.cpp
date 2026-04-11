class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0);
    ListNode *left = &dummy, *right = head;
    left->next = head;
    while (n>1) {
      right = right->next;
      n--;
    }
    while (right->next) {
      right = right->next;
      left = left->next;
    }
    left->next = left->next->next;
    return dummy.next;
  }
};
