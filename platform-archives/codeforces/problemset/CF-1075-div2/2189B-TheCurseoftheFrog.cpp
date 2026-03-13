#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n; ll x;
  std::cin >> n >> x;
  ll pos = 0, mx = -2e18;
  for (int i = 0; i < n; ++i) {
    ll a, b, c;
    std::cin >> a >> b >> c;
    pos += (b - 1) * a;
    mx = std::max(mx, b*a-c);
  }
  if (pos >= x) {
    std::cout << "0\n";
    return;
  }
  if (mx <= 0) {
    std::cout << "-1\n";
    return;
  }
  std::cout << ((x-pos)+mx-1)/mx << "\n";
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
