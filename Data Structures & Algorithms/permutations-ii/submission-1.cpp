/// Alhamdulillah

#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  set<vector<int>> ans;
  void backTrack(vector<int> &curr, vector<int> &rem, int &n) {

    if (curr.size() == n) {
      ans.insert(curr);
      return;
    }

    for (int i = 0; i < rem.size(); i++) {
      vector<int> tmp = rem;

      curr.emplace_back(tmp[i]);
      tmp.erase(tmp.begin() + i);

      backTrack(curr, tmp, n);
      curr.pop_back();
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<int> curr;
    int n = nums.size();
    
    backTrack(curr, nums, n);
    return vector<vector<int>>(ans.begin(), ans.end());
  }
};
