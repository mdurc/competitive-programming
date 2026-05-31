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

// https://cses.fi/problemset/task/2193
int main() {
  int n;
  std::cin >> n;
  std::vector<Pt> p(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i];


  long long area2 = 0;
  for (int i = 2; i < n; ++i) {
    area2 += p[0].triangle(p[i], p[i-1]);
  }
  area2 = std::abs(area2);

  long long boundary = 0;
  for (int i = 0; i < n; ++i) {
    int j = (i+1) % n;
    Pt diff = p[j] - p[i];
    int g = std::gcd(diff.x, diff.y);
    boundary += g;
  }

  // picks theorem: area = interior + boundary/2 - 1
  // interior = area - boundary/2 + 1
  long long interior = (area2 - boundary + 2) / 2;
  std::cout << interior << "\n" << boundary << "\n";
}
