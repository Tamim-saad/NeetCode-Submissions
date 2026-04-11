/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (!head || left == right)
      return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    int i;
    for (i = 1; i < left; i++)
      prev = prev->next;

    ListNode *curr = prev->next;

    ListNode *leftFixed = prev;
    ListNode *leftStart = curr;

    for (i = 0; i <= right - left; i++) {
      ListNode *next = curr->next;
      curr->next = prev;

      prev = curr;
      curr = next;
    }

    leftFixed->next = prev;
    leftStart->next = curr;

    if (left == 1)
      return leftFixed->next;
    else
      return head;
  }
};