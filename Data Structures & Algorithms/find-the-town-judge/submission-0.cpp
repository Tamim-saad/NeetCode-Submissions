class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<vector<int>> adj_list(n + 1);

    vector<int> par(n + 1, -1);
    for (auto x : trust) {
      adj_list[x[1]].emplace_back(x[0]);
      par[x[0]] = x[1];
    }
    for (int i = 1; i <= n; i++) {
      if (adj_list[i].size() == n - 1 && par[i] == -1) return i;
    }
    return -1;
  }
};