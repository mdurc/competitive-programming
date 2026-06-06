#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  if (n == 2 || n == 3) {
    std::cout << "NO SOLUTION\n";
  } else {
    // odd .. odd 1 4 even .. even 2
    for (int i = 3; i <= n; i += 2) std::cout << i << " ";
    std::cout << "1 ";
    for (int i = 4; i <= n; i += 2) std::cout << i << " ";
    if (n > 1) std::cout << "2\n";
  }
}
