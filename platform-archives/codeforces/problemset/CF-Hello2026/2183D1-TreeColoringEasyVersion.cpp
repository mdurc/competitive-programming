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
  std::vector<int> dist(n, -1), cnt(n, 0);
  std::queue<int> q;
  dist[0] = 0;
  cnt[0] = 1;
  q.push(0);
  int max_group = 1, max_depth = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int children = 0;
    for (int v: adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u]+1;
        max_depth = std::max(max_depth, ++cnt[dist[v]]);
        children++;
        q.push(v);
      }
    }
    max_group = std::max(max_group, children+1);
  }
  std::cout << std::max(max_depth, max_group) << "\n";
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
