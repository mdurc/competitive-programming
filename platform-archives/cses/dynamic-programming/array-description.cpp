#include<bits/stdc++.h>

const int mod = 1e9+7;
int n, m, a[100001], dp[100001][101];

// recursive - too slow - TLE
int solve(int idx, int prev) {
  if (idx == n) return 1;
  if (dp[idx][prev] != -1) return dp[idx][prev];
  int res = 0;
  if (a[idx] != 0) {
    res = (idx > 0 && std::abs(a[idx]-prev) > 1) ? 0: solve(idx+1, a[idx]);
  } else {
    for (int i = 1; i <= m; ++i) {
      if (idx == 0 || std::abs(i-prev) <= 1) {
        res = (res + solve(idx+1, i)) % mod;
      }
    }
  }
  return dp[idx][prev] = res;
}

int solve() {
  std::memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= m; ++i) dp[n][i] = 1;
  for (int j = n-1; j >= 0; --j) {
    for (int i = 0; i <= m; ++i) {
      int res = 0;
      if (a[j] != 0) {
        res = (j > 0 && std::abs(a[j]-i) > 1) ? 0: dp[j+1][a[j]];
      } else {
        int l = 1, r = m;
        if (i != 0) {
          l = std::max(1, i-1), r = std::min(m, i+1);
        }
        for (int k = l; k <= r; ++k) {
          if (i == 0 || std::abs(k-i) <= 1) {
            res = (res + dp[j+1][k]) % mod;
          }
        }
      }
      dp[j][i] = res;
    }
  }
  return dp[0][0];
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  // std::memset(dp, -1, sizeof(dp));
  // std::cout << solve(0, 0) << "\n";
  std::cout << solve() << "\n";
}
