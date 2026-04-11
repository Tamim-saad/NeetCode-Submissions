#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

typedef tree<pair<ll, char>, null_type, greater<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class Solution {
public:
  int characterReplacement(string s, ll k) {
    indexed_multiset ms;
    map<char, ll> mp;
    ll n = s.size();

    ll i = 0, j = 0, ans = 0;
    while (i < n) {
      if (mp.find(s[i]) != mp.end())
        ms.erase({mp[s[i]], s[i]});
      mp[s[i]]++;
      ms.insert({mp[s[i]], s[i]});

      while (i - j + 1 - ms.begin()->first > k) {
        ms.erase({mp[s[j]], s[j]});
        if (--mp[s[j]])
          ms.insert({mp[s[j]], s[j]});
        j++;
      }
      ans = max(ans, i - j + 1);
      i++;
    }
    return ans;
  }
};