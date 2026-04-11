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
  int node = 0;
  void preOrder(TreeNode *root, int maxSoFar = -107) {
    if (!root)
      return;
    int maxHere = maxSoFar;
    if (root->val >= maxSoFar) {
      node++;
      maxHere = root->val;
    }
    preOrder(root->left, maxHere);
    preOrder(root->right, maxHere);
  }

  int goodNodes(TreeNode *root) {
    preOrder(root);
    return node;
  }
};