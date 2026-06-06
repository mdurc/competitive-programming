#include <bits/stdc++.h>

const int mod = 1e9+7;

int main() {
  int n;
  std::cin >> n;
  long long res = 1;
  for (int i = 0; i < n; ++i) {
    res = (res * 2) % mod;
  }
  std::cout << res << "\n";
}
