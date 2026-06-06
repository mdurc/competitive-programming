#include <bits/stdc++.h>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int y, x;
    std::cin >> y >> x;
    int mx = std::max(y, x);
    long long most = (long long)mx * mx;
    long long corner = most - mx + 1;
    int dir = 0;
    if (mx % 2 == 0) {
      dir = (y > x ? 1: -1); // travel left (+1) vs up (-1)
    } else {
      dir = (y > x ? -1: 1); // travel left (-1) vs up (+1)
    }
    corner = corner + (mx - std::min(y, x)) * dir;
    std::cout << corner << "\n";
  }
}
