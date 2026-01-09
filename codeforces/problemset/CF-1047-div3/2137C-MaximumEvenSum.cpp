#include <bits/stdc++.h>

using ll = long long;

void solve() {
  ll a, b;
  std::cin >> a >> b;
  ll res = 0;
  if (b % 2 == 1) {
    res = a*b+1;
  } else {
    //res = a*(b/2) + b/(b/2);
    res = a*b/2 + 2;
  }
  std::cout << (res%2 == 0 ? res: -1) << "\n";
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

