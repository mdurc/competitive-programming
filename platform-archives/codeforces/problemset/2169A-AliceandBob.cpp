#include <bits/stdc++.h>

void solve() {
  int n, v;
  std::cin >> n >> v;
  int less = 0, more = 0;
  for (int i = 0; i < n; ++i) {
    int a; std::cin >> a;
    if (a < v) ++less;
    else if (a > v) ++more;
  }
  std::cout << (less > more ? v - 1 : v + 1) << "\n";
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
