#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int c0 = std::count(a.begin(), a.end(), 0);
  int c1 = std::count(a.begin(), a.end(), 1);
  if (c0 == 0 || (c0 > 1 && c1 == 0)) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
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
