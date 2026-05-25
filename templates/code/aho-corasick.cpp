#include <bits/stdc++.h>

struct AhoCorasick {
  struct Node {
    int next[26];
    int fail, out;
    std::vector<int> matches; // IDs of patterns that end exactly at this node

    Node() {
      std::fill(next, next + 26, -1);
      fail = 0;
      out = 0;
    }
  };

  std::vector<Node> trie;

  AhoCorasick() { trie.emplace_back(); }

  void insert(const std::string& pattern, int pattern_id) {
    int u = 0;
    for (char c : pattern) {
      int idx = c - 'a';
      if (trie[u].next[idx] == -1) {
        trie[u].next[idx] = trie.size();
        trie.emplace_back();
      }
      u = trie[u].next[idx];
    }
    trie[u].matches.push_back(pattern_id);
  }

  // build failure and output links (bfs)
  void build() {
    std::queue<int> q;

    // Push all depth-1 nodes to the queue. Their fail links are naturally 0
    // (root).
    for (int i = 0; i < 26; i++) {
      if (trie[0].next[i] != -1) {
        q.push(trie[0].next[i]);
      } else {
        // DFA Optimization: Missing root edges loop back to root
        trie[0].next[i] = 0;
      }
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int i = 0; i < 26; i++) {
        int v = trie[u].next[i];
        if (v != -1) {
          // 1. The fail link of child 'v' is the 'i' transition of u's fail
          // link. This is the EXACT parallel to l = lps[l-1] in KMP!
          trie[v].fail = trie[trie[u].fail].next[i];

          // 2. Build the output link to quickly grab substring matches
          if (!trie[trie[v].fail].matches.empty()) {
            trie[v].out = trie[v].fail;
          } else {
            trie[v].out = trie[trie[v].fail].out;
          }
          q.push(v);
        } else {
          // DFA Optimization: If child 'v' doesn't exist, we permanently point
          // this path to the fallback state. This completely eliminates
          // the KMP "while" loop during the search phase!
          trie[u].next[i] = trie[trie[u].fail].next[i];
        }
      }
    }
  }

  void search(const std::string& text) {
    int u = 0;
    int n = (int)text.size();
    for (int i = 0; i < n; ++i) {
      int idx = text[i] - 'a';
      u = trie[u].next[idx]; // bfs handles fail-links
      int curr = u;
      while (curr != 0) { // fail-link = 0 for root
        for (int pattern_id : trie[curr].matches) {
          // found pattern_id ending at text index i
          std::cout << pattern_id << " ending at " << i << "\n";
        }
        curr = trie[curr].out;
      }
    }
  }
};
