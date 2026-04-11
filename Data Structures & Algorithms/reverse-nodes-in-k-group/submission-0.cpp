
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *reverse(ListNode *head) {
    ListNode *prev, *curr, *next;
    prev = next = nullptr;
    curr = head;

    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    int i = 1;
    auto curr = head;
    auto last = head;
    ListNode *dummy = new ListNode(0);
    auto ans = dummy;

    while (last && last->next && i < k) {
      last = last->next;
      i++;
      if (i == k) {
        auto tmp = last->next;
        last->next = nullptr;
        ans->next = reverse(curr);
        while (ans->next)
          ans = ans->next;

        curr = last = tmp;
        i = 1;
      }
    }
    ans->next = curr;

    return dummy->next;
  }
};