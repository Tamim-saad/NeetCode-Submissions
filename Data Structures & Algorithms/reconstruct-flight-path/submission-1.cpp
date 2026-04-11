/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // map<string, priority_queue<pair<int, string>>> adj_list;
  map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>> adj_list;
  map<int, int> visEdge;
  vector<string> path;

  void dfs(string curr) {
    while (!adj_list[curr].empty()) {
      auto [eid, neigh] = adj_list[curr].top();
      adj_list[curr].pop();

      if (!visEdge[eid]) {
        cout << eid << " " << neigh << endl;
        visEdge[eid] = 1;
        dfs(neigh);
      }
    }
    path.emplace_back(curr);
  }

  vector<string> findItinerary(vector<vector<string>> &tickets) {
    sort(tickets.begin(),tickets.end());
    int n = tickets.size();

    for (int i = 0; i < n; i++) {
      auto x = tickets[i][0];
      auto y = tickets[i][1];

      adj_list[x].push({i, y});
    }
    dfs("JFK");

    reverse(path.begin(), path.end());
    return path;
  }
};