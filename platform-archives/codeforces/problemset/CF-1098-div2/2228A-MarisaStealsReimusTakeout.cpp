#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  int zero = 0, one = 0, two = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    if (a == 0) ++zero;
    else if (a == 1) ++one;
    else ++two;
  }
  int p = std::min(one, two);
  std::cout << zero + p + ((one-p)/3) + ((two-p)/3) << "\n";
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
