/// Alhamdulillah
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class MyHashSet {
public:
  indexed_multiset ms;
  MyHashSet() {}

  void add(int key) { ms.insert(key); }

  void remove(int key) { ms.erase(key); }

  bool contains(int key) {
    auto ind = ms.find(key);
    return ind != ms.end();
  }
};