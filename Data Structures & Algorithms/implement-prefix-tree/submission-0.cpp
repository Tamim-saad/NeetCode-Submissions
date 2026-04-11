/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  // int letterVal;
  int we = 0;
  int pc = 0;
  TrieNode *children[26];

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
};

class PrefixTree {
public:
  TrieNode *Root;
  PrefixTree() { Root = new TrieNode(); }

  void insert(string word) {
    auto root = Root;
    for (char x : word) {
      if (!root->children[x - 'a'])
        root->children[x - 'a'] = new TrieNode();
      root->children[x - 'a']->pc++;

      root = root->children[x - 'a'];
    }
    root->we++;
  }

  bool search(string word) {
    auto root = Root;
    for (char x : word) {
      if (!root->children[x - 'a'])
        return false;
      root = root->children[x - 'a'];
    }
    if (root->we > 0)
      return true;
    return false;
  }

  bool startsWith(string prefix) {
    auto root = Root;
    for (char x : prefix) {
      if (!root->children[x - 'a'])
        return false;
      root = root->children[x - 'a'];
    }
    if (root->pc > 0)
      return true;
    return false;
  }
};

// int main() {
//   vector<int> v;
//   int n, k;
//   cin >> n >> k;
//   for (int i = 0; i < n; i++) {
//     int x;
//     cin >> x;
//     v.push_back(x);
//   }
//   string s;
//   // cin >> s;
//   Solution sl;
//   // vector<int>
//   bool ans = sl.isNStraightHand(v, k);
//   // for (auto x : ans) {
//   //   cout << x << " ";
//   // }
//   cout << ans << endl;
// }
