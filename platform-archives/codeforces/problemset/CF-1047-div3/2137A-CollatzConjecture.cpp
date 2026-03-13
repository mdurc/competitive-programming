#include <bits/stdc++.h>

void solve() {
  int k, x;
  std::cin >> k >> x;
  std::cout << (x << k) << "\n";
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
