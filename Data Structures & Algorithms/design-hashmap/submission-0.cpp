// Alhamdulillah
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <vector>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class MyHashMap {
public:
  indexed_multiset ms;
  vector<long long> v;
  MyHashMap() { v.resize(1000001, -1); }

  void put(int key, int value) { v[key] = value; }

  int get(int key) { return v[key]; }

  void remove(int key) { v[key] = -1; }
};