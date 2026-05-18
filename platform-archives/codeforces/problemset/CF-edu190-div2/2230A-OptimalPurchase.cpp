#include <bits/stdc++.h>

using ll = long long;

void solve() {
  ll n, a, b;
  std::cin >> n >> a >> b;
  ll x = std::min(a, b);
  ll y = std::min(2*x, b);
  ll z = std::min(x+y, b);
  std::cout << (n/3)*z + ((n%3)/2)*y + ((n%3)%2)*x << "\n";
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
