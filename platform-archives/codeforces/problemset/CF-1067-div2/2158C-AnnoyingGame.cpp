#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<ll> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  if (k % 2 == 0) {
    ll mx = a[0], cur = a[0];
    for (int i = 1; i < n; ++i) {
      cur = std::max(a[i], cur+a[i]);
      mx = std::max(mx, cur);
    }
    std::cout << mx << "\n";
    return;
  }
  std::vector<ll> pre(n), suf(n);
  pre[0] = a[0];
  suf[n-1] = a[n-1];
  for (int i = 1; i < n; ++i) pre[i] = std::max(a[i], pre[i-1]+a[i]);
  for (int i = n-2; i >= 0; --i) suf[i] = std::max(a[i], suf[i+1]+a[i]);
  ll res = -2e9;
  for (int i = 0; i < n; ++i) {
    res = std::max(res, pre[i]+suf[i]-a[i]+b[i]);
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
