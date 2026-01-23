#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  int cur = 1, len = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i-1]) continue;
    if (a[i] == a[i-1]+1) ++cur;
    else cur = 1;
    len = std::max(len, cur);
  }
  std::cout << len << "\n";
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
