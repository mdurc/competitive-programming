#include <bits/stdc++.h>

const int mod = 1e9+7;
int n, dp[1001][1001];
char a[1001][1001];

int solve(int r, int c) {
  if (r >= n || c >= n || a[r][c] == '*') return 0;
  if (r == n-1 && c == n-1) return 1;
  if (dp[r][c] != -1) return dp[r][c];
  return dp[r][c] = (solve(r+1, c) + solve(r, c+1)) % mod;
}

int solve() {
  std::memset(dp, 0, sizeof(dp));
  if (a[n-1][n-1] == '*') return 0;
  dp[n-1][n-1] = 1;
  for (int r = n-1; r >= 0; --r) {
    for (int c = n-1; c >= 0; --c) {
      if (r == n-1 && c == n-1) continue;
      if (a[r][c] == '*') {
        dp[r][c] = 0;
        continue;
      }
      int down = (r+1 < n ? dp[r+1][c]: 0);
      int right = (c+1 < n ? dp[r][c+1]: 0);
      dp[r][c] = (down + right) % mod;
    }
  }
  return dp[0][0];
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  // std::memset(dp, -1, sizeof(dp));
  // std::cout << solve(0, 0) << "\n";
  std::cout << solve() << "\n";
}
