#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i];
  int res = 0;
  for (int i = 0; i+1 < n; ++i) {
    if (std::abs(p[i]-p[i+1]) == std::gcd(p[i], p[i+1])) {
      ++res;
    }
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
