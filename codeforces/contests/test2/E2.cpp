#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 2;
struct matrix_t {
  ll x[N + 1][N + 1]; // 1-based matrix
  matrix_t(int v = 0) {
    memset(x, 0, sizeof(x));
    if (v != 0) {
      for (int i = 1; i <= N; ++i) x[i][i] = v % MOD;
    }
  }
  matrix_t operator*(const matrix_t& r) const {
    matrix_t p;
    for (int k = 1; k <= N; ++k) {
      for (int i = 1; i <= N; ++i) {
        if (x[i][k] == 0) continue;
        for (int j = 1; j <= N; ++j) {
          p.x[i][j] = (p.x[i][j] + 1LL * x[i][k] * r.x[k][j]) % MOD;
        }
      }
    }
    return p;
  }
  matrix_t power(ll p) const {
    matrix_t r(1);
    matrix_t a = *this;
    while (p) {
      if (p & 1) r = r * a;
      a = a * a;
      p >>= 1;
    }
    return r;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll p, q, n;
  cin >> p >> q >> n;

  if (n == 0) {
    cout << 2 << "\n";
    return 0;
  }
  if (n == 1) {
    cout << p << "\n";
    return 0;
  }

  // f0 = 2, f1 = p, fn = p*f(n-1) - q*f(n-2)
  matrix_t m;
  m.x[1][1] = p;
  m.x[1][2] = (-q + MOD) % MOD;
  m.x[2][1] = 1;
  m.x[2][2] = 0;

  matrix_t res = m.power(n-1);
  cout << ((res.x[1][1] * p) % MOD + (res.x[1][2] * 2) % MOD) % MOD << "\n";

  return 0;
}
