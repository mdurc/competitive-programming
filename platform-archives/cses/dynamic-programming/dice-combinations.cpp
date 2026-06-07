#include <bits/stdc++.h>

const int mod = 1e9+7;
const int mxn = 1e6;
int n;
int dp[mxn+1];

// recursive/v1
int solve(int sum) {
  if (sum == 0) return 1;
  if (sum < 0) return 0;
  if (dp[sum] != -1) return dp[sum];
  int res = 0;
  for (int i = 1; i <= 6; ++i) {
    res = (res + solve(sum - i)) % mod;
  }
  return dp[sum] = res;
}

// iterative/v2
int solve() {
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = 0;
    for (int j = 1; j <= 6 && i-j >= 0; ++j) {
      dp[i] = (dp[i] + dp[i-j]) % mod;
    }
  }
  return dp[n];
}

int main() {
  std::cin >> n;
  // std::fill(dp, dp+n+1, -1); // for recursive
  std::cout << solve() << "\n";
}
