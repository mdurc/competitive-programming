#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  long long sum = 0;
  for (int i = 0; i < n-1; ++i) {
    int a;
    std::cin >> a;
    sum += a;
  }
  std::cout << (long long)n*(n+1)/2 - sum << "\n";
}
