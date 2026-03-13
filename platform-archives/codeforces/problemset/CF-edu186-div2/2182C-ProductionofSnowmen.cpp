#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  for (int i = 0; i < n; ++i) std::cin >> c[i];
  auto count = [&](auto& x, auto& y) -> int {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      bool ok = 1;
      for (int j = 0; j < n; ++j) {
        if (x[j] >= y[(j + i) % n]) {
          ok = 0;
          break;
        }
      }
      if (ok) ++res;
    }
    return res;
  };
  std::cout << (ll)n * count(a,b) * count(b,c) << "\n";
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
