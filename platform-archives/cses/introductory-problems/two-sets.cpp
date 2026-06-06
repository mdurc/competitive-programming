#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  long long sum = (long long)n*(n+1)/2;
  if (sum % 2 == 1) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
    long long cur = 0;
    std::vector<int> a, b;
    for (int i = n; i >= 1; --i) {
      if (cur + i <= sum/2) {
        a.push_back(i);
        cur += i;
      } else {
        b.push_back(i);
      }
    }
    std::cout << a.size() << "\n";
    for (int i: a) std::cout << i << " ";
    std::cout << "\n";
    std::cout << b.size() << "\n";
    for (int i: b) std::cout << i << " ";
    std::cout << "\n";
  }
}
