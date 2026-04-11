/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  struct Node {
    string parent;
    int rank = 0;
  };

  map<string, Node> node;

  string FindParent(string u) {
    if (!node.count(u)) {
      node[u].parent = u;
      node[u].rank = 0;
    }
    if (node[u].parent == u)
      return u;

    return node[u].parent = FindParent(node[u].parent);
  }

  void Union(string u, string v) {
    string pu = FindParent(u);
    string pv = FindParent(v);
    if (pu == pv)
      return;

    if (node[pu].rank == node[pv].rank)
      node[u].rank++;

    if (node[pu].rank < node[pv].rank)
      swap(pu, pv);
    node[pv].parent = pu;
  }

  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    map<string, string> acntHolder;

    for (auto &x : accounts) {
      for (int i = 1; i < x.size(); i++) {
        acntHolder[x[i]] = x[0];
        Union(x[i], x[1]);
      }
    }

    map<string, vector<string>> group;
    for (auto e : acntHolder) {
      group[FindParent(e.first)].emplace_back(e.first);
    }

    vector<vector<string>> ans;

    for (auto &x : group) {
      vector<string> merged;
      merged.emplace_back(acntHolder[x.first]);

      for (auto mail : x.second)
        merged.emplace_back(mail);

      sort(merged.begin(), merged.end());
      ans.push_back(merged);
    }

    return ans;
  }
};