/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isprime(int n) {
    if (n == 1)
      return false;
    if (n == 2 || n == 3)
      return true;

    int k = sqrt(n);
    for (int i = 2; i <= k; i++) {
      if (n % i == 0)
        return false;
    }
    return true;
  }

  struct Node {
    int value;
    int parent = -1;
    int rank = 0;
  };

  Node node[100000];

  int FindParent(int u) {
    if (node[u].parent == -1)
      return u;
    return node[u].parent = FindParent(node[u].parent);
  }

  void Union(int u, int v) {
    if (node[u].rank >= node[v].rank)
      node[v].parent = u;
    else if (node[u].rank < node[v].rank)
      node[u].parent = v;
    if (node[u].rank == node[v].rank)
      node[u].rank++;
  }

  bool canTraverseAllPairs(vector<int> &nums) {
    if (nums.size() == 1)
      return true;

    vector<int> primes;
    map<int, int> mp;

    for (int i = 1; i < 320; i++) {
      if (isprime(i)) {
        primes.emplace_back(i);
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1)
        return false;
      for (auto x : primes) {
        if (x * x > nums[i])
          break;

        if (nums[i] % x == 0) {
          if (!mp.count(x)) {
            mp[x] = i;
          } else {
            int pu = FindParent(i);
            int pv = FindParent(mp[x]);
            if (pu != pv) {
              Union(pu, pv);
              mp[x] = FindParent(i);
            }
          }
        }
        while (!(nums[i] % x))
          nums[i] /= x;
      }

      if (nums[i] > 1) {
        if (!mp.count(nums[i])) {
          mp[nums[i]] = i;
        } else {
          int pu = FindParent(i);
          int pv = FindParent(mp[nums[i]]);
          if (pu != pv) {
            Union(pu, pv);
            mp[nums[i]] = FindParent(i);
          }
        }
      }
    }

    int root = FindParent(0);
    for (int i = 1; i < nums.size(); i++) {
      if (FindParent(i) != root)
        return false;
    }
    return true;
  }
};