#include <bits/stdc++.h>

struct Pt {
  long long x, y;
  Pt operator+(const Pt& b) const { return Pt{x + b.x, y + b.y}; }
  Pt operator-(const Pt& b) const { return Pt{x - b.x, y - b.y}; }
  bool operator<(const Pt& b) const { return x != b.x ? x < b.x : y < b.y; }
  long long cross(const Pt& b) const { return x*b.y - y*b.x; }
  long long triangle(const Pt& b, const Pt& c) const { return (b - *this).cross(c - *this); } // *this is the origin
  friend std::istream& operator>>(std::istream& is, Pt& b) { return is >> b.x >> b.y; }
};

// [a,b] overlaps with [c,d]
bool intervals_overlap(long long a, long long b, long long c, long long d) {
  if (a > b) std::swap(a, b);
  if (c > d) std::swap(c, d);
  return std::max(a, c) <= std::min(b, d);
}

bool segments_intersect(Pt p1, Pt p2, Pt p3, Pt p4) {
  if (p3.triangle(p1, p4) == 0 && p3.triangle(p2, p4) == 0) {
    // two segments are collinear
    return intervals_overlap(p1.x, p2.x, p3.x, p4.x) && intervals_overlap(p1.y, p2.y, p3.y, p4.y);
  }
  long long sign1 = p1.triangle(p2, p3);
  long long sign2 = p1.triangle(p2, p4);
  if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
    return false;
  }
  sign1 = p3.triangle(p4, p1);
  sign2 = p3.triangle(p4, p2);
  if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
    return false;
  }
  return true;
}

bool segment_contains(Pt a, Pt b, Pt c) {
  if (a.triangle(b, c) != 0) return false;
  return std::min(a.x, b.x) <= c.x && c.x <= std::max(a.x, b.x) &&
         std::min(a.y, b.y) <= c.y && c.y <= std::max(a.y, b.y);
}

// https://cses.fi/problemset/task/2192
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Pt> p(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i];
  for (int k = 0; k < m; ++k) {
    Pt a;
    std::cin >> a;
#ifdef USING_INF_POINT
    Pt outside = Pt{a.x+1, 1'000'000'001LL};
#endif

    bool on_bound = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int j = i==n-1 ? 0: i+1;
      if (segment_contains(p[i], p[j], a)) {
        on_bound = 1;
        break;
      }
#ifdef USING_INF_POINT
      if (intersect(a, outside, p[i], p[j])) {
        ++res;
      }
#else
      bool upward = p[i].y <= a.y && p[j].y > a.y; // a should be on the left (inside polygon)
      if (upward && p[i].triangle(a, p[j]) < 0) ++res;

      bool downward = p[i].y > a.y && p[j].y <= a.y; // a should be on the right (inside polygon)
      if (downward && p[i].triangle(p[j], a) < 0) ++res;
#endif
    }
    if (on_bound) {
      std::cout << "BOUNDARY\n";
    } else if (res % 2 == 0) {
      std::cout << "OUTSIDE\n";
    } else {
      std::cout << "INSIDE\n";
    }
  }
}
