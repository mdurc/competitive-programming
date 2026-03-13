#include <bits/stdc++.h>

using ll = long long;

#ifdef DEBUG
std::vector<int> factors(int n) {
  std::vector<int> res;
  for (int i = 1; i*i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n/i) res.push_back(n/i);
    }
  }
  return res;
}

void visual() {
  for (int i = 1; i <= 50; ++i) {
    printf("%-2d ", i);
  }
  std::cout << "\n";
  for (int i = 1; i <= 50; ++i) {
    printf("%-2d ", (factors(i).size()%2 == 0));
  }
  std::cout << "\n";
}
#endif

void solve() {
  ll k;
  std::cin >> k;
  std::cout << k + (ll)(std::sqrtl((long double)k) + 0.5) << "\n";
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
