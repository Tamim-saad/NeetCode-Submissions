/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
public:
  map<pair<TreeNode *, int>, int> mp;

  int rec(TreeNode *root, int parntRob) {
    if (!root)
      return 0;

    auto key = make_pair(root, parntRob);

    if (mp[key])
      return mp[key];

    int left, right, nebo, neboNa;

    if (parntRob == 1)
      return mp[key] = rec(root->left, 0) + rec(root->right, 0);

    nebo = root->val + rec(root->left, 1) + rec(root->right, 1);
    neboNa = rec(root->left, 0) + rec(root->right, 0);

    return mp[key] = max(nebo, neboNa);
  }
  int rob(TreeNode *root) { return rec(root, 0); }
};