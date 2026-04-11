// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {

    vector<int> t = {-1, -1};

    int i = 0;
    while (i < intervals.size()) {
      if (intervals[i][0] <= newInterval[0] and
          newInterval[0] <= intervals[i][1]) {
        t[0] = min(newInterval[0], intervals[i][0]);
      }
      if (intervals[i][0] <= newInterval[1] and
          newInterval[1] <= intervals[i][1]) {
        t[1] = max(newInterval[1], intervals[i][1]);
      }
      i++;
    }

    if (t[0] == -1)
      t[0] = newInterval[0];
    if (t[1] == -1)
      t[1] = newInterval[1];

    cout << t[0] << " " << t[1] << endl;
    // return t;

    vector<vector<int> > vans;

    i = 0;
    while (i < intervals.size()) {
      if (!((t[0] <= intervals[i][0] and intervals[i][0] <= t[1]) ||
          (t[0] <= intervals[i][1] and intervals[i][1] <= t[1]))) {
        // intervals.erase(intervals.begin() + i);
        vans.push_back(intervals[i]);
      }
      i++;
    }
    vans.push_back(t);

    sort(vans.begin(), vans.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[0] == b[0])
             return a[1] <= b[1];
           return a[0] <= b[0];
         });

    return vans;
  }
};