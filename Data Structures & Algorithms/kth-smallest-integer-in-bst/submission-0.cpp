/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
  vector<int> vc;
  void preOrder(TreeNode *root) {
    if (root->left)
      preOrder(root->left);
    vc.push_back(root->val);
    if (root->right)
      preOrder(root->right);
  }

  int kthSmallest(TreeNode *root, int k) {
    preOrder(root);
    for (auto x : vc) {
      cout << x << " ";
    }
    return vc[k - 1];
  }
};