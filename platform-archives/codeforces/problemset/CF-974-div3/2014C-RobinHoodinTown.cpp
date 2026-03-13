#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  if (n <= 2) {
    std::cout << "-1\n";
    return;
  }
  std::sort(a.begin(), a.end());
  ll sum = std::accumulate(a.begin(), a.end(), 0LL);
  // (sum + x)/(2*n) > a[mid]
  ll res = std::max(0LL, (ll)a[n/2]*2*n-sum+1);
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
