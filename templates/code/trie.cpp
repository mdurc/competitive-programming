#include <bits/stdc++.h>

struct Trie {
  char base = 'a';
  struct Node {
    int next[26];
    bool is_end;
    int count;
    Node() : is_end(false), count(0) { std::fill(next, next + 26, -1); }
  };
  std::vector<Node> tree;
  Trie() { tree.emplace_back(); }
  void insert(const std::string& s) {
    int p = 0;
    tree[p].count++;
    for (char c : s) {
      int idx = c - base;
      if (tree[p].next[idx] == -1) {
        tree[p].next[idx] = tree.size();
        tree.emplace_back();
      }
      p = tree[p].next[idx];
      tree[p].count++;
    }
    tree[p].is_end = true;
  }
  bool search(const std::string& s) {
    int p = 0;
    for (char c : s) {
      int idx = c - base;
      if (tree[p].next[idx] == -1) return false;
      p = tree[p].next[idx];
    }
    return tree[p].is_end;
  }
  bool startsWith(const std::string& s) {
    int p = 0;
    for (char c : s) {
      int idx = c - base;
      if (tree[p].next[idx] == -1) return false;
      p = tree[p].next[idx];
    }
    return true;
  }
};

// number of ways to form string S using words in the dictionary
int word_combinations(const std::string& s, const std::vector<std::string>& words) {
  const int MOD = 1e9 + 7;
  int n = s.size();
  Trie trie;
  for (auto& word : words) trie.insert(word);
  std::vector<int> dp(n + 1, 0);
  dp[0] = 1; // base case: empty string
  for (int i = 0; i < n; i++) {
    int p = 0; // start at root of trie
    for (int j = i; j < n; j++) {
      int idx = s[j] - 'a';
      if (trie.tree[p].next[idx] == -1) break; // no matching prefix
      p = trie.tree[p].next[idx];
      if (trie.tree[p].is_end) dp[j + 1] = (dp[j + 1] + dp[i]) % MOD; // extend ways
    }
  }
  return dp[n];
}
