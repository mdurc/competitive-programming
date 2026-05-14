#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  auto check = [&](int m) {
    std::vector<bool> seen(m, false);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (cur >= m) return true;
      if (a[i] < m && !seen[a[i]]) {
        seen[a[i]] = true;
      } else if (cur <= (a[i] - 1) / 2) {
        seen[cur] = true;
      }
      while (cur < m && seen[cur]) {
        cur++;
      }
    }
    return cur >= m;
  };
  int l = 0, r = n;
  while (l < r) {
    int mid = l+(r-l+1)/2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid-1;
    }
  }
  std::cout << l << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
