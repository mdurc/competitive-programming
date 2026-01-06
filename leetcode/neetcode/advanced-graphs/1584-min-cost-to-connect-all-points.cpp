// prim solution:
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n = (int)points.size(), cost = 0, ncnt = 0;
      std::vector<std::vector<std::pair<int,int>>> adj(n);
      for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
          int dist = std::abs(points[i][0]-points[j][0]) + std::abs(points[i][1]-points[j][1]);
          adj[i].emplace_back(j, dist);
          adj[j].emplace_back(i, dist);
        }
      }
      std::vector<bool> seen(n, false);
      std::priority_queue<std::pair<int,int>, vector<std::pair<int,int>>, greater<>> pq;
      pq.emplace(0, 0);
      while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (!seen[u]) {
          seen[u] = true;
          cost += d, ncnt++;
          for (auto [v, w]: adj[u]) {
            if (!seen[v]) {
              pq.emplace(w, v);
            }
          }
        }
      }
      return ncnt != n ? -1: cost;
    }
};

// kruskal solution (globals):
std::vector<int> edges[1000001];
int parent[1000001];
class Solution {
public:
    int find(int u) {
      if (u == parent[u]) return u;
      return parent[u] = find(parent[u]);
    }
    bool merge(int u, int v) {
      u = find(u), v = find(v);
      if (u == v) return false;
      parent[u] = v;
      return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n = points.size();
      std::iota(parent, parent+n, 0);
      int ecnt = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
          edges[ecnt++] = {i, j, std::abs(points[i][0]-points[j][0]) + std::abs(points[i][1]-points[j][1])};
        }
      }
      std::sort(edges, edges+ecnt, [](const std::vector<int>& a, const std::vector<int>& b) {
          return a[2] < b[2];
          });
      int cost = 0, sz = 0;
      for (int i = 0; i < ecnt; ++i) {
        std::vector<int>& e = edges[i];
        if (merge(e[0], e[1])) {
          cost += e[2];
          sz++;
        }
      }
      if (sz < n - 1) return -1;
      return cost;
    }
};

// kruskal solution (no globals):
class Solution {
public:
    std::vector<int> parent;
    std::vector<std::vector<int>> edges;
    int find(int u) {
      if (u == parent[u]) return u;
      return parent[u] = find(parent[u]);
    }
    bool merge(int u, int v) {
      u = find(u), v = find(v);
      if (u == v) return false;
      parent[u] = v;
      return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n = (int)points.size(), ecnt = n*(n-1)/2;
      edges.reserve(ecnt);
      parent.resize(n);
      std::iota(parent.begin(), parent.end(), 0);
      for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
          edges.push_back({i, j, std::abs(points[i][0]-points[j][0]) + std::abs(points[i][1]-points[j][1])});
        }
      }
      std::sort(edges.begin(), edges.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
          return a[2] < b[2];
          });
      int cost = 0, sz = 0;
      for (std::vector<int>& e: edges) {
        if (merge(e[0], e[1])) {
          cost += e[2];
          sz++;
        }
      }
      if (sz < n - 1) return -1;
      return cost;
    }
};
