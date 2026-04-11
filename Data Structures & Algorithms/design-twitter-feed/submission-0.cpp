#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
  int cnt = 0;
  map<int, set<int>> followers, following;
  map<int, priority_queue<pair<int, int>>> tweet;

  Twitter() {}

  void postTweet(int userId, int tweetId) {
    tweet[userId].push({++cnt, tweetId});
  }

  void follow(int followerId, int followeeId) {
    followers[followeeId].insert(followerId);
    following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    followers[followeeId].erase(followerId);
    following[followerId].erase(followeeId);
  }

  vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>> pq;

    following[userId].insert(userId);

    for (auto pid : following[userId]) {
      priority_queue<pair<int, int>> tmp;
      int in = 0;

      while (!tweet[pid].empty() && in++ < 10) {
        auto x = tweet[pid].top();
        tmp.push(x);
        pq.push(x);
        tweet[pid].pop();
      }
      while (!tmp.empty()) {
        tweet[pid].push(tmp.top());
        tmp.pop();
      }
    }

    following[userId].erase(userId);

    vector<int> ans;
    int in = 0;
    while (!pq.empty() && in++ < 10) {
      ans.emplace_back(pq.top().second);
      pq.pop();
    }

    return ans;
  }
};
