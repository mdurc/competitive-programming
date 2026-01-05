#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  ll S;
  std::cin >> n >> S;
  std::vector<std::vector<std::pair<int,int>>> adj(n);
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u-1].emplace_back(v-1, w);
    adj[v-1].emplace_back(u-1, w);
  }
  std::vector<int> paths(n), weight(n);
  auto dfs = [&](auto&& dfs, int u, int p) -> void {
    if (u > 0 && adj[u].size() == 1) {
      paths[u] = 1;
    }
    for (auto [v, w]: adj[u]) {
      if (v == p) continue;
      weight[v] = w;
      dfs(dfs, v, u);
      paths[u] += paths[v];
    }
  };
  dfs(dfs, 0, -1);
  for (int i = 1; i < n; ++i) {
    S -= (ll)paths[i] * weight[i];
  }
  std::priority_queue<std::pair<ll,int>> pq;
  for (int i = 1; i < n; ++i) {
    pq.emplace((ll)paths[i]*((weight[i]+1)/2), i);
  }
  int moves = 0;
  while (S < 0) {
    auto [w, u] = pq.top(); pq.pop();
    ++moves;
    S += w;
    weight[u] /= 2;
    pq.emplace((ll)paths[u]*((weight[u]+1)/2), u);
  }
  std::cout << moves << "\n";
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
