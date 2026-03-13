#include <bits/stdc++.h>

// 10 min
void solve() {
  int n;
  std::cin >> n;
  // alice wins if 0
  std::vector<int> a(n);
  bool hasone = 0, prefz = 0, sufz = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (i == 0 && a[i] == 0) prefz = 1;
    if (i == n-1 && a[i] == 0) sufz = 1;
    if (a[i] == 1) hasone = 1;
  }
  if (hasone && ((prefz && !sufz) || (!prefz && hasone))) {
    std::cout << "Alice\n";
  } else {
    std::cout << "Bob\n";
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
