class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    map<char, int> mp1;
    for (auto x : s1) {
      mp1[x]++;
    }

    int i = 0, j = 0, start = 0, cnt = s1.length();
    string s = s2;
    map<char, int> mp = mp1;
    while (i < s.length()) {
      if (mp[s[i]]) {
        mp[s[i]]--;
        cnt--;
        i++;
        if (cnt == 0) return true;
      } else {
        mp[s[j]]++;
        j++;
        cnt++;
      }
    }
    return false;
  }
};