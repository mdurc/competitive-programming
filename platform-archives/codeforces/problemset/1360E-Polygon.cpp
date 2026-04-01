#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  for (int i = n-1; i >= 0; --i) {
    for (int j = n-1; j >= 0; --j) {
      if (a[i][j] == '0') continue;
      if (i + 1 == n || j + 1 == n) continue;
      if ((i+1 < n && a[i+1][j] != '1') && (j+1 < n && a[i][j+1] != '1')) {
        std::cout << "NO\n";
        return;
      }
    }
  }
  std::cout << "YES\n";
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
