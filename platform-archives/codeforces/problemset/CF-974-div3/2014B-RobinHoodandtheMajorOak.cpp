#include <bits/stdc++.h>

void solve() {
  int n, k;
  std::cin >> n >> k;
  // number of odd values left at year n
  std::cout << ((k-(n/2-(n-k)/2))%2 == 0 ? "YES\n": "NO\n");
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
