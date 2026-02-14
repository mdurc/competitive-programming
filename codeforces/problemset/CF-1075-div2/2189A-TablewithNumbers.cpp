#include <bits/stdc++.h>

void solve() {
  int n, h, l;
  std::cin >> n >> h >> l;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  if (h > l) std::swap(h, l);
  int lo = 0, hi = n-1, res = 0;
  while (lo < hi) {
    if (a[lo] <= h && a[hi] <= l) {
      res++;
      lo++;
      hi--;
    }
    if (a[lo] > h) ++lo;
    if (a[hi] > l) --hi;
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
