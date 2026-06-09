#include <bits/stdc++.h>

void solve() {
  long long n;
  std::cin >> n;
  if (n < 10 || n == 11) {
    std::cout << n << " 0\n";
    return;
  }
  if (n == 10) {
    std::cout << "-1\n";
    return;
  }
  if (n%12 == 0) {
    std::cout << 0 << " " << n << "\n";
    return;
  }
  auto pal = [&](long long x) {
    long long tmp = x, c = 0;
    while (x > 0) {
      c = c*10 + x%10;
      x /= 10;
    }
    return c == tmp;
  };
  long long a = 0;
  while (1) {
    if ((n-a)%12 == 0 && pal(a)) {
      std::cout << a << " " << n-a << "\n";
      return;
    }
    ++a;
  }
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
