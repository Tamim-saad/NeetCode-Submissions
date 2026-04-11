/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

// class Node {
// public:
//   bool val;
//   bool isLeaf;
//   Node *topLeft;
//   Node *topRight;
//   Node *bottomLeft;
//   Node *bottomRight;

//   Node() {
//     val = false;
//     isLeaf = false;
//     topLeft = NULL;
//     topRight = NULL;
//     bottomLeft = NULL;
//     bottomRight = NULL;
//   }

//   Node(bool _val, bool _isLeaf) {
//     val = _val;
//     isLeaf = _isLeaf;
//     topLeft = NULL;
//     topRight = NULL;
//     bottomLeft = NULL;
//     bottomRight = NULL;
//   }

//   Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
//        Node *_bottomLeft, Node *_bottomRight) {
//     val = _val;
//     isLeaf = _isLeaf;
//     topLeft = _topLeft;
//     topRight = _topRight;
//     bottomLeft = _bottomLeft;
//     bottomRight = _bottomRight;
//   }
// };

class Solution {
public:
  pair<int, int> isSame(vector<vector<int>> &grid, int r1, int c1, int r2,
                        int c2) {
    int curr = -1;
    for (int i = r1; i <= r2; i++) {
      for (int j = c1; j <= c2; j++) {
        if (curr == -1)
          curr = grid[i][j];
        else if (grid[i][j] != curr)
          return {0, 0};
      }
    }
    return {1, curr};
  }

  Node *rec(vector<vector<int>> &grid, int r1, int c1, int r2, int c2) {
    auto x = isSame(grid, r1, c1, r2, c2);
    if (x.first == 1)
      return new Node(x.second == 1, true);

    int rm = (r1 + r2) / 2;
    int cm = (c1 + c2) / 2;

    Node *tl = rec(grid, r1, c1, rm, cm);
    Node *tr = rec(grid, r1, cm + 1, rm, c2);
    Node *bl = rec(grid, rm + 1, c1, r2, cm);
    Node *br = rec(grid, rm + 1, cm + 1, r2, c2);

    return new Node(false, false, tl, tr, bl, br);
    ;
  }

  Node *construct(vector<vector<int>> &grid) {
    Node *root = new Node();
    int n = grid.size();
    if (!n)
      return nullptr;

    return rec(grid, 0, 0, n - 1, n - 1);
  }
};