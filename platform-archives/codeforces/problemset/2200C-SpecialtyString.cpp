#include <bits/stdc++.h>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::stack<char> q;
  for (int i = 0; i < n; ++i) {
    if (!q.empty() && s[i] == q.top()) {
      q.pop();
    } else {
      q.push(s[i]);
    }
  }
  std::cout << (q.empty()? "YES\n": "NO\n");
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
