// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;


//class Solution {
//public:
  ///  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //	vector<int> rows1st
      //  for (auto x:matrix){
  //          rows1st.push_back(x[0]);
    //    }
        
 //   }
//};

// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int l = 0;
    int h = matrix.size() - 1;
    while (l <= h) {
      int mid = (l + h) / 2;
      if (target < matrix[mid][0]) // || target == matrix[mid][h])
        h = mid - 1;
      else if (target > matrix[mid][matrix[0].size() - 1]) {
        l = mid + 1;
      } else {
        l = mid;
        break;
      }
    }

    if (l < 0 || l >= matrix.size())
      return false;
    cout << l << " --  " << endl;
    h = 0 + matrix[0].size() - 1;
    int row = l;
    l=0;

    while (l < h) {
      int mid = (l + h) / 2;
      if (target > matrix[row][mid]) {
        l = mid + 1;
      } else {
        h = mid;
      }
    }
    // if (target == matrix[row][mid]) {
    //   return true;
    // }
    if (matrix[row][l] == target)
      return true;
    return false;
  }
};
