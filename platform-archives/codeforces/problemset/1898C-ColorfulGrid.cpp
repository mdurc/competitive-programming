#include <bits/stdc++.h>

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int min_length = n+m-2;
  if (k < min_length) {
    std::cout << "NO\n";
    return;
  }

  int t = min_length-1;
  if ((k-t-1)%4 != 0 && (k-t-3)%4 != 0) {
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";

  std::vector rows(n, std::vector<bool>(m-1, 0));
  std::vector cols(n-1, std::vector<bool>(m, 0));

  rows[n-2][m-3] = 1;
  rows[n-2][m-2] = 1;
  rows[n-1][m-3] = 1;

  for (int i = m-4; i >= 0; --i) {
    rows[n-1][i] = !rows[n-1][i+1];
  }
  cols[n-2][0] = !rows[n-1][0];
  for (int i = n-3; i >= 0; --i) {
    cols[i][0] = !cols[i+1][0];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m-1; ++j) {
      std::cout << (rows[i][j] ? "R ": "B ");
    }
    std::cout << "\n";
  }
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cout << (cols[i][j] ? "R ": "B ");
    }
    std::cout << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve();
  }

  return 0;
}
