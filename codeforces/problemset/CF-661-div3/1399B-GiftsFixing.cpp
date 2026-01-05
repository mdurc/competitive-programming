#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  int min_a = *std::min_element(a.begin(), a.end());
  int min_b = *std::min_element(b.begin(), b.end());
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += std::max(a[i]-min_a, b[i]-min_b);
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
