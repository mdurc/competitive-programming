#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  bool found = 0;
  for (int i = 0; i < n; ++i) {
    int a; std::cin >> a;
    if (a == 67) found = 1;
  }
  if (found) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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
