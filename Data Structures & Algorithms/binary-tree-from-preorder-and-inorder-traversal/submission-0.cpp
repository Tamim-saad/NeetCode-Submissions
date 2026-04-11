
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  TreeNode *recur(deque<int> &preorder, vector<int> inorder) {
    if (preorder.empty() || inorder.empty())
      return nullptr;

    auto x = preorder.front();
    preorder.pop_front();

    auto ind = find(inorder.begin(), inorder.end(), x) - inorder.begin();
    vector<int> left(inorder.begin(), inorder.begin() + ind);
    vector<int> right(inorder.begin() + ind + 1, inorder.end());

    TreeNode *root = new TreeNode(x);
    root->left = recur(preorder, left);
    root->right = recur(preorder, right);
    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    deque<int> dq(preorder.begin(), preorder.end());
    return recur(dq, inorder);
  }
};