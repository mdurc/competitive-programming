#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector a(2, std::vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }
  std::vector<int> amin(n), amax(n); // prefix
  amin[0] = amax[0] = a[0][0];
  for (int i = 1; i < n; ++i) {
    amin[i] = std::min(amin[i - 1], a[0][i]);
    amax[i] = std::max(amax[i - 1], a[0][i]);
  }
  std::vector<int> bmin(n), bmax(n); // suffix
  bmin[n - 1] = bmax[n - 1] = a[1][n - 1];
  for (int i = n - 2; i >= 0; --i) {
    bmin[i] = std::min(bmin[i + 1], a[1][i]);
    bmax[i] = std::max(bmax[i + 1], a[1][i]);
  }
  // x x x x x
  //         x x x x x
  std::vector<std::pair<int, int>> vals(n);
  for (int i = 0; i < n; ++i) {
    int mn = std::min(amin[i], bmin[i]);
    int mx = std::max(amax[i], bmax[i]);
    vals[i] = std::make_pair(mn, mx);
  }
  std::sort(vals.rbegin(), vals.rend());
  ll res = 0, cur_mx = 2 * n + 1;
  for (int i = 0; i < n; ++i) {
    if (vals[i].second < cur_mx) {
      res += (ll)vals[i].first * (cur_mx - vals[i].second);
      cur_mx = vals[i].second;
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
