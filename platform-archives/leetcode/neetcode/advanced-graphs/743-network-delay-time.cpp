// Dijkstra's, O(E log V)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      std::vector<std::vector<std::pair<int,int>>> adj(n);
      for (std::vector<int>& t: times) {
        adj[t[0]-1].emplace_back(t[1]-1, t[2]);
      }
      const int inf = 1e9;
      std::vector<int> dist(n, inf);
      std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<>> pq;
      pq.emplace(0, k-1);
      dist[k-1] = 0;
      while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w]: adj[u]) {
          if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.emplace(dist[v], v);
          }
        }
      }
      int res = *std::max_element(dist.begin(), dist.end());
      return res == inf ? -1: res;
    }
};

// Floyd Warshall, O(V^3)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      const int inf = 1e9;
      vector<vector<int>> dist(n, vector<int>(n, inf));
      for (int i = 0; i < n; ++i) dist[i][i] = 0;
      for (std::vector<int>& t: times) {
        dist[t[0]-1][t[1]-1] = t[2];
      }
      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            dist[i][j] = std::min(dist[i][j], dist[i][k]+dist[k][j]);
          }
        }
      }
      int res = *std::max_element(dist[k-1].begin(), dist[k-1].end());
      return res == inf ? -1: res;
    }
};

// Bellman Ford, O(V * E)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      const int inf = 1e9;
      std::vector<int> dist(n, inf);
      dist[k-1] = 0;
      for (int i = 0; i < n-1; ++i) {
        for (std::vector<int>& t: times) {
          int u = t[0]-1, v = t[1]-1, w = t[2];
          if (dist[u] != inf && dist[u]+w < dist[v]) {
            dist[v] = dist[u]+w;
          }
        }
      }
      int res = *std::max_element(dist.begin(), dist.end());
      return res == inf ? -1: res;
    }
};
