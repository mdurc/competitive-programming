#include <bits/stdc++.h>

const int mod = 1e9+7;
int n;

int solve(int w, int h) {
  if (w == 1 && h == 1) return 1;
  if (w <= 0 || h <= 0) return 0;
  int res = 0;
  for (int i = 1; i <= w; ++i) {
    for (int j = 1; j <= h; ++j) {
      // TODO
    }
  }
  return res;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::cout << solve(2, n) << "\n";
  }
}
