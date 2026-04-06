#include <bits/stdc++.h>

void solve() {
  long long a, b;
  std::cin >> a >> b;
  a = abs(a) % abs(b), b = abs(b);
  if (a == 0 || b == 0) {
    std::cout << "0\n";
    return;
  }
  std::unordered_map<long long, int> m;
  int i = 0;
  while (a > 0) {
    if (m.find(a) != m.end()) {
      std::cout << i - m[a] << "\n";
      return;
    }
    m[a] = i;
    a *= 10;
    a %= b;
    i++;
  }
  std::cout << "0\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
