class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      // tree is fully connected and acyclic with n-1 edges
      if ((int)edges.size() != n-1) {
        return false;
      }
      // assert that graph is connected
      std::vector<std::vector<int>> adj(n);
      for (int i = 0; i < n-1; ++i) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
      }
      int cnt = 0;
      std::vector<bool> seen(n, false);
      auto dfs = [&](auto&& dfs, int u) -> void {
        seen[u] = true;
        ++cnt;
        for (int v: adj[u]) {
          if (!seen[v]) dfs(dfs, v);
        }
      };
      dfs(dfs, 0);
      return cnt == n;
    }
};
