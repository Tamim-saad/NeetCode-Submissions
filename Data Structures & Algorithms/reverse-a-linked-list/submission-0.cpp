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
  ListNode *reverseList(ListNode *head) {
    stack<ListNode *> st;
    ListNode *temp, *newHead;

    if (head == nullptr || head->next == nullptr)
      return head;

    while (head != nullptr) {
      st.push(head);
      head = head->next;
    }

    newHead = st.top();
    st.pop();
    temp = newHead;
    while (!st.empty()) {
      temp->next = st.top();
      temp = temp->next;
      st.pop();
    }
    temp->next = nullptr;
    return newHead;
  }
};

