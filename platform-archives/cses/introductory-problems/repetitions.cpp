#include <bits/stdc++.h>

int main() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  int cur = 1, res = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      cur++;
      res = std::max(res, cur);
    } else {
      cur = 1;
    }
  }
  std::cout << res << "\n";
}
