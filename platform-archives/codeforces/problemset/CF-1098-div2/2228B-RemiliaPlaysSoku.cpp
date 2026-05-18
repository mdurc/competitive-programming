#include <bits/stdc++.h>

void solve() {
  int n, x1, x2, k;
  std::cin >> n >> x1 >> x2 >> k;
  if (n <= 3) {
    std::cout << "1\n";
    return;
  }
  if (x1 < x2) std::swap(x1, x2);
  std::cout << k + std::min(x1 - x2, (n-x1)+x2) << "\n";
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
