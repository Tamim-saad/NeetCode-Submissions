#include <bits/stdc++.h>
using namespace std;

class Codec {
public:
  void encode(TreeNode *root, string &ans) {
    if (!root)
      return;
    ans += to_string(root->val);

    if (root->left) {
      ans += "{";
      encode(root->left, ans);
      ans += "}";
    }
    if (root->right) {
      ans += "[";
      encode(root->right, ans);
      ans += "]";
    }
  }

  int extractFirstInt(string data) {
    string s = "";
    int i = 0;
    while (i < data.size() && (isdigit(data[i]) || data[i] == '-')) {
      s += data[i];
      i++;
    }
    return stoi(s);
  }

  string frag(string data, char open) {
    char close = ')';
    if (open == '{')
      close = '}';
    else
      close = ']';

    string ans = "";
    int i = 1, l = 1, r = 0;
    while (l != r) {
      if (data[i] == open)
        l++;
      if (data[i] == close)
        r++;
      if (l != r)
        ans += data[i];
      i++;
    }
    return ans;
  }

  TreeNode *decode(TreeNode *root, string &data) {
    if (data.empty())
      return root = nullptr;

    root = new TreeNode(extractFirstInt(data));
    int i = 0;

    while (i < data.size() && (isdigit(data[i]) || data[i] == '-'))
      i++;

    if (i < data.size() && data[i] == '{') {
      string left = frag(data.substr(i), '{');
      root->left = decode(root->left, left);
      i += left.size() + 2;
    } else {
      root->left = nullptr;
    }

    if (i < data.size() && data[i] == '[') {
      string right = frag(data.substr(i), '[');
      root->right = decode(root->right, right);
      i += right.size() + 2;
    } else {
      root->right = nullptr;
    }

    return root;
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string ans = "";
    encode(root, ans);
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty())
      return nullptr;
    return decode(nullptr, data);
  }
};
