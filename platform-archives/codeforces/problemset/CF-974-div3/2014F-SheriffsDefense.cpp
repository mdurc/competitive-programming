#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n, c;
  std::cin >> n >> c;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }
  std::vector<std::array<ll,2>> dp(n);
  auto dfs = [&](auto&& dfs, int u, int p) -> void {
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (int v: adj[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
      dp[u][0] += std::max(dp[v][0], dp[v][1]);
      dp[u][1] += std::max(dp[v][0], dp[v][1]-2*c);
    }
  };
  dfs(dfs, 0, -1);
  std::cout << std::max(dp[0][0], dp[0][1]) << "\n";
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
