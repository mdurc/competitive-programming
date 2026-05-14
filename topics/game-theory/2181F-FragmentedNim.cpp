#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/2181/F

void solve() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  /* key idea:
      non-independent sub games.
      the only way the opponent can force an outcome
      is when they pick a pile with 1 stone.
  */
  int ones = std::count(a.begin(), a.end(), 1);
  if (ones == n) {
    if (ones % 2 != 0) {
      std::cout << "Alice\n";
    } else {
      std::cout << "Bob\n";
    }
  } else {
    if (ones % 2 == 0) {
      std::cout << "Alice\n";
    } else {
      std::cout << "Bob\n";
    }
  }
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
