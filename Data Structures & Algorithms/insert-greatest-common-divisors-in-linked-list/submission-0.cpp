#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    while (head && head->next) {
      auto mid = gcd(head->val, head->next->val);
      auto newNode = new ListNode(mid);

      auto tmp = head->next;
      head->next = newNode;
      newNode->next = tmp;

      head = head->next->next;
    }

    return dummy->next;
  }
};