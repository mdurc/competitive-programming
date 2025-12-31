#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  int res = 0;
  for (int i = 0; i <= n/2; ++i) {
    if ((n - i*2) % 4 == 0) ++res;
  }
  std::cout << res << "\n";
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
