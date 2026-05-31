#include <bits/stdc++.h>

// https://cses.fi/problemset/task/2189
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // treat p1 as the origin, then determine
    //  if p3 is more left/right than p2 via cross product sign.

    // normalize based on (x1, y1)
    x2 -= x1;
    y2 -= y1;
    x3 -= x1;
    y3 -= y1;

    // y2/x2 > y3/x3 indicates the slope of p2 > p3, meaning p2 is more left
    // x2*y3 - x3*y2 < 0 means p2 is left, meaning that p3 is to the right
    long long c = (long long)x2*y3 - (long long)x3*y2;
    if (c < 0) {
      std::cout << "RIGHT\n";
    } else if (c > 0) {
      std::cout << "LEFT\n";
    } else { /* c == 0 equal slopes */
      std::cout << "TOUCH\n";
    }
  }
}
