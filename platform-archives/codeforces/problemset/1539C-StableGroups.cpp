#include <bits/stdc++.h>

using ll = long long;

void solve() {
  ll n, k, x;
  std::cin >> n >> k >> x;
  std::vector<ll> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  std::vector<ll> amt;
  for (int i = 0; i+1 < n; ++i) {
    if (a[i+1]-a[i] > x) {
      amt.push_back((a[i+1]-a[i]-1)/x);
    }
  }
  std::sort(amt.begin(), amt.end());
  ll i = 0, cur = 0, nn = (ll)amt.size();
  while (i < nn && cur+amt[i]<=k) {
    cur += amt[i];
    ++i;
  }
  std::cout << nn-i+1 << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
