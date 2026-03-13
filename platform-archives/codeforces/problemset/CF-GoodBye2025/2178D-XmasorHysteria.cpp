#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  if (m > n / 2) {
    std::cout << "-1\n";
    return;
  }

  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });

  if (m > 0) {
    std::cout << n - m << "\n";
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 1 || i/2 >= m) {
        std::cout << p[i]+1 << " " << p[i-1]+1 << "\n";
      }
    }
    return;
  }

  ll sum = std::accumulate(a.begin(), a.end(), 0LL) - a[p[n-1]];
  if (sum < a[p[n-1]]) {
    std::cout << "-1\n";
    return;
  }
  sum = 0;
  int x = n-2;
  while (sum < a[p[n-1]]) {
    sum += a[p[x]];
    --x;
  }
  std::cout << n-1 << "\n";
  for (int i = 0; i <= x; ++i) {
    std::cout << p[i]+1 << " " << p[i+1]+1 << "\n";
  }
  for (int i = x+1; i < n-1; ++i) {
    std::cout << p[i]+1 << " " << p[n-1]+1 << "\n";
  }
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
