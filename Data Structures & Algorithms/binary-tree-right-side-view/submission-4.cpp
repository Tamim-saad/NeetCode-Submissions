
class Solution {
 public:
  vector<int> rightSideView(TreeNode *root) {
    if (!root) return {};
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    int prev = 1, now = 0;

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      prev--;
      if (node->left) {
        q.push(node->left);
        now++;
      }
      if (node->right) {
        q.push(node->right);
        now++;
      }
      if (!prev) {
        ans.emplace_back(node->val);
        prev = now;
        now = 0;
      }
    }
    return ans;
  }
};
