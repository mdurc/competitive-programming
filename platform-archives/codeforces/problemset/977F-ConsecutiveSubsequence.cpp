#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::map<int, int> dp;

  int ans = INT_MIN;
  int end_idx = 0;
  for (int i = 0; i < n; ++i) {
    dp[a[i]] = dp[a[i]-1] + 1;
    if (dp[a[i]] > ans) {
      ans = dp[a[i]];
      end_idx = a[i];
    }
  }

  std::vector<int> res;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == end_idx) {
      res.push_back(i);
      end_idx--;
    }
  }

  std::cout << ans << "\n";
  for (int i = 0; i < ans; ++i) {
    std::cout << res[ans-i-1] + 1 << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
