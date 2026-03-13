#include <bits/stdc++.h>

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  for (int i = n-1; i >= 0; --i) {
    if (i == n-1) {
      a[i] = std::max(a[i], b[i]);
    } else {
      a[i] = std::max({a[i], a[i+1], b[i]});
    }
  }
  std::vector<int> ps(n);
  std::partial_sum(a.begin(), a.end(), ps.begin());
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << ps[r-1] - (l-2 >= 0 ? ps[l-2]: 0) << " ";
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
