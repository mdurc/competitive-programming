#include <bits/stdc++.h>

void solve() {
  int n, k;
  std::cin >> n >> k;
  int cur = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    if (a >= k) {
      cur += a;
    } else if (a == 0 && cur > 0) {
      --cur;
      ++ans;
    }
  }
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
