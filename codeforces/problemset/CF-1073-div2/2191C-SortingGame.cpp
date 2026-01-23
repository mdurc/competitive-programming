#include <bits/stdc++.h>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  if (std::is_sorted(s.begin(), s.end())) {
    std::cout << "Bob\n";
    return;
  }
  int c0 = std::count(s.begin(), s.end(), '0');
  std::vector<int> res;
  for (int i = 0; i < n; ++i) {
    if (i < c0 && s[i] == '1') res.push_back(i + 1);
    if (i >= c0 && s[i] == '0') res.push_back(i + 1);
  }
  std::cout << "Alice\n" << res.size() << "\n";
  for (int i: res) {
    std::cout << i << " ";
  }
  std::cout << "\n";
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
