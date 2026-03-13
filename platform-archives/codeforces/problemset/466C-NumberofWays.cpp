#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  ll sum = std::accumulate(a.begin(), a.end(), 0LL);
  if (sum % 3 != 0) {
    std::cout << "0\n";
    return;
  }
  ll k = sum / 3;
  int firsts = 0;
  ll cur = 0, res = 0;
  for (int i = 0; i < n-1; ++i) {
    cur += a[i];
    if (cur == 2*k) {
      res += firsts;
    }
    if (cur == k) {
      ++firsts;
    }
  }
  std::cout << res << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
