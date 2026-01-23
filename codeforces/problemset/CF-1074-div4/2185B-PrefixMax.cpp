#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::swap(a[0], a[std::max_element(a.begin(), a.end())-a.begin()]);
  int mx = a[0], res = a[0];
  for (int i = 1; i < n; ++i) {
    mx = std::max(mx, a[i]);
    res += mx;
  }
  std::cout << res << "\n";
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
