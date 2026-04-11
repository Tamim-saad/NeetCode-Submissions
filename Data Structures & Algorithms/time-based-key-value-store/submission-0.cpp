#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

// Define an indexed_multiset to keep track of character frequencies in a
// sliding window
typedef tree<pair<ll, char>, null_type, greater<pair<ll, char>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class TimeMap {
public:
  indexed_multiset ms;
  map<string, vector<ll>> mp;
  map<pair<string, ll>, string> ans;
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mp[key].emplace_back(timestamp);
    ans[{key, timestamp}] = value;
  }

  string get(string key, int timestamp) {
    if (mp.find(key) == mp.end())
      return "";

    ll ts = upper_bound(mp[key].begin(), mp[key].end(), timestamp) -
            mp[key].begin();

    if (ts == 0) {
      return "";
    } else {
      return ans[{key, mp[key][ts - 1]}];
    }
  }
};
