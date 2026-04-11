#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class MinStack {
private:
public:
  indexed_multiset ms;
  map<ll, ll> mp;
  ll idx = 0;
  MinStack() {}

  void push(int val) {
    ms.insert({val, idx});
    mp[idx++] = val;
  }

  void pop() { ms.erase({mp[--idx], idx}); }

  int top() { return mp[idx - 1]; }

  int getMin() { return ms.begin()->first; }
};
