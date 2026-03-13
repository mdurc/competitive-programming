#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<ll> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  std::sort(a.begin(), a.end());
  ll res = 0;
  std::vector<ll> ps(n);
  std::partial_sum(b.begin(), b.end(), ps.begin());
  for (int i = 0; i < n; ++i) {
    if ((ll)n >= ps[i]) {
      res = std::max(res, (ll)(i+1) * a[n-ps[i]]);
    }
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
