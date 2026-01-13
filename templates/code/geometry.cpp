#include <bits/stdc++.h>

using ll = long long;
using i128 = __int128;

struct Point {
  ll x, y;
  Point() : x(0), y(0) {}
  Point(ll _x, ll _y) : x(_x), y(_y) {}
  Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
  Point operator*(ll k) const { return Point(x * k, y * k); }
  Point operator/(ll k) const { return Point(x / k, y / k); }
  bool operator<(const Point& o) const { return x != o.x ? x < o.x : y < o.y; }
  static bool cmp_y(const Point& a, const Point& b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }
  bool operator==(const Point& o) const { return x == o.x && y == o.y; }
  friend std::istream& operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }
  friend std::ostream& operator<<(std::ostream& os, const Point& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

// from origin, area of parallelogram from vectors a and b
static inline i128 cross(const Point& a, const Point& b) {
  return (i128)a.x * b.y - (i128)a.y * b.x; // pos is counterclockwise a to b
}
// from point o acting as origin, area of parallelogram from vectors a and b
static inline i128 cross(const Point& o, const Point& a, const Point& b) {
  return cross(a - o, b - o); // positive is counterclockwise from a to b
}
static inline i128 dot(const Point& a, const Point& b) {
  return (i128)a.x * b.x + (i128)a.y * b.y;
}
// distance squared
static inline i128 dist2(const Point& a, const Point& b) {
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;
  return (i128)dx * dx + (i128)dy * dy;
}
// orient: +1 left turn, -1 right turn, 0 collinear
static inline int orient(const Point& a, const Point& b, const Point& c) {
  i128 v = cross(a, b, c);
  // from a acting as the origin, we check the relationship of vectors b and c
  if (v == 0) return 0;
  return (v > 0) ? 1 : -1;
}
// segment containment: check if p lies on segment ab (inclusive)
bool on_segment(const Point& a, const Point& b, const Point& p) {
  return orient(a, b, p) == 0 && dot(a - p, b - p) <= 0;
}
// segment intersection (including endpoints / collinear)
bool segments_intersect(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  int o1 = orient(a1, a2, b1);
  int o2 = orient(a1, a2, b2);
  int o3 = orient(b1, b2, a1);
  int o4 = orient(b1, b2, a2);
  if (o1 != o2 && o3 != o4) return true;
  if (o1 == 0 && on_segment(a1, a2, b1)) return true;
  if (o2 == 0 && on_segment(a1, a2, b2)) return true;
  if (o3 == 0 && on_segment(b1, b2, a1)) return true;
  if (o4 == 0 && on_segment(b1, b2, a2)) return true;
  return false;
}

std::vector<Point> convex_hull(std::vector<Point> pts, bool keep_collinear = false) {
  std::sort(pts.begin(), pts.end());
  pts.erase(std::unique(pts.begin(), pts.end()), pts.end());
  int n = (int)pts.size();
  if (n <= 1) return pts;
  std::vector<Point> lower, upper;
  // lower hull
  for (int i = 0; i < n; ++i) {
    while (lower.size() >= 2) {
      i128 v = cross(lower[lower.size() - 2], lower[lower.size() - 1], pts[i]);
      if (v > 0 || (keep_collinear && v == 0)) {
        break;
      }
      lower.pop_back();
    }
    lower.push_back(pts[i]);
  }
  // upper hull
  for (int i = n - 1; i >= 0; --i) {
    while (upper.size() >= 2) {
      i128 v = cross(upper[upper.size() - 2], upper[upper.size() - 1], pts[i]);
      if (v > 0 || (keep_collinear && v == 0)) {
        break;
      }
      upper.pop_back();
    }
    upper.push_back(pts[i]);
  }
  // remove duplicates in hull
  lower.pop_back();
  upper.pop_back();
  lower.insert(lower.end(), upper.begin(), upper.end());
  return lower;
}

// O(n log n) closest pair algorithm
struct closest_pts {
  i128 d2; // distance squared
  Point p1, p2;
};
closest_pts closest_pair(std::vector<Point> pts) {
  int n = (int)pts.size();
  if (n < 2) return { (i128)1 << 125, Point(), Point() };
  std::sort(pts.begin(), pts.end());
  std::vector<Point> strip;
  strip.reserve(n);
  auto helper = [&](auto&& helper, int l, int r) -> closest_pts {
    if (r - l <= 3) {
      closest_pts res = { (i128)1 << 125, Point(), Point() };
      for (int i = l; i < r; ++i) {
        for (int j = i + 1; j < r; ++j) {
          i128 d = dist2(pts[i], pts[j]);
          if (d < res.d2) res = {d, pts[i], pts[j]};
        }
      }
      std::sort(pts.begin() + l, pts.begin() + r, Point::cmp_y);
      return res;
    }

    int mid = (l + r) / 2;
    ll mid_x = pts[mid].x;
    closest_pts r1 = helper(helper, l, mid);
    closest_pts r2 = helper(helper, mid, r);

    // take the better of the two halves
    closest_pts res = (r1.d2 < r2.d2) ? r1 : r2;
    std::inplace_merge(pts.begin() + l, pts.begin() + mid, pts.begin() + r, Point::cmp_y);

    strip.clear();
    for (int i = l; i < r; ++i) {
      ll dx = pts[i].x - mid_x;
      if ((i128)dx * dx < res.d2) {
        strip.push_back(pts[i]);
      }
    }

    for (size_t i = 0; i < strip.size(); ++i) {
      for (size_t j = i + 1; j < strip.size(); ++j) {
        ll dy = strip[j].y - strip[i].y;
        if ((i128)dy * dy >= res.d2) break;
        i128 d = dist2(strip[i], strip[j]);
        if (d < res.d2) {
          res = {d, strip[i], strip[j]};
        }
      }
    }
    return res;
  };
  return helper(helper, 0, n);
}
