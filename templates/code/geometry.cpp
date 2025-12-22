typedef __int128_t i128;
struct Point {
  ll x, y;
  Point() : x(0), y(0) {}
  Point(ll _x, ll _y) : x(_x), y(_y) {}
  Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
  Point operator*(ll k) const { return Point(x * k, y * k); }
  bool operator<(const Point& o) const { return x != o.x ? x < o.x : y < o.y; }
  bool operator==(const Point& o) const { return x == o.x && y == o.y; }
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
static inline ll dist2(const Point& a, const Point& b) {
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;
  return dx * dx + dy * dy;
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
  if (orient(a, b, p) != 0) return false;
  return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y &&
         p.y <= max(a.y, b.y);
}
// segment intersection (including endpoints / collinear)
bool segments_intersect(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  int o1 = orient(a1, a2, b1);
  int o2 = orient(a1, a2, b2);
  int o3 = orient(b1, b2, a1);
  int o4 = orient(b1, b2, a2);
  if (o1 != o2 && o3 != o4) return true;
  if (o1 == 0 && on_segment(a1, a2, b1))
    return true;
  if (o2 == 0 && on_segment(a1, a2, b2))
    return true;
  if (o3 == 0 && on_segment(b1, b2, a1))
    return true;
  if (o4 == 0 && on_segment(b1, b2, a2))
    return true;
  return false;
}

vector<Point> convex_hull(vector<Point> pts, bool keep_collinear = false) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  int n = pts.size();
  if (n <= 1) return pts;
  vector<Point> lower, upper;
  // lower hull
  for (int i = 0; i < n; ++i) {
    while (lower.size() >= 2) {
      i128 v = cross(lower[lower.size() - 2],
          lower[lower.size() - 1], pts[i]);
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
      i128 v = cross(upper[upper.size() - 2],
          upper[upper.size() - 1], pts[i]);
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
