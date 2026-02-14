#include <bits/stdc++.h>

void solve() {
  int n, s, x;
  std::cin >> n >> s >> x;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    sum += a;
  }
  if (sum > s || (s-sum)%x != 0) {
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
