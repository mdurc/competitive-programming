#include <bits/stdc++.h>

const int mod = 1e9+7;
int n, x;
int a[101], dp[101][(int)1e6+1];

// recursive/v1 (too slow - TLE)
int solve(int idx, int sum) {
  if (sum == 0) return 1;
  if (sum < 0 || idx == n) return 0;
  if (dp[idx][sum] != -1) return dp[idx][sum];
  int res = 0;
  res = (res + solve(idx, sum - a[idx])) % mod;
  res = (res + solve(idx+1, sum)) % mod;
  return dp[idx][sum] = res;
}

// iterative/v2
int solve() {
  std::memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= n; ++i) dp[i][0] = 1;
  // dp[idx] = ..dp[idx+1] -> solve big to small
  for (int j = n-1; j >= 0; --j) { // putting this as the outside loop only to improve cache locality
    for (int i = 1; i <= x; ++i) {
      dp[j][i] = dp[j+1][i];
      if (i-a[j] >= 0) {
        dp[j][i] = (dp[j][i] + dp[j][i-a[j]]) % mod;
      }
    }
  }
  return dp[0][x];
}

int main() {
  std::cin >> n >> x;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  // std::memset(dp, -1, sizeof(dp)); // for recursive
  // std::cout << solve(0, x) << "\n";
  std::cout << solve() << "\n";
}
