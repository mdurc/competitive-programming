#include <bits/stdc++.h>

struct Point {
  long long x, y;
  Point operator+(const Point& b) const { return Point{x + b.x, y + b.y}; }
  Point operator-(const Point& b) const { return Point{x - b.x, y - b.y}; }
  Point operator*(long long k) const { return Point{x * k, y * k}; }
  Point operator/(long long k) const { return Point{x / k, y / k}; }
  bool operator<(const Point& b) const { return x != b.x ? x < b.x : y < b.y; }
  bool operator==(const Point& b) const { return x == b.x && y == b.y; }
  __int128 cross(const Point& b) const { return (__int128)x*b.y - (__int128)y*b.x; } // from origin, returns 2x triangle area
  __int128 triangle(const Point& b, const Point& c) const { return (b - *this).cross(c - *this); } // negative means b is left from c
  static bool cmp_y(const Point& a, const Point& b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }
  friend std::istream& operator>>(std::istream& is, Point& a) { return is >> a.x >> a.y; }
  friend std::ostream& operator<<(std::ostream& os, const Point& a) { return os << "(" << a.x << ", " << a.y << ")"; }
};
static inline __int128 dot(const Point& a, const Point& b) { return (__int128)a.x*b.x + (__int128)a.y*b.y; }
static inline __int128 dist2(const Point& a, const Point& b) {
  long long dx = a.x - b.x;
  long long dy = a.y - b.y;
  return (__int128)dx * dx + (__int128)dy * dy;
}

// 0 means b and c are collinear, -1 means b is left, +1 means b is right
static inline int orient(const Point& a, const Point& b, const Point& c) {
  __int128 v = a.triangle(b, c);
  return v == 0 ? 0: v < 0 ? -1: 1;
}
// segment containment: check if p lies on segment ab (inclusive)
bool on_segment(const Point& a, const Point& b, const Point& p) {
  return a.triangle(b, p) == 0 && dot(a - p, b - p) <= 0;
  // return a.triangle(b, p) == 0 && std::min(a.x, b.x) <= p.x && p.x <= std::max(a.x, b.x) && std::min(a.y, b.y) <= p.y && p.y <= std::max(a.y, b.y);
}
// [a,b] overlaps with [c,d]
bool intervals_overlap(long long a, long long b, long long c, long long d) {
  if (a > b) std::swap(a, b);
  if (c > d) std::swap(c, d);
  return std::max(a, c) <= std::min(b, d);
}
// segment intersection (including endpoints / collinear)
bool segments_intersect(Point p1, Point p2, Point p3, Point p4) {
  if (p3.triangle(p1, p4) == 0 && p3.triangle(p2, p4) == 0) { // collinear
    return intervals_overlap(p1.x, p2.x, p3.x, p4.x) && intervals_overlap(p1.y, p2.y, p3.y, p4.y);
  }
  __int128 sign1 = p1.triangle(p2, p3);
  __int128 sign2 = p1.triangle(p2, p4);
  if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) return false;
  sign1 = p3.triangle(p4, p1);
  sign2 = p3.triangle(p4, p2);
  if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) return false;
  return true;
}

long long polygon_area_doubled(const std::vector<Point>& poly) {
  long long area = 0;
  int n = (int)poly.size();
#ifdef method1
  for (int i = 2; i < n; ++i) {
    area += poly[0].triangle(poly[i], poly[i-1]);
  }
#else
  for (int i = 0; i < n; ++i) {
    area += poly[i].cross(poly[(i+1) % n]);
  }
#endif
  return std::abs(area);
}
bool is_inside_polygon(Point P, const std::vector<Point>& poly) {
  int n = (int)poly.size();
  bool inside = false;
  for (int i = 0; i < n; i++) {
    Point A = poly[i];
    Point B = poly[(i + 1) % n];
    if (P.triangle(A, B) == 0 &&
        std::min(A.x, B.x) <= P.x && P.x <= std::max(A.x, B.x) &&
        std::min(A.y, B.y) <= P.y && P.y <= std::max(A.y, B.y)) {
      return true; // point is on the boundary
    }
    bool a_left = (A.x <= P.x);
    bool b_left = (B.x <= P.x);
    if (a_left != b_left) {
      __int128 cross = P.triangle(A, B);
      if (a_left && cross < 0) inside = !inside;
      if (b_left && cross > 0) inside = !inside;
    }
  }
  return inside;
}

std::vector<Point> convex_hull(std::vector<Point> pts, bool keep_collinear = false) {
  std::sort(pts.begin(), pts.end());
  pts.erase(std::unique(pts.begin(), pts.end()), pts.end());
  int n = pts.size(), k = 0;
  if (n <= 2) return pts;
  std::vector<Point> hull(2 * n); // max hull size
  // first iteration is upper hull, second is lower hull (with reversed points)
  for (int rep = 0; rep < 2; ++rep) {
    // S prevents us from popping points that belong to the upper hull
    const int S = k;
    for (int i = 0; i < n; i++) {
      while (k >= S + 2) {
        __int128 v = hull[k-2].triangle(hull[k-1], pts[i]);
        if (v < 0 || (keep_collinear && v == 0)) break;
        k--;
      }
      hull[k++] = pts[i];
    }
    --k; // drop the last point because the second iteration will include it first
    std::reverse(pts.begin(), pts.end());
  }
  hull.resize(k);
  return hull;
}

// O(n log n) closest pair algorithm
struct closest_pts {
  __int128 d2; // distance squared
  Point p1, p2;
};
closest_pts closest_pair(std::vector<Point> pts) {
  int n = (int)pts.size();
  if (n < 2) return { (__int128)1 << 125, Point(), Point() };
  std::sort(pts.begin(), pts.end());
  std::vector<Point> strip;
  strip.reserve(n);
  auto helper = [&](auto&& helper, int l, int r) -> closest_pts {
    if (r - l <= 3) {
      closest_pts res = { (__int128)1 << 125, Point(), Point() };
      for (int i = l; i < r; ++i) {
        for (int j = i + 1; j < r; ++j) {
          __int128 d = dist2(pts[i], pts[j]);
          if (d < res.d2) res = {d, pts[i], pts[j]};
        }
      }
      std::sort(pts.begin() + l, pts.begin() + r, Point::cmp_y);
      return res;
    }

    int mid = (l + r) / 2;
    long long mid_x = pts[mid].x;
    closest_pts r1 = helper(helper, l, mid);
    closest_pts r2 = helper(helper, mid, r);

    // take the better of the two halves
    closest_pts res = (r1.d2 < r2.d2) ? r1 : r2;
    std::inplace_merge(pts.begin() + l, pts.begin() + mid, pts.begin() + r, Point::cmp_y);

    strip.clear();
    for (int i = l; i < r; ++i) {
      long long dx = pts[i].x - mid_x;
      if ((__int128)dx * dx < res.d2) {
        strip.push_back(pts[i]);
      }
    }

    for (size_t i = 0; i < strip.size(); ++i) {
      for (size_t j = i + 1; j < strip.size(); ++j) {
        long long dy = strip[j].y - strip[i].y;
        if ((__int128)dy * dy >= res.d2) break;
        __int128 d = dist2(strip[i], strip[j]);
        if (d < res.d2) {
          res = {d, strip[i], strip[j]};
        }
      }
    }
    return res;
  };
  return helper(helper, 0, n);
}
