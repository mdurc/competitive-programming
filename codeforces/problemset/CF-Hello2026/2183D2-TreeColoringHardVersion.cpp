#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }

  std::vector<int> dist(n, -1), parent(n, -1);
  std::vector<std::vector<int>> level(n);
  std::queue<int> q;
  dist[0] = 0;
  level[0].push_back(0);
  q.push(0);
  int max_group = 1, max_depth = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int children = 0;
    for (int v: adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u]+1;
        parent[v] = u;
        level[dist[v]].push_back(v);
        max_depth = std::max(max_depth, (int)level[dist[v]].size());
        children++;
        q.push(v);
      }
    }
    max_group = std::max(max_group, children + 1);
  }

  int minops = std::max(max_depth, max_group);
  std::cout << minops << "\n";

  std::vector<std::vector<int>> res(minops);
  std::vector<int> color(n);
  color[0] = 0;
  res[0].push_back(1);
  for (int d = 1; d < n; ++d) {
    if (level[d].empty()) break;
    std::vector<int>& nodes = level[d];
    int m = (int)nodes.size();
    std::sort(nodes.begin(), nodes.end(), [&](int a, int b) {
        return color[parent[a]] < color[parent[b]];
        });
    std::vector<int> bad;
    for (int i = 0; i < m; ++i) {
      int u = nodes[i];
      color[u] = i;
      if (color[parent[u]] == i) {
        bad.push_back(i);
      }
    }
    int next_extra = m;
    for (int idx: bad) {
      int u = nodes[idx];
      if (color[u] != color[parent[u]]) continue;
      if (next_extra < minops) {
        color[u] = next_extra++;
      } else {
        int swap_idx = 0;
        if (color[parent[nodes[0]]] == color[parent[u]]) {
          swap_idx = m - 1;
        }
        std::swap(color[u], color[nodes[swap_idx]]);
      }
    }
    for (int u: nodes) res[color[u]].push_back(u + 1);
  }
  for (std::vector<int>& r: res) {
    std::cout << r.size();
    for (int u: r) std::cout << " " << u;
    std::cout << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
