#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  long long res = 0;
  for (int i = 5; i <= n; i *= 5) {
    res += n/i;
  }
  std::cout << res << "\n";
}
