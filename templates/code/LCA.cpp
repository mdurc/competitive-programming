// Assumes 1-based node indexing
struct LCA {
  int n, MAX_LOG = 20;
  vector<vector<int>> adj; // adjacency list of the tree
  vector<vector<int>> up;  // up[v][j] = 2^j-th ancestor of v
  vector<int> depth;
  LCA(int _n) : n(_n) {
    MAX_LOG = 1;
    while ((1 << MAX_LOG) <= n) ++MAX_LOG;
    adj.assign(n + 1, vector<int>());
    up.assign(n + 1, vector<int>(MAX_LOG, 0));
    depth.assign(n + 1, 0);
  }
  void add_edge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }
  void dfs(int v, int p = 0) { // needed for depths
    up[v][0] = p;
    for (int u : adj[v]) {
      if (u != p) {
        depth[u] = depth[v] + 1;
        dfs(u, v);
      }
    }
  }
  void binary_lift() {
    for (int j = 1; j < MAX_LOG; j++) {
      for (int i = 1; i <= n; i++) {
        if (up[i][j - 1] != 0) up[i][j] = up[up[i][j - 1]][j - 1];
      }
    }
  }
  void build(int root = 1) {
    depth[root] = 0;
    dfs(root);
    binary_lift();
  }
  int kth_ancestor(int a, int k) {
    for (int i = 0; i < MAX_LOG; i++) {
      if ((1 << i) & k) {
        a = up[a][i];
        if (a == 0) break; // no ancestor exists
      }
    }
    return a;
  }
  int get_lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    // lift a to same depth as b
    a = kth_ancestor(a, diff);
    if (a == b) return a;
    // lift both until their parents are equal
    for (int i = MAX_LOG - 1; i >= 0; i--) {
      if (up[a][i] != 0 && up[a][i] != up[b][i]) {
        a = up[a][i];
        b = up[b][i];
      }
    }
    return up[a][0];
  }
  int tree_distance(int a, int b) {
    int lca = get_lca(a, b);
    return depth[a] + depth[b] - 2 * depth[lca];
  }
};
