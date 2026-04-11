#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  map<string, bool> visited;
  bool dfs(map<string, vector<pair<string, double>>> &neighbours, string curr,
           string &dest, double &ans) {

    visited[curr] = true;
    if (curr == dest)
      return true;

    for (auto [neigh, val] : neighbours[curr]) {
      if (!visited[neigh]) {
        ans *= val;
        if (dfs(neighbours, neigh, dest, ans))
          return true;

        ans /= val;
      }
    }
    return false;
  }

  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    map<string, vector<pair<string, double>>> neighbours;

    for (int i = 0; i < equations.size(); i++) {
      auto x = equations[i];
      neighbours[x[0]].push_back({x[1], values[i]});
      neighbours[x[1]].push_back({x[0], (double)(1 / values[i])});
    }
    vector<double> solns;

    for (auto x : queries) {
      visited.clear();

      if (neighbours.find(x[0]) == neighbours.end() ||
          neighbours.find(x[1]) == neighbours.end()) {

        solns.emplace_back(-1.0);
        continue;
      }

      if (x[0] == x[1]) {
        solns.emplace_back(1.0);
        continue;
      }

      double ans = 1.0;
      if (!dfs(neighbours, x[0], x[1], ans))
        ans = -1.0;

      solns.emplace_back(ans);
    }

    return solns;
  }
};