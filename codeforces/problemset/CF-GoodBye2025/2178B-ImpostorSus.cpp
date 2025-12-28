#include <bits/stdc++.h>

void solve() {
  std::string s;
  std::cin >> s;
  int n = (int)s.size();
  int res = 0;
  if (s[0] == 'u') {
    ++res;
    s[0] = 's';
  }
  if (s[n-1] == 'u') {
    ++res;
    s[n-1] = 's';
  }
  int last_u = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == 's') {
      res += (i - last_u - 1) / 2;
      last_u = i;
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
