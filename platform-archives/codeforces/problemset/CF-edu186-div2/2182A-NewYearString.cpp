#include <bits/stdc++.h>

void solve1() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int mn = INT_MAX;
  bool has25 = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    std::string pref = s.substr(i,4);
    if (!has25) has25 = pref == "2025";
    for (int j = 0; j < 4; ++j) {
      if (pref[j] != "2026"[j]) {
        ++cnt;
      }
    }
    if (cnt == 0) {
      std::cout << "0\n";
      return;
    }
    mn = std::min(mn, cnt);
  }
  if (!has25) {
    std::cout << "0\n";
    return;
  } else {
    std::cout << mn << "\n";
  }
}

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  if (s.find("2025") == std::string::npos ||
      s.find("2026") != std::string::npos) {
    std::cout << "0\n";
  } else {
    std::cout << "1\n";
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
