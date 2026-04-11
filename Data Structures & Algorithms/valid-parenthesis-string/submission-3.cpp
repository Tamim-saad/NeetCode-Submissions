class Solution {
 public:
  bool forward(string s) {
    int left = 0, star = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        left++;
      } else if (s[i] == '*') {
        star++;
      } else if (s[i] == ')') {
        if (left > 0)
          left--;
        else if (star > 0)
          star--;
        else {
          return false;
        }
      }
    }
    return true;
  }
  bool checkValidString(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++) {
      if (t[i] == '(')
        t[i] = ')';
      else if (t[i] == ')')
        t[i] = '(';
    }
    return forward(s) && forward(t);
  }
};