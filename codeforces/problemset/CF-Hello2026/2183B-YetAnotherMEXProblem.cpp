#include <bits/stdc++.h>

// 18 min
const int mxn = 2e5+1;
int cnt[mxn];
void solve() {
  std::fill(cnt, cnt+mxn, 0);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  int res = 0;
  while (cnt[res] > 0) {
    ++res;
  }
  std::cout << std::min(res, k-1) << "\n";
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
