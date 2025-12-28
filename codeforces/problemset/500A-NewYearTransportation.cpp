#include <bits/stdc++.h>

void solve() {
  int n, t;
  std::cin >> n >> t;
  std::vector<int> a(n+1);
  for (int i = 1; i <= n-1; ++i) {
    std::cin >> a[i];
  }
  int pos = 1;
  while (pos < n && pos != t) {
    pos += a[pos];
  }
  std::cout << (pos == t ? "YES": "NO") << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
