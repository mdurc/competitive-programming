#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<ll> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  ll mn = 0, mx = 0;
  for (int i = 1; i <= n; ++i) {
    ll x = std::min(mn - a[i - 1], b[i - 1] - mx);
    ll y = std::max(mx - a[i - 1], b[i - 1] - mn);
    mn = x, mx = y;
  }
  std::cout << mx << "\n";
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
