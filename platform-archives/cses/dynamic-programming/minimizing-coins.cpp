#include <bits/stdc++.h>

const int inf = 1e9;
int n, x;
int a[101], dp[(int)1e6+1];

// recursive/v1
int solve(int sum) {
  if (sum == 0) return 0;
  if (sum < 0) return inf;
  if (dp[sum] != -1) return dp[sum];
  int res = inf;
  for (int i = 0; i < n; ++i) {
    res = std::min(res, 1 + solve(sum-a[i]));
  }
  return dp[sum] = res;
}

// iterative/v2
int solve() {
  dp[0] = 0;
  for (int i = 1; i <= x; ++i) {
    dp[i] = inf;
    for (int j = 0; j < n; ++j) {
      if (i-a[j] >= 0) {
        dp[i] = std::min(dp[i], 1 + dp[i-a[j]]);
      }
    }
  }
  return dp[x] == inf ? -1: dp[x];
}

int main() {
  std::cin >> n >> x;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  // std::fill(dp, dp+x+1, -1); // for recursive
  std::cout << solve() << "\n";
}
