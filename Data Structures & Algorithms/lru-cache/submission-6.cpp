// say Alhamdulillah

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// template <typename Key, typename Mapped, typename Compare, typename Tag,
//           typename Policy>

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class LRUCache {
public:
  indexed_multiset ms;
  unordered_map<int, int> mpTime, mpValue;

  int capacity;
  int time = 0;
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    if (mpValue.find(key) == mpValue.end())
      return -1;
    ms.erase(ms.lower_bound({mpTime[key], key}));
    ms.insert({time, key});
    mpTime[key] = time;
    time++;
    return mpValue[key];
  }

  void put(int key, int value) {
    if (mpValue.find(key) == mpValue.end()) {
      if (mpTime.size() == capacity) {
        mpTime.erase((*ms.begin()).second);
        mpValue.erase((*ms.begin()).second);
        ms.erase(ms.begin());
      }
      ms.insert({time, key});
      mpValue[key] = value;
      mpTime[key] = time;
      time++;
      return;
    }
    ms.erase(ms.lower_bound({mpTime[key], key}));
    ms.insert({time, key});
    mpValue[key] = value;
    mpTime[key] = time;
    time++;
  }
};
