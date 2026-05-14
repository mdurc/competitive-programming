#include <bits/stdc++.h>

const int mod = 676767677;

void solve() {
  int n;
  std::cin >> n;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    if (a == 1 && i != n-1) continue;
    res = (res + a) % mod;
  }
  std::cout << res << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
