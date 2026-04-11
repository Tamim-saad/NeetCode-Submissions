/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ans, dummy(0);
    int inHand = 0;
    ans = &dummy;
    while (l1 || l2) {
      int t = 0;
      if (l1) {
        t += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        t += l2->val;
        l2 = l2->next;
      }
      t += inHand;

      ListNode *temp=new ListNode(t % 10);
      ans->next = temp;
      ans = ans->next;
      inHand = t / 10;
    }
    if (inHand) {
      ListNode *temp=new ListNode(inHand);
      ans->next = temp;
    }
    return dummy.next;
  }
};
