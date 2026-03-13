#include <bits/stdc++.h>

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  int res = 0, good = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      good = i + k + 1;
    } else if (i >= good) {
      ++res;
    }
  }
  std::cout << res << "\n";
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
