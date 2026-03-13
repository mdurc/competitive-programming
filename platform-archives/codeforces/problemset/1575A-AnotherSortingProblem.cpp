#include <bits/stdc++.h>

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<std::string, int>> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first;
    a[i].second = i+1;
  }
  std::sort(a.begin(), a.end(), [m](auto& x, auto& y) -> bool {
      for (int i = 0; i < m; ++i) {
        if (x.first[i] != y.first[i]) {
          if ((i+1)%2 == 1) {
            return x.first[i] < y.first[i];
          } else {
            return x.first[i] > y.first[i];
          }
        }
      }
      return false;
      });
  for (int i = 0; i < n; ++i) {
    std::cout << a[i].second << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
