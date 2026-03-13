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

// distance squared
static inline i128 dist2(const Point& a, const Point& b) {
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;
  return (i128)dx * dx + (i128)dy * dy;
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

void solve() {
  int n;
  std::cin >> n;
  std::vector<Point> p(n);
  ll cur = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    cur += a;
    p[i] = Point(i+1, cur);
  }
  std::cout << (ll)closest_pair(p).d2 << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
