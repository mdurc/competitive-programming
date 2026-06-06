#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    // placements; i*i choose 2
    // ways that two knights could attack each other:
    // sets of 2x3 rectangles: 2*(i-1)*(i-2)
    // sets of 3x2 rectangles: 2*(i-1)*(i-2)
    long long sz = i*i;
    std::cout << sz*(sz-1)/2 - 4*(i-1)*(i-2) << "\n";
  }
}
