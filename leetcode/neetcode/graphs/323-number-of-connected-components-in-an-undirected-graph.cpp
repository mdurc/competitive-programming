class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
      std::vector<std::vector<int>> adj(n);
      for (const std::vector<int>& e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
      }
      int cnt = 0;
      std::vector<bool> seen(n, false);
      auto dfs = [&](auto&& dfs, int u) -> void {
        seen[u] = true;
        for (int v: adj[u]) {
          if (!seen[v]) dfs(dfs, v);
        }
      };
      for (int i = 0; i < n; ++i) {
        if (!seen[i]) {
          ++cnt;
          dfs(dfs, i);
        }
      }
      return cnt;
    }
};
