#include <bits/stdc++.h>

void solve() {
  std::string s;
  std::cin >> s;
  if (std::count(s.begin(),s.end(),'Y') >= 2) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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
