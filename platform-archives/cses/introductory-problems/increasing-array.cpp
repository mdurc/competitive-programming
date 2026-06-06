#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  int mx = 0;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    mx = std::max(mx, a);
    res += mx - a;
  }
  std::cout << res << "\n";
}
