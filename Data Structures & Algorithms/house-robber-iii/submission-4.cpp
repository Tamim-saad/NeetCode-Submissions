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
  int recur(TreeNode *root, int shouldRob) {
    if (!root)
      return 0;

    if (mp.find({root, shouldRob}) != mp.end())
      return mp[{root, shouldRob}];

    int rob = 0, skip = 0;
    if (shouldRob)
      rob = root->val + recur(root->left, 0) + recur(root->right, 0);
    skip = recur(root->left, 1) + recur(root->right, 1);

    return mp[{root, shouldRob}] = max({rob, skip});
  }
  int rob(TreeNode *root) { return recur(root, 1); }
};