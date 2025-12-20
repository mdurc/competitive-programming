#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define print(p) cout << "{" << p.first << "," << p.second << "}";

int n, h, w;
const int mxn = 1e5+1, mxlog = 31;
int up[mxn][mxlog];

pi get(int val) { return make_pair(val/w, val%w); }
int get(int x, int y) { return x*w+y; } // 1-based coordinates

bool invalid(int val) {
  const auto& [x, y] = get(val);
  return x < 1 || x > h || y < 1 || y > w;
}

void binary_lift() {
  for (int j = 1; j < mxlog; j++) {
    for (int i = 1; i <= n; i++) {
      up[i][j] = up[up[i][j - 1]][j - 1];
    }
  }
}

int kth_ancestor(int a, int k) {
  for (int i = 0; i < mxlog; i++) {
    if ((1 << i) & k) {
      a = up[a][i];
      if (invalid(a)) break; // stay outside
    }
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> h >> w >> q;

  vector<string> g(h);
  for (int i = 0; i < h; ++i) {
    cin >> g[i];
  }

  h += 2;
  w += 2;
  n = h*w;
  vector<int> nxt(n);
  for (int x = 0; x < h; ++x) {
    for (int y = 0; y < w; ++y) {
      if (x == 0 || x == h-1 || y == 0 || y == w-1) {
        nxt[get(x,y)] = get(x,y);
        continue;
      }
      int nx = x, ny = y;
      char c = g[x-1][y-1];
      if (c == 'U') nx--;
      else if (c == 'D') nx++;
      else if (c == 'L') ny--;
      else if (c == 'R') ny++;
      nxt[get(x,y)] = get(nx,ny);
    }
  }

  for (int i = 0; i < n; ++i) up[i][0] = nxt[i];
  binary_lift();

  while (q--) {
    int x, y, t;
    cin >> x >> y >> t;
    const auto& [tx, ty] = get(kth_ancestor(x*w+y, t));
    cout << tx << " " << ty << "\n";
  }
}
