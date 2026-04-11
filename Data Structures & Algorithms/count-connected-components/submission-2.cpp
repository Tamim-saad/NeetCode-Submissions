class Solution {
 public:
  vector<vector<int>> adj_list;
  vector<int> par, vis;

  void dfs(int curr, int parnt) {
    par[curr] = parnt;
    vis[curr] = 1;

    for (int i = 0; i < adj_list[curr].size(); i++) {
      int neigh = adj_list[curr][i];
    //   if (par[curr] != neigh) {
      if (!vis[neigh]) {
        dfs(neigh, curr);
      }
    }
    return;
  }

  int countComponents(int n, vector<vector<int>>& edges) {
    vis.resize(n, 0);
    par.resize(n, -1);
    adj_list.resize(n);

    for (auto x : edges) {
      adj_list[x[0]].emplace_back(x[1]);
      adj_list[x[1]].emplace_back(x[0]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        dfs(i, i);
        ans++;
      }
    }
    return ans;
  }
};