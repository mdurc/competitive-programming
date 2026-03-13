// O(E log E)
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      // eulerian path
      std::unordered_map<std::string, std::vector<std::string>> adj;
      for (std::vector<std::string>& e: tickets) {
        adj[e[0]].push_back(e[1]);
      }
      for (auto& [u, nei] : adj) {
        std::sort(nei.rbegin(), nei.rend());
      }
      std::vector<std::string> res;
      auto dfs = [&](auto&& dfs, const std::string& u) -> void {
        while (!adj[u].empty()) {
          std::string v = adj[u].back();
          adj[u].pop_back();
          dfs(dfs, v);
        }
        res.push_back(u);
      };
      dfs(dfs, "JFK");
      reverse(res.begin(), res.end());
      return res;
    }
};

// Too slow, does not pass, O(n*m):
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      // eulerian path
      std::sort(tickets.begin(), tickets.end());
      std::unordered_map<std::string, std::vector<std::string>> adj;
      for (std::vector<std::string>& e: tickets) {
        adj[e[0]].push_back(e[1]);
      }
      std::vector<std::string> res = {"JFK"};
      auto dfs = [&](auto&& dfs, const std::string& u) -> bool {
        if (res.size() == tickets.size()+1) return true;
        if (adj.find(u) == adj.end()) return false;
        for (int i = 0; i < (int)adj[u].size(); ++i) {
          std::string v = adj[u][i];
          res.push_back(v);
          adj[u].erase(adj[u].begin() + i);
          if (dfs(dfs, v)) return true;
          adj[u].insert(adj[u].begin() + i, v);
          res.pop_back();
        }
        return false;
      };
      dfs(dfs, "JFK");
      return res;
    }
};
