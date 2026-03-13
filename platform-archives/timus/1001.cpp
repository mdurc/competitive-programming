#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<long long> a;
  long long n;
  while (std::cin >> n) {
    a.push_back(n);
  }
  for (int i = (int)a.size()-1; i>=0; --i) {
    std::cout << std::fixed << std::setprecision(4) << std::sqrt(a[i]) << "\n";
  }

  return 0;
}
