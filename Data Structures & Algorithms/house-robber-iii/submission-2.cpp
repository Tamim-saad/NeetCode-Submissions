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

    int left, right, nebo, neboNa;

    if (parntRob == 1) {
      if (!mp[{root->left, 0}])
        mp[{root->left, 0}] = rec(root->left, 0);
      if (!mp[{root->right, 0}])
        mp[{root->right, 0}] = rec(root->right, 0);

      left = mp[{root->left, 0}];
      right = mp[{root->right, 0}];

      return (left + right);
    }

    if (!mp[{root->left, 0}])
      mp[{root->left, 0}] = rec(root->left, 0);
    if (!mp[{root->right, 0}])
      mp[{root->right, 0}] = rec(root->right, 0);
    if (!mp[{root->left, 1}])
      mp[{root->left, 1}] = rec(root->left, 1);
    if (!mp[{root->right, 1}])
      mp[{root->right, 1}] = rec(root->right, 1);

    nebo = root->val + mp[{root->left, 1}] + mp[{root->right, 1}];
    neboNa = mp[{root->left, 0}] + mp[{root->right, 0}];

    return max(nebo, neboNa);
  }
  int rob(TreeNode *root) { return rec(root, 0); }
};