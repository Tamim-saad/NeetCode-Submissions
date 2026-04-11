#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

// Define an indexed_multiset to keep track of character frequencies in a
// sliding window
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
    mp[idx] = val;
    idx++;

    cout << "push ===" << endl;
    for (auto x : ms) {
      cout << x.first << " --- " << x.second << endl;
    }
    cout << endl;
  }

  void pop() {
    --idx;
    ms.erase({mp[idx], idx});
    cout << "pop ===" << endl;
    for (auto x : ms) {
      cout << x.first << " --- " << x.second << endl;
    }
    cout << endl;
  }

  int top() {
    cout << "top ===" << endl;
    for (auto x : ms) {
      cout << x.first << " --- " << x.second << endl;
    }
    cout << endl;
    return mp[idx - 1];
  }

  int getMin() {

    cout << "getMin ===" << endl;
    for (auto x : ms) {
      cout << x.first << " --- " << x.second << endl;
    }
    cout << endl;
    return ms.begin()->first;
  }
};
