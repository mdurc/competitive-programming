#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cout << i << " ";
  }
  std::cout << "\n";
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
