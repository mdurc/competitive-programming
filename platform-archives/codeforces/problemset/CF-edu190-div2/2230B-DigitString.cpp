#include <bits/stdc++.h>

using ll = long long;

void solve() {
  std::string s;
  std::cin >> s;
  int n = (int)s.size();
  int res = std::count(s.begin(), s.end(), '4');
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1' || s[i] == '3') ++cnt;
    if (cnt > 0 && s[i] == '2') {
      --cnt;
      ++res;
    }
  }
  std::cout << res << "\n";
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
