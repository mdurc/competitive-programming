#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int t;
  std::cin >> t;

  std::sort(a.begin(), a.end());
  int res = 0;
  int l = 0, r = 0;
  while (r < n) {
    if (a[r] - a[l] > t) {
      ++l;
    } else {
      res = std::max(res, r-l+1);
    }
    ++r;
  }
  std::cout << res << "\n";
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
