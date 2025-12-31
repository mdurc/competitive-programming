#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  if (a[0] == -1 && a[n - 1] == -1) {
    a[0] = a[n-1] = 0;
  } else if (a[0] == -1) {
    a[0] = a[n-1];
  } else if (a[n-1] == -1) {
    a[n-1] = a[0];
  }
  std::cout << std::abs(a[n-1]-a[0]) << "\n";
  for (int i: a) {
    std::cout << (i == -1 ? 0: i) << " ";
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
