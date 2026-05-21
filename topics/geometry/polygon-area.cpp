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

// https://cses.fi/problemset/task/2191
int main() {
  int n;
  std::cin >> n;
  std::vector<Pt> p(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i];

  // pick p1 as the origin and compute cross to sum all triangles that come from it
  // (skip directly adjacent points to origin point)
  long long res = 0;
  for (int i = 2; i < n; ++i) {
    // The question is asking for 2x area, so we don't need to divide by 2.
    res += p[0].triangle(p[i], p[i-1]);

    // If we have a concave polygon, we rely on the sign of product to cancel out any area
    //  we included that is in dead space.
  }
  std::cout << std::abs(res) << "\n";

  // This concept of including then excluding/cancelling out regions of area means
  //  that we can actually pick an arbitrary point outside of polygon as the origin.
  // This will work because we will perform clockwise cross products until the very end
  //  when we compute the bottom edges that are counter-clockwise, cancelling out the area
  //  that was initially included that exists outside of the polygon between the nail/origin
  //  and the polygon
}
