/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
  Node *copyRandomList(Node *head) {

    Node *org = head;
    map<Node *, Node *> mp;

    while (org) {
      mp[org] = new Node(org->val);
      org = org->next;
    }

    org = head;
    while (org) {
      mp[org]->next = mp[org->next];
      mp[org]->random = mp[org->random];
      org = org->next;
    }

    return mp[head];
  }
};
