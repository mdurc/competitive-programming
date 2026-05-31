#include <bits/stdc++.h>

struct P {
  long long x, y;
  P operator+(const P& b) const { return P{x + b.x, y + b.y}; }
  P operator-(const P& b) const { return P{x - b.x, y - b.y}; }
  long long operator*(const P& b) const { return (long long)x*b.y - (long long)y*b.x; }
  bool operator<(const P& b) const { return x != b.x ? x < b.x : y < b.y; }
  long long cross(const P& b, const P& c) const { return (b - *this) * (c - *this); } // *this is the origin
  friend std::istream& operator>>(std::istream& is, P& b) { return is >> b.x >> b.y; }
};

// https://cses.fi/problemset/task/2195
int main() {
  int n;
  std::cin >> n;
  std::vector<P> points(n);
  for (int i = 0; i < n; ++i) std::cin >> points[i];
  std::sort(points.begin(), points.end());
  std::vector<P> hull;
  for (int rep = 0; rep < 2; ++rep) {
    const int S = hull.size(); // only access elements on the current (top/bottom) pass
    for (P c: points) {
      while ((int)hull.size() - S >= 2) {
        P a = hull.end()[-2];
        P b = hull.end()[-1];
        if (a.cross(b, c) <= 0) { // B is on the left from C, or colinear
          break;
        }
        hull.pop_back(); // remove B
      }
      hull.push_back(c);
    }

    // setup bottom pass
    hull.pop_back(); // remove rightmost point
    std::reverse(points.begin(), points.end());
  }
  std::cout << hull.size() << "\n";
  for (P p: hull) {
    std::cout << p.x << " " << p.y << "\n";
  }
}
