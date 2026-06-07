#include <bits/stdc++.h>

const int mod = 1e9+7;
int n, x;
int a[101], dp[(int)1e6+1];

// same technique as dice-combinations.cpp
// recursive/v1
int solve(int sum) {
  if (sum == 0) return 1;
  if (sum < 0) return 0;
  if (dp[sum] != -1) return dp[sum];
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res = (res + solve(sum - a[i])) % mod;
  }
  return dp[sum] = res;
}

// iterative/v2
int solve() {
  dp[0] = 1;
  for (int i = 1; i <= x; ++i) {
    dp[i] = 0;
    for (int j = 0; j < n; ++j) {
      if (i-a[j] >= 0) {
        dp[i] = (dp[i] + dp[i-a[j]]) % mod;
      }
    }
  }
  return dp[x];
}

int main() {
  std::cin >> n >> x;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  // std::fill(dp, dp+x+1, -1); // for recursive
  std::cout << solve() << "\n";
}
