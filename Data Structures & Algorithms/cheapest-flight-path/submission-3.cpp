/// Alhamdulillah
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {

    vector<vector<pair<int, int>>> adj_list(n);
    for (auto x : flights)
      adj_list[x[0]].emplace_back(x[1], x[2]);

    vector<int> value(n, INT_MAX);
    queue<tuple<int, int, int>> pq;

    pq.push({0, 0, src});
    value[src] = 0;

    while (!pq.empty()) {
      auto [currValue, currHop, currNode] = pq.front();
      pq.pop();

      // if (currHop > k)
        // continue;

      for (auto [neigh, edgeWeight] : adj_list[currNode]) {
        if (currHop <= k && currValue + edgeWeight < value[neigh]) {

          value[neigh] = currValue + edgeWeight;
          pq.push({value[neigh], currHop + 1, neigh});
        }
      }
    }

    return value[dst] == INT_MAX ? -1 : value[dst];
  }
};
