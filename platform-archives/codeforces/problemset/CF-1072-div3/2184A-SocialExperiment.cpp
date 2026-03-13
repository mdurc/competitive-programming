#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  if (n == 2 || n == 3) {
    std::cout << n << "\n";
  } else {
    std::cout << (n % 2 == 0 ? 0: 1) << "\n";
  }
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
