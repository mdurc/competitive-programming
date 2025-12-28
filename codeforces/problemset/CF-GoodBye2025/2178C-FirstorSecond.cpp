#include <bits/stdc++.h>

using ll = long long;

void solve1() {
  int n;
  std::cin >> n;
  std::vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<ll> ps(n);
  std::partial_sum(a.begin(), a.end(), ps.begin());
  ll cur = 0, res = LLONG_MIN;
  for (int i = 0; i < n; ++i) {
    res = std::max(res, cur-(ps[n-1]-ps[i]));
    if (i == 0) {
      cur += a[i];
    } else {
      cur += std::abs(a[i]);
    }
  }
  std::cout << res << "\n";
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  ll sum = -std::accumulate(a.begin(), a.end(), 0LL);
  ll res = LLONG_MIN;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    res = std::max(res, sum);
    sum += (i == 0 ? a[i] : std::abs(a[i]));
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
