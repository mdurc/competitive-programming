#include <bits/stdc++.h>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  // subsequence cannot be a prefix of s
  // first differing char: s[i] == ')';
  int cur = 0, copen = std::count(s.begin(), s.end(), '(');
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == '(') ++cur;
    if (s[i] == ')' && s[i+1] == '(') {
      if (copen - (cur+1) >= 1) {
        std::cout << n-2 << "\n";
        return;
      }
    }
  }
  std::cout << "-1\n";
}

/* (()(())) */
/* 01234567 */

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
