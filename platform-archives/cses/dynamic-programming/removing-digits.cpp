#include <bits/stdc++.h>

const int inf = 1e9;
int n;
int dp[(int)1e6+1];

// recursive
int solve(int cur) {
  if (cur == 0) return 0;
  if (dp[cur] != -1) return dp[cur];
  int res = inf, c = cur;
  while (c > 0) {
    if (c%10) {
      res = std::min(res, 1 + solve(cur - c%10));
    }
    c /= 10;
  }
  return dp[cur] = res;
}

// iterative
int solve() {
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = inf;
    int c = i;
    while (c > 0) {
      if (c%10) {
        dp[i] = std::min(dp[i], 1+dp[i-c%10]);
      }
      c /= 10;
    }
  }
  return dp[n];
}

int main() {
  std::cin >> n;
  // std::fill(dp, dp+n+1, -1);
  // std::cout << solve(n) << "\n";
  std::cout << solve() << "\n";
}
