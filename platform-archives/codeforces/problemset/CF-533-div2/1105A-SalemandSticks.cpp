#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int t, mn = 1e9;
  for (int i = 1; i <= 100; ++i) {
    int cur = 0;
    for (int j = 0; j < n; ++j) {
      cur += (std::max(std::abs(a[j]-i),1)-1);
    }
    if (cur < mn) {
      mn = cur;
      t = i;
    }
  }
  std::cout << t << " " << mn << "\n";
  return 0;
}
