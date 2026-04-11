#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<pair<int, int>> st;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      int x = heights[i];
      if (st.empty() || x > st.top().second) {
        st.push(make_pair(i, x));
      } else {
        while (!st.empty() && x <= st.top().second) {
          int h = st.top().second;
          st.pop();
          int w = st.empty() ? i : i - st.top().first - 1;
          ans = max(ans, h * w);
        }
        st.push(make_pair(i, x));
      }
    }

    while (!st.empty()) {
      int h = st.top().second;
      st.pop();
      int w = st.empty() ? n : n - st.top().first - 1;
      ans = max(ans, h * w);
    }
    return ans;
  }
};
