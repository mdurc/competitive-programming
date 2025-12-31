#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n+1), b(n+1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) std::cin >> b[i];
  bool awins = std::accumulate(a.begin(),a.end(),0) % 2 == 1;
  bool bwins = std::accumulate(b.begin(),b.end(),0) % 2 == 1;

  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      if (a[i] != b[i] && !awins) {
        awins = true;
        bwins = !bwins;
      }
    } else {
      if (a[i] != b[i] && !bwins) {
        bwins = true;
        awins = !awins;
      }
    }
  }

  if (awins == bwins) {
    std::cout << "Tie\n";
  } else if (awins) {
    std::cout << "Ajisai\n";
  } else {
    std::cout << "Mai\n";
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
