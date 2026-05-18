#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  long long p = 0, chain = 0, l = 0, m = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    int pairs = a/2;
    if (pairs >= 1) {
      p += pairs;
      chain += a%2;
      m++;
    } else {
      l += a%2;
    }
  }
  long long res = p * 2 + chain + (m == 1 ? std::min(l,p): std::min(l, p-m));
  if (m == 0 || res < 3) {
    std::cout << "0\n";
    return;
  }
  std::cout << res << "\n";
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
