
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *merge(ListNode *l, ListNode *r) {
    ListNode *dummy = new ListNode(0);
    auto curr = dummy;

    while (l && r) {
      if (l->val < r->val) {
        curr->next = l;
        l = l->next;
      } else {
        curr->next = r;
        r = r->next;
      }
      curr = curr->next;
    }
    if (l)
      curr->next = l;
    if (r)
      curr->next = r;
    return dummy->next;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return nullptr;

    if (lists.size() == 1)
      return lists[0];

    int mid = lists.size() / 2;
    vector<ListNode *> left(lists.begin(), lists.begin() + mid);
    vector<ListNode *> right(lists.begin() + mid, lists.end());

    auto leftSorted = mergeKLists(left);
    auto rightSorted = mergeKLists(right);

    auto head = merge(leftSorted, rightSorted);
    return head;
  }
};