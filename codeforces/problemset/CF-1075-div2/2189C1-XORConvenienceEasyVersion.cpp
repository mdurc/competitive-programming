#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  if (n%2==0) {
    std::cout << n << " ";
  } else {
    std::cout << n-1 << " ";
  }
  for (int i = 2; i < n; ++i) {
    std::cout << (i ^ 1) << " ";
  }
  std::cout << "1\n";
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
