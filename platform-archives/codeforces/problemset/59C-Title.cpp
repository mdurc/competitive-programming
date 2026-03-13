#include <bits/stdc++.h>

void solve() {
  int k;
  std::string s;
  std::cin >> k >> s;

  int n = (int)s.size();
  for (int i = 0; i < n/2; ++i) {
    if (s[i] == '?' && s[n-i-1] == '?') continue;
    if (s[i] == s[n-i-1]) continue;
    if (s[i] == '?') s[i] = s[n-i-1];
    else if (s[n-i-1] == '?') s[n-i-1] = s[i];
    else { std::cout << "IMPOSSIBLE\n"; return; }
  }

  std::set<char> todo;
  for (char c = 'a'; c < 'a'+k; ++c) todo.insert(c);
  for (char c: s) todo.erase(c);

  for (int i = (n%2==0?(n/2)-1:n/2); !todo.empty() && i >= 0; --i) {
    if (s[i] == '?') {
      char c = *todo.rbegin();
      s[i] = c, s[n-i-1] = c;
      todo.erase(c);
    }
  }
  if (todo.empty()) {
    for (char i: s) {
      std::cout << (i == '?'?'a':i);
    }
    std::cout << "\n";
  } else {
    std::cout << "IMPOSSIBLE\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
