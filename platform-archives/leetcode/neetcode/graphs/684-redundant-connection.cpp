// incremental cycle detection with DSU, O(n log n), optimal solution
class Solution {
public:
    std::vector<int> parent;
    int find(int u) {
      if (u == parent[u]) return u;
      return parent[u] = find(parent[u]);
    }
    bool merge(int u, int v) {
      u = find(u), v = find(v);
      if (u == v) return true;
      parent[u] = v;
      return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = (int)edges.size();
      parent.resize(n+1);
      std::iota(parent.begin(), parent.end(), 0);
      for (std::vector<int>& e: edges) {
        if (merge(e[0], e[1])) return e;
      }
      return {};
    }
};

// edge removal with dfs, O(n^2), still passes
std::vector<int> adj[1001];
bool seen[1001];
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = (int)edges.size();
      for (int i = 0; i < 1001; ++i) adj[i].clear();
      for (const std::vector<int>& e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
      }
      auto dfs = [&](auto&& dfs, int u, std::vector<int>& e) -> void {
        seen[u] = 1;
        for (int v: adj[u]) {
          if ((v==e[0]&&u==e[1])||(v==e[1]&&u==e[0])) continue;
          if (!seen[v]) dfs(dfs,v,e);
        }
      };
      // see which edge is not necessary to still be able to traverse from u to v
      for (int i = n-1; i >= 0; --i) {
        std::fill(seen, seen+1001, 0);
        dfs(dfs, edges[i][0], edges[i]);
        if (seen[edges[i][1]]) return edges[i];
      }
      return {};
    }
};


// incremental cycle detection with dfs, still O(n^2), still passes
class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
      int n = (int)edges.size();
      std::vector<std::vector<int>> adj(n+1);
      std::vector<bool> seen(n+1);
      auto dfs = [&](auto&& dfs, int u, int target) -> bool {
        seen[u] = 1;
        if (u == target) return true;
        for (int v: adj[u]) {
          if (!seen[v] && dfs(dfs, v, target)) {
            return true;
          }
        }
        return false;
      };
      for (std::vector<int>& e: edges) {
        int u = e[0], v = e[1];
        std::fill(seen.begin(), seen.end(), 0);
        if (!adj[u].empty() && !adj[v].empty() && dfs(dfs, u, v)) {
          return e;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      return {};
    }
};
