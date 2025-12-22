struct Trie {
  char base = 'a';
  struct Node {
    int next[26]; bool isEnd; int freq;
    Node() : isEnd(false), freq(0) { fill(next, next + 26, -1); }
  };
  vector<Node> tree;
  Trie() { tree.push_back(Node()); }
  void insert(const string& s) {
    int p = 0;
    tree[p].freq++;
    for (char c : s) {
      int idx = c - base;
      if (tree[p].next[idx] == -1) {
        tree[p].next[idx] = tree.size();
        tree.push_back(Node());
      }
      p = tree[p].next[idx];
      tree[p].freq++;
    }
    tree[p].isEnd = true;
  }
  bool search(const string& s) {
    int p = 0;
    for (char c : s) {
      int idx = c - base;
      if (tree[p].next[idx] == -1) return false;
      p = tree[p].next[idx];
    }
    return tree[p].isEnd;
  }
  bool startsWith(const string& s) {
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
int word_combinations(const string& s, const vector<string>& words) {
  const int MOD = 1e9 + 7;
  int n = s.size();
  Trie trie;
  for (auto& word : words) trie.insert(word);
  vector<int> dp(n + 1, 0);
  dp[0] = 1; // base case: empty string
  for (int i = 0; i < n; i++) {
    int p = 0; // start at root of trie
    for (int j = i; j < n; j++) {
      int idx = s[j] - 'a';
      if (trie.tree[p].next[idx] == -1) break; // no matching prefix
      p = trie.tree[p].next[idx];
      if (trie.tree[p].isEnd) dp[j + 1] = (dp[j + 1] + dp[i]) % MOD; // extend ways
    }
  }
  return dp[n];
}
