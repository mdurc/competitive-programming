#include <bits/stdc++.h>

void solve() {
  int n, y, r;
  std::cin >> n >> y >> r;
  std::cout << r + std::min(n-r, y/2) << "\n";
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
