#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];

  int res = 0;
  int i = n-1, j = n-1;
  while (i >= 0 && j >= 0) {
    if (a[i] == b[j]) {
      --i;
      --j;
    } else {
      res++;
      i--;
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
