#include <bits/stdc++.h>

int n, x;
int h[1001], s[1001], dp[1001][(int)1e5+1];

// recursive - too slow - TLE
int solve(int idx, int cost) {
  if (cost < 0) return -1e9;
  if (idx == n) return 0;
  if (dp[idx][cost] != -1) return dp[idx][cost];
  int take = s[idx] + solve(idx+1, cost-h[idx]);
  int skip = solve(idx+1, cost);
  return dp[idx][cost] = std::max(take, skip);
}

// knapsack 01
int solve() {
  std::memset(dp, 0, sizeof(dp));
  for (int j = n-1; j >= 0; --j) {
    for (int i = 0; i <= x; ++i) {
      dp[j][i] = dp[j+1][i];
      if (i-h[j] >= 0) {
        dp[j][i] = std::max(dp[j][i], s[j] + dp[j+1][i-h[j]]);
      }
    }
  }
  return dp[0][x];
}

int main() {
  std::cin >> n >> x;
  for (int i = 0; i < n; ++i) std::cin >> h[i];
  for (int i = 0; i < n; ++i) std::cin >> s[i];
  // std::memset(dp, -1, sizeof(dp));
  // std::cout << solve(0, x) << "\n";
  std::cout << solve() << "\n";
}
