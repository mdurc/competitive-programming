#include <bits/stdc++.h>

void solve() {
  int n, m;
  std::string s;
  std::cin >> n >> m >> s;

  int idx;
  std::vector<bool> a(n, false);
  for (int i = 0; i < m; ++i) std::cin >> idx, a[idx-1] = 1;

  std::string c;
  std::cin >> c;

  std::sort(c.begin(), c.end());
  for (int cidx = 0, i = 0; i < n; ++i) {
    if (a[i] && cidx < m) {
      s[i] = c[cidx++];
    }
  }
  std::cout << s << "\n";
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
