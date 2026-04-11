#include <bits/stdc++.h>
using namespace std;

// struct TreeNode {
// int val;
// TreeNode *left;
// TreeNode *right;
// TreeNode() : val(0), left(nullptr), right(nullptr) {}
// TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {

    deque<TreeNode *> next, curr;
    vector<vector<int>> ans;
    curr.push_back(root);

    if (root == nullptr)
      return ans;

    ans.push_back({root->val});

    while (!curr.empty()) {
      if (curr.front()->left)
        next.push_back(curr.front()->left);

      if (curr.front()->right)
        next.push_back(curr.front()->right);

      curr.pop_front();
      if (curr.empty()) {
        if (!next.empty()) {
          vector<int> vtemp;
          for (auto node : next)
            vtemp.push_back(node->val);

          ans.push_back(vtemp);
        }

        curr = next;
        next.clear();
      }
    }
    return ans;
  }
};