#include <bits/stdc++.h>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* beforeLeft = &dummy;
        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = beforeLeft->next;

        for (int i = 0; i <= right - left; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Reconnect the reversed 
        ListNode* leftNode = beforeLeft->next;
        beforeLeft->next = prev;
        leftNode->next = curr;

        return dummy.next;
    }
};
