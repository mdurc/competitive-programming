#include <bits/stdc++.h>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int cnt = 0;
  std::vector<int> res(n);
  std::stack<int> needs_zero, needs_one;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (needs_zero.empty()) {
        res[i] = ++cnt;
      } else {
        res[i] = needs_zero.top();
        needs_zero.pop();
      }
      needs_one.push(res[i]);
    } else {
      if (needs_one.empty()) {
        res[i] = ++cnt;
      } else {
        res[i] = needs_one.top();
        needs_one.pop();
      }
      needs_zero.push(res[i]);
    }
  }
  std::cout << cnt << "\n";
  for (int i = 0; i < n; ++i) {
    std::cout << res[i] << " ";
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
