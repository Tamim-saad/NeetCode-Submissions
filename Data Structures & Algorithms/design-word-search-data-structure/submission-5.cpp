/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  int we = 0;
  int pc = 0;
  TrieNode *children[26];

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
};

class WordDictionary {
public:
  TrieNode *Root;
  WordDictionary() { Root = new TrieNode(); }

  void addWord(string word) {
    auto root = Root;
    for (char x : word) {
      if (!root->children[x - 'a'])
        root->children[x - 'a'] = new TrieNode();
      root->children[x - 'a']->pc++;

      root = root->children[x - 'a'];
    }
    root->we++;
  }

  bool searchWithRoot(TrieNode *root, int ind, string word) {
    if (ind == word.length())
      return root->we > 0;

    auto x = word[ind];
    if (x == '.') {
      for (int j = 0; j < 26; j++) {
        if (root->children[j]) {
          if (searchWithRoot(root->children[j], ind + 1, word))
            return true;
        }
      }
      return false;
    }
    if (!root->children[x - 'a'])
      return false;
    return searchWithRoot(root->children[x - 'a'], ind + 1, word);
  }

  bool search(string word) {
    auto root = Root;
    return searchWithRoot(root, 0, word);
  }
};
