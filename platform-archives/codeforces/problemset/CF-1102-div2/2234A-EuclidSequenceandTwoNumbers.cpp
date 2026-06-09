#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.rbegin(), a.rend());
  for (int i = 2; i < n; ++i) {
    if (a[i] != a[i-2]%a[i-1]) {
      std::cout << "-1\n";
      return;
    }
  }
  std::cout << a[0] << " " << a[1] << "\n";
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
