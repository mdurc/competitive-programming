#include <bits/stdc++.h>

const int mxn = 50001;
std::vector<int> adj[mxn];
int dp[mxn][501];


void solve() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  long long ans = 0;
  auto dfs = [&](auto&& dfs, int u, int p) -> void {
    dp[u][0] = 1;
    for (int v: adj[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
      for (int i = 1; i <= k; ++i) ans += 1LL * dp[u][k-i] * dp[v][i-1];
      for (int i = 1; i <= k; ++i) dp[u][i] += dp[v][i-1];
    }
  };

  dfs(dfs, 1, 0);
  std::cout << ans << "\n";

#if 0
  for (int i = 0; i < n; ++i) dp[i][1] = (int)adj[i].size();
  for (int i = 2; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int v: adj[j]) {
        dp[j][i] += (dp[v][i-1]-1);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) ans += dp[i][k];
#endif
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
