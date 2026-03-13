#include <bits/stdc++.h>

void solve() {
  int s, k, m;
  std::cin >> s >> k >> m;
  if (s <= k || (m/k)%2 == 0) {
    std::cout << std::max(0, s-(m%k)) << "\n";
  } else {
    std::cout << k-(m%k) << "\n";
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
