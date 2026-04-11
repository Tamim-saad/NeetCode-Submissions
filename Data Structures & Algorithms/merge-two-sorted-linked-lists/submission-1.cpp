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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    ListNode *t1 = list1, *t2 = list2, *ans, dummy(0);
    ans = &dummy;

    while (t1 != nullptr && t2 != nullptr) {
      if (t1->val <= t2->val) {
        ans->next = t1;
        t1 = t1->next;
      } else {
        ans->next = t2;
        t2 = t2->next;
      }
      ans = ans->next;
    }

    if (t1 != nullptr)
      ans->next = t1;
    if (t2 != nullptr)
      ans->next = t2;
    return dummy.next;
  }
};


