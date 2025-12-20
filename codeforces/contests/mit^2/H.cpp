#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
struct Point {
  ll x, y, r;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<Point> p(n);

  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
    p[i].r = p[i].x * p[i].x + p[i].y * p[i].y;
  }

  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int a,int b){ return p[a].r < p[b].r; });

  vector<int> parent(n, -1);
  vector<vector<int>> child(n);
  for (int ii = 0; ii < n; ii++) {
    int i = idx[ii];
    ll best_r = LLONG_MAX;
    int best_j = -1;
    for (int jj = 0; jj < ii; jj++) {
      int j = idx[jj];
      ll dx = p[i].x - p[j].x;
      ll dy = p[i].y - p[j].y;
      __int128 d = (__int128)dx * dx + (__int128)dy * dy;
      if (d <= p[j].r) {
        if (p[j].r < best_r) {
          best_r = p[j].r;
          best_j = j;
        }
      }
    }
    parent[i] = best_j;
    if (best_j != -1) child[best_j].push_back(i);
  }

  vector<ll> dp0(n), dp1(n);
  for (int ii = n - 1; ii >= 0; ii--) {
    int u = idx[ii];
    ll ways0 = 1, ways1 = 1;
    for (int v : child[u]) {
      ways1 = (ways1 * dp0[v]) % MOD;
      ways0 = (ways0 * ((dp0[v] + dp1[v]) % MOD)) % MOD;
    }
    dp0[u] = ways0;
    dp1[u] = ways1;
  }

  ll ans = 1;
  for (int i = 0; i < n; i++) {
    if (parent[i] == -1) {
      ans = ans * ((dp0[i] + dp1[i]) % MOD) % MOD;
    }
  }
  ans = (ans - 1 + MOD) % MOD; // remove empty set
  cout << ans << "\n";
  return 0;
}
