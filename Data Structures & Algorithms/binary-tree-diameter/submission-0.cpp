#include <bits/stdc++.h>
using namespace std;

// <Definition for a binary tree node.
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
    int maxDepth(TreeNode *root,int &res) {
      int l = 0, r = 0;
      if (root == nullptr)
        return 0;
      if (root->right != nullptr)
        r = maxDepth(root->right,res);
      if (root->left != nullptr)
        l = maxDepth(root->left,res);
      res=max(res,l+r);
      return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root) {
      int res=0;
      maxDepth(root,res);
      return res;
    }
};