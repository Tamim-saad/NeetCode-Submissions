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
  vector<int> vc;
  void inOrder(TreeNode *root) {
    if (root->left)
      inOrder(root->left);
    vc.push_back(root->val);
    if (root->right)
      inOrder(root->right);
  }

  int kthSmallest(TreeNode *root, int k) {
    inOrder(root);
    return vc[k - 1];
  }
};