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
  vector<vector<int>> levelOrder(TreeNode *root) {

    deque<TreeNode *> nextdq, currdq;
    currdq.push_back(root);
    TreeNode *temp;

    int level = 1;
    vector<vector<int>> ans;
    if (root == nullptr)
      return ans;
    ans.push_back({root->val});
    // if (root->right != nullptr || root->left != nullptr)
    // ans.push_back({});

    while (!currdq.empty()) {
      temp = currdq.front();
      if (temp->left != nullptr) {
        nextdq.push_back(temp->left);
        // ans[level].push_back(temp->left->val);
      }
      if (temp->right != nullptr) {
        nextdq.push_back(temp->right);
        // ans[level].push_back(temp->right->val);
      }

      currdq.pop_front();
      if (currdq.empty()) {
        // if (!nextdq.empty())
        //   ans.push_back({});
        if (!nextdq.empty()) {
          // vector<int> vtemp(nextdq.begin(), nextdq.end());
          vector<int> vtemp;
          for (auto node : nextdq) {
            vtemp.push_back(node->val); // Fixed to push node values
          }
          ans.push_back(vtemp);
        }

        currdq = nextdq;
        nextdq.clear();

        level++;
      }
    }
    return ans;
  }
};